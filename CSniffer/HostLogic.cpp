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
        throw new QException();
    }

    return host_name;
}

HOSTENT* HostLogic::GetHostByName(CHAR* host_name)
{
    HOSTENT *phe = gethostbyname(host_name);

    if (!phe)
    {
        throw new QException();
    }

    return phe;
}
