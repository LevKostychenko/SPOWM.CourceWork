#ifndef HOSTLOGICBASE_H
#define HOSTLOGICBASE_H
#include <winsock2.h>
#include <QString>

class HostLogicBase
{
public:
    HostLogicBase();
    virtual CHAR* GetHostName() = 0;
    virtual HOSTENT* GetHostByName(CHAR* host_name) = 0;
    virtual QList<QString> GetHostIp(HOSTENT* host) = 0;
};

#endif // HOSTLOGICBASE_H
