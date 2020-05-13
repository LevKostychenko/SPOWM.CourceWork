#ifndef SNIFFERLOGIC_H
#define SNIFFERLOGIC_H
#include "snifferlogicbase.h"
#include <winsock2.h>
//Включаем ws2_32.lib для использования функций WinSock2
#pragma comment(lib, "ws2_32.lib")
//Включаем netapi32.lib для использования функций NetApi
#pragma comment(lib, "netapi32.lib")
#include "HostLogic.h"
#include "SnifferException.h"

class SnifferLogic : public SnifferLogicBase
{
public:
    SnifferLogic();
    ~SnifferLogic();

    void ConfigureSocket(QString binding_ip) override;
    Package StartSniff() override;
    QString PackageToString(Package package) override;

private:
    SOCKET raw_socket;
    SOCKADDR_IN socket_addr;
    HostLogicBase* _host_logic;
    ProtocolEnum GetProtocol(unsigned char protocol);
    QString ProtocolToString(ProtocolEnum protocol);
    Package ParceTCPHeader(char* buffer, IPHeader* ip_header, int size);
    Package ParceUDPHeader(char* buffer, IPHeader* ip_header, int size);
    void GetData(char* data, int size, Package* package);
};

#endif // SNIFFERLOGIC_H
