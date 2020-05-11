#ifndef SNIFFERLOGICBASE_H
#define SNIFFERLOGICBASE_H
#include "Package.h"
#include "IPHeader.h"

class SnifferLogicBase
{
public:
    SnifferLogicBase();
    virtual ~SnifferLogicBase();

    virtual void ConfigureSocket(QString binding_ip) = 0;
    virtual IPHeader* StartSniff() = 0;
    virtual QString PackageToString(Package package) = 0;
    virtual Package ParseIPHeader(IPHeader* ip_header) = 0;
};

#endif // SNIFFERLOGICBASE_H
