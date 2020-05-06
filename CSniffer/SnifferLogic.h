#ifndef SNIFFERLOGIC_H
#define SNIFFERLOGIC_H
#include "snifferlogicbase.h"
#include <winsock2.h>
//Включаем ws2_32.lib для использования функций WinSock2
#pragma comment(lib, "ws2_32.lib")
//Включаем netapi32.lib для использования функций NetApi
#pragma comment(lib, "netapi32.lib")
#include "HostLogic.h"

class SnifferLogic : public SnifferLogicBase
{
public:
    SnifferLogic();

    void ConfigureHost(int port) override;
    void ConfigureSocket() override;
    void StartSniff() override;
    QString PackageToString(Package package) override;

private:
    int SIO_RCVALL = 0x98000001;
    SOCKET raw_socket;
    SOCKADDR_IN socket_addr;
    HostLogicBase *_host_logic;
};

#endif // SNIFFERLOGIC_H
