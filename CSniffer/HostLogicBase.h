#ifndef HOSTLOGICBASE_H
#define HOSTLOGICBASE_H
#include <winsock2.h>

class HostLogicBase
{
public:
    HostLogicBase();
    virtual CHAR* GetHostName();
    virtual HOSTENT* GetHostByName(CHAR* host_name);
};

#endif // HOSTLOGICBASE_H
