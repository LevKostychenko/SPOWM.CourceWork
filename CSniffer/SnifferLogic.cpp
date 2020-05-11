#include "SnifferLogic.h"
#include "mstcpip.h"
#include<QDebug>

SnifferLogic::SnifferLogic()
{
    this->_host_logic = new HostLogic();
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    this->raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
}

SnifferLogic::~SnifferLogic()
{
    closesocket(this->raw_socket);
    WSACleanup();
}

void SnifferLogic::ConfigureSocket(QString binding_ip)
{
    int status;
    ZeroMemory(&this->socket_addr, sizeof(this->socket_addr));

    this->socket_addr.sin_family = AF_INET;
    this->socket_addr.sin_addr.s_addr = inet_addr(binding_ip.toStdString().c_str());;

    status = bind(this->raw_socket, (SOCKADDR*)&this->socket_addr, sizeof(SOCKADDR));

    if (status < 0)
    {
        throw new SnifferException("Cannot bind raw socket.  Try to open app with administrator permitions.");
    }

    DWORD flag = TRUE;
    status = ioctlsocket(this->raw_socket, SIO_RCVALL, &flag);

    if (status < 0)
    {
        throw new SnifferException("Cannot switch to promiscuous mode. Try to open app with administrator permitions");
    }
}

IPHeader* SnifferLogic::StartSniff()
{
    IPHeader *ip_header;
    CHAR btBuffer[65536];
    int count = 0;

    count = recv(this->raw_socket, btBuffer, sizeof(btBuffer), 0);

    int valid_size = sizeof(IPHeader);
    if (count >= valid_size)
    {
        ip_header = (IPHeader*)btBuffer;
        WORD size = (ip_header->ver_len << 8) + (ip_header->ver_len >> 8);

        if (size >= 60)
        {
            return ip_header;
        }
    }
    else
    {
        return 0;
    }
}

Package SnifferLogic::ParseIPHeader(IPHeader* ip_header)
{
    Package package;

    if (ip_header != NULL)
    {
        IN_ADDR dest_ia;
        IN_ADDR source_ia;
        dest_ia.s_addr = ip_header->dest;
        CHAR *dest_ip = inet_ntoa(dest_ia);
        package.DestinationIp = QString(dest_ip);
        source_ia.s_addr = ip_header->src;
        CHAR *src_ip = inet_ntoa(source_ia);        
        package.SourceIp = QString(src_ip);

        package.Protocol = GetProtocol(ip_header->protocol);
        package.Id = ip_header->id;
        package.RequestSize = ip_header->length;

        QList<QString> local_ips = _host_logic->GetHostIp(_host_logic->GetHostByName(_host_logic->GetHostName()));

        package.IsForThisHost = local_ips.contains(package.DestinationIp);
        package.IsFromThisHost = local_ips.contains(package.SourceIp);
        package.StringProtocol = this->ProtocolToString(package.Protocol);
    }

    return package;
}

QString SnifferLogic::PackageToString(Package package)
{
    return QString(
                "SRC IP: " + package.SourceIp +
                " DEST IP: " + package.DestinationIp +
                " ID: " + package.Id +
                " PROTOCOL: " + ProtocolToString(package.Protocol) +
                " SIZE: " + QString::number(package.RequestSize));
}

ProtocolEnum SnifferLogic::GetProtocol(unsigned char protocol)
{
    switch (protocol)
    {
        case IPPROTO_ICMP :
        {
            return ProtocolEnum::ICMP;
        }
        case IPPROTO_IGMP :
        {
            return ProtocolEnum::IGMP;
        }
        case IPPROTO_GGP :
        {
            return ProtocolEnum::GGP;
        }
        case IPPROTO_PUP :
        {
            return ProtocolEnum::PUP;
        }
        case IPPROTO_TCP :
        {
            return ProtocolEnum::TCP;
        }
        case IPPROTO_UDP :
        {
            return ProtocolEnum::UDP;
        }
        case IPPROTO_IPV6 :
        {
            return ProtocolEnum::IPV6;
        }
        case IPPROTO_ND :
        {
            return ProtocolEnum::ND;
        }
    }

    return ProtocolEnum::UNDEF;
}

QString SnifferLogic::ProtocolToString(ProtocolEnum protocol)
{
    switch (protocol)
    {
        case ProtocolEnum::ICMP :
        {
            return "ICMP";
        }
        case ProtocolEnum::IGMP :
        {
            return "IGMP";
        }
        case ProtocolEnum::GGP:
        {
            return "GGP";
        }
        case ProtocolEnum::PUP :
        {
            return "PUP";
        }
        case ProtocolEnum::TCP :
        {
            return "TCP";
        }
        case ProtocolEnum::UDP :
        {
            return "UDP";
        }
        case ProtocolEnum::IPV6 :
        {
            return "IPV6";
        }
        case ProtocolEnum::ND:
        {
            return "ND";
        }
        case ProtocolEnum::UNDEF:
        {
            return "UDEFINED";
        }
    }
}
