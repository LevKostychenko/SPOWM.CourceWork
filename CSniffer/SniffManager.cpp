#include "SniffManager.h"

SniffManager::SniffManager(QString ip)
{
    this->_snifferLogic = new SnifferLogic();
    this->_ip = ip;
    this->_current_packages = new QList<Package>;
}

void SniffManager::start_sniff()
{
    try
    {
        _snifferLogic->ConfigureSocket(this->_ip);
        this->isContinueSniff = true;
    }
    catch(SnifferException* ex)
    {
        emit this->error_occured(ex);
        return;
    }

    while (this->isContinueSniff)
    {
        Package package = this->_snifferLogic->StartSniff();

        for (auto it : *this->_current_packages)
        {
            if (it.Id == package.Id)
            {
                continue;
            }
        }

        if (package.Id != 0)
        {
            this->_current_packages->append(package);
            emit this->package_append();
        }
    }
}

void SniffManager::SetNewIp(QString ip)
{
    this->_ip = ip;
}

void SniffManager::stop_sniff()
{
    this->isContinueSniff = false;
}

Package SniffManager::GetLastAddedPackage()
{
    if (this->_current_packages != NULL && !this->_current_packages->isEmpty())
    {
        return this->_current_packages->last();
    }

    throw new SnifferException("No sniffed packages.");
}

void SniffManager::ResetPackages()
{
    if (this->_current_packages != nullptr && !this->_current_packages->isEmpty())
    {
        this->_current_packages->clear();
    }
}
