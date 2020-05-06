#include "SnifferLogic.h"

SnifferLogic::SnifferLogic()
{
    this->_host_logic = new HostLogic();
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    this->raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
}

void SnifferLogic::ConfigureHost(int port = 3000)
{

}

void SnifferLogic::ConfigureSocket()
{
    CHAR* host_name = this->_host_logic->GetHostName();
    HOSTENT* host = this->_host_logic->GetHostByName(host_name);
    ZeroMemory(&this->socket_addr, sizeof(this->socket_addr));

    this->socket_addr.sin_family = AF_INET;
    this->socket_addr.sin_addr.s_addr = ((struct in_addr*)host->h_addr_list[0])->s_addr;

    bind(this->raw_socket, (SOCKADDR*)&this->socket_addr, sizeof(SOCKADDR));
    DWORD flag = TRUE;
    ioctlsocket(this->raw_socket, SIO_RCVALL, &flag);
}
