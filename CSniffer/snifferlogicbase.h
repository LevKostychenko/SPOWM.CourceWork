#ifndef SNIFFERLOGICBASE_H
#define SNIFFERLOGICBASE_H
#include "Package.h"
#include "IPHeader.h"
#include "TCPHeader.h"
#include "UDPHeader.h"

class SnifferLogicBase
{
public:
    SnifferLogicBase();
    virtual ~SnifferLogicBase();

    virtual void ConfigureSocket(QString binding_ip) = 0;
    virtual Package StartSniff() = 0;
    virtual QString PackageToString(Package package) = 0;
};

#endif // SNIFFERLOGICBASE_H
