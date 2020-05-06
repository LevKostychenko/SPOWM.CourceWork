#ifndef SNIFFERLOGICBASE_H
#define SNIFFERLOGICBASE_H
#include "Package.h"

class SnifferLogicBase
{
public:
    SnifferLogicBase();

    virtual void ConfigureHost(int port) = 0;
    virtual void ConfigureSocket() = 0;
    virtual void StartSniff() = 0;
    virtual QString PackageToString(Package package) = 0;
};

#endif // SNIFFERLOGICBASE_H
