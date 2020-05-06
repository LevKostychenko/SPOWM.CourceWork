#ifndef HOSTLOGIC_H
#define HOSTLOGIC_H
#include "HostLogicBase.h"
#include <qexception.h>

class HostLogic : public HostLogicBase
{
public:
    HostLogic();

    CHAR* GetHostName() override;
    HOSTENT* GetHostByName(CHAR* host_name) override;
};

#endif // HOSTLOGIC_H
