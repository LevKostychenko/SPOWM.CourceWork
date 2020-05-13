#ifndef PACKAGE_H
#define PACKAGE_H
#include <QString>
#include "ProtocolEnum.h"
#include "HttpMethodEnum.h"

class Package
{
public:
    int Id;
    QString DestinationIp;
    QString SourceIp;
    ProtocolEnum Protocol;
    HttpMethodEnum HttpMethod;
    QString Version;
    int RequestSize;
    QString PayloadHexData;
    QString PayloadASCIIData;
    bool IsForThisHost;
    bool IsFromThisHost;
    bool IsBodyCoded;
    QString StringProtocol;
};

#endif // PACKAGE_H
