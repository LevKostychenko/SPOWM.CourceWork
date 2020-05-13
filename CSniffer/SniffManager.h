#ifndef SNIFFMANAGER_H
#define SNIFFMANAGER_H
#include <QObject>
#include "SnifferLogic.h"

class SniffManager : public QObject
{
    Q_OBJECT

public:
    SniffManager(QString ip);
    Package GetLastAddedPackage();
    void ResetPackages();
    void SetNewIp(QString ip);

private:
    SnifferLogicBase* _snifferLogic;
    QString _ip;
    QList<Package>* _current_packages;
    bool isContinueSniff;

public slots:
    void start_sniff();
    void stop_sniff();

signals:
    void package_append();
    void close_sniffer();
    void error_occured(SnifferException* exception);
};

#endif // SNIFFMANAGER_H
