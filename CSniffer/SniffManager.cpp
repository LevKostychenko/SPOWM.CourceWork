#include "SniffManager.h"

SniffManager::SniffManager(QString ip)
{
    this->_snifferLogic = new SnifferLogic();
    this->_ip = ip;
    this->_current_packages = new QList<Package>;
}

void SniffManager::start_sniff()
{
    _snifferLogic->ConfigureSocket(this->_ip);
    bool isContinue = true;

    while (isContinue)
    {
        Package package = this->_snifferLogic->ParseIPHeader(this->_snifferLogic->StartSniff());

        for (auto it : *this->_current_packages)
        {
            if (it.Id == package.Id)
            {
                continue;
            }
        }

        this->_current_packages->append(package);
        emit this->package_append();
    }
}

void SniffManager::SetNewIp(QString ip)
{
    this->_ip = ip;
}

void SniffManager::stop_sniff()
{
    emit this->close_sniffer();
}

Package SniffManager::GetLastAddedPackage()
{
    if (this->_current_packages != NULL && !this->_current_packages->isEmpty())
    {
        return this->_current_packages->last();
    }

    throw new SnifferException("No sniffed packages.");
}
