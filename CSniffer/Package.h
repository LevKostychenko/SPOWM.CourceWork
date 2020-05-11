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
    QString HttpVersion;
    int RequestSize;
    QString RequestBody;
    bool IsForThisHost;
    bool IsFromThisHost;
    bool IsBodyCoded;
    QString StringProtocol;
};

#endif // PACKAGE_H
