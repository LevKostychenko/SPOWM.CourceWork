#include "HostLogic.h"

HostLogic::HostLogic()
{

}

CHAR* HostLogic::GetHostName()
{
    CHAR host_name[16];
    gethostname(host_name, sizeof host_name);

    if (!host_name)
    {
        throw new SnifferException("Cannot get host name.");
    }

    return host_name;
}

HOSTENT* HostLogic::GetHostByName(CHAR* host_name)
{
    HOSTENT *phe = gethostbyname(host_name);

    if (!phe)
    {
        throw new SnifferException("Cannot get host.");
    }

    return phe;
}

QList<QString> HostLogic::GetHostIp(HOSTENT* host)
{
    QList<QString> ip_list;

    for(int i = 0; host->h_addr_list[i] != NULL; i++)
    {
        QString ip_buffer = QString(inet_ntoa(*((struct in_addr*)host->h_addr_list[i])));
        if (!ip_buffer.isNull() && !ip_buffer.isEmpty())
        {
            ip_list.append(ip_buffer);
        }
    }

    return ip_list;
}
