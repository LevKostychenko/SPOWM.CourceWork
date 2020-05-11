#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->_snifferLogic = new SnifferLogic();
    this->_hostLogic = new HostLogic();
    this->is_manager_thread_created = false;
    this->is_window_configured = false;

    this->scroll_widg = new QWidget();
    this->scroll_layout = new QVBoxLayout(this->scroll_widg);
    ui->scrollArea->setWidget(this->scroll_widg);

    _existing_dest_ips = QList<QString>();
    _existing_src_ips = QList<QString>();
    _existing_packages = QList<Package>();

    this->current_dst_search_val = "All";
    this->current_src_search_val = "All";
    this->current_protocol_search_val = "All";

    SetUpDDLItems();
    SetUpHostName();

    QString binding_ip = ui->ipBox->currentText();
    this->_sniffManager = new SniffManager(binding_ip);

    this->is_window_configured = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUpDDLItems()
{
    HOSTENT* hst = this->_hostLogic->GetHostByName(this->_hostLogic->GetHostName());

    for (int i = 0; hst->h_addr_list[i] != NULL; i++)
    {
        in_addr *addr_list;
        addr_list = (in_addr*)hst->h_addr_list[i];
        QString ip_string = inet_ntoa(*addr_list);

        if (!ip_string.isNull() && !ip_string.isEmpty())
        {
            ui->ipBox->addItem(ip_string);
        }
    }

    ui->protocolSearch->addItem("All");
    ui->protocolSearch->addItem("TCP");
    ui->protocolSearch->addItem("UDP");
    ui->protocolSearch->addItem("ICMP");
    ui->protocolSearch->addItem("IGMP");
    ui->protocolSearch->addItem("GGP");
    ui->protocolSearch->addItem("IPV6");
    ui->protocolSearch->addItem("ND");
    ui->protocolSearch->addItem("UNDEFINED");

    ui->srcIpSearch->addItem("All");
    ui->destinationIpSearch->addItem("All");
}

void MainWindow::SetUpHostName()
{
    ui->hostNameLabel->setText(this->_hostLogic->GetHostName());
}

void MainWindow::on_startButton_clicked()
{
    QString binding_ip = ui->ipBox->currentText();
    this->_sniffManager = new SniffManager(binding_ip);
    this->_managerThread = new QThread();
    this->_sniffManager->moveToThread(this->_managerThread);

    connect(this->_managerThread, SIGNAL(started()), this->_sniffManager, SLOT(start_sniff()));
    connect(this->_sniffManager, SIGNAL(package_append()), this, SLOT(on_package_added()));

    this->is_manager_thread_created = true;
    this->_managerThread->start();
}

void MainWindow::on_stopButton_clicked()
{
    this->_sniffManager->stop_sniff();
}

void MainWindow::on_package_added()
{ 
    Package package = this->_sniffManager->GetLastAddedPackage();   

    if(IsPackageSuitableForApplyingFilters(package))
    {
        PackageBlock* package_block = new PackageBlock(ui, this->scroll_widg, package);
        this->scroll_layout ->addWidget(package_block);
        ui->scrollArea->setWidget(this->scroll_widg);
        this->_existing_packages.append(package);

        if (!this->_existing_src_ips.contains(package.SourceIp))
        {
            this->_existing_src_ips.append(package.SourceIp);
            ui->srcIpSearch->addItem(package.SourceIp);
        }

        if (!this->_existing_dest_ips.contains(package.DestinationIp))
        {
            this->_existing_dest_ips.append(package.DestinationIp);
            ui->destinationIpSearch->addItem(package.DestinationIp);
        }
    }
}

void MainWindow::on_ipBox_currentTextChanged(const QString &arg1)
{
    if (this->is_window_configured)
    {
        this->_sniffManager->SetNewIp(arg1);
    }
}

void MainWindow::on_actionCler_triggered()
{
    if (is_window_configured)
    {
        QList<PackageBlock*> widgets = this->scroll_widg->findChildren<PackageBlock*>();
        foreach(QWidget * child, widgets)
        {
            delete child;
        }

        ClearSearchDDLs();
        this->_existing_packages.clear();

        this->_sniffManager->ResetPackages();
    }
}

void MainWindow::ClearSearchDDLs()
{
    for (int i = 1; i < this->_existing_src_ips.count(); i++)
    {
        ui->srcIpSearch->removeItem(i);
    }

    for (int i = 1; i < this->_existing_dest_ips.count(); i++)
    {
        ui->destinationIpSearch->removeItem(i);
    }
}

void MainWindow::on_protocolSearch_currentIndexChanged(const QString &arg1)
{
    if (is_window_configured)
    {
        this->current_protocol_search_val = arg1;
        UpplyFilters();
    }
}

void MainWindow::UpplyFilters()
{
    QList<Package> new_list;

    foreach(auto package, this->_existing_packages)
    {
        if(IsPackageSuitableForApplyingFilters(package))
        {
            new_list.append(package);
        }
    }

    this->UpdateScrollArea(new_list);
}

bool MainWindow::IsPackageSuitableForApplyingFilters(Package package)
{
    if (this->current_protocol_search_val == "All" || package.StringProtocol == this->current_protocol_search_val)
    {
        if (this->current_src_search_val == "All" || package.SourceIp == this->current_src_search_val)
        {
            if (this->current_dst_search_val == "All" || package.DestinationIp == this->current_dst_search_val)
            {
                return true;
            }
        }
    }

    return false;
}

void MainWindow::UpdateScrollArea(QList<Package> new_packages)
{
    QList<PackageBlock*> widgets = this->scroll_widg->findChildren<PackageBlock*>();
    foreach(QWidget* child, widgets)
    {
        delete child;
    }

    foreach (auto package, new_packages)
    {
        PackageBlock* package_block = new PackageBlock(ui, this->scroll_widg, package);
        this->scroll_layout ->addWidget(package_block);
        ui->scrollArea->setWidget(this->scroll_widg);
        this->_existing_packages.append(package);
    }
}

void MainWindow::on_srcIpSearch_currentIndexChanged(const QString &arg1)
{
    if (is_window_configured)
    {
        this->current_src_search_val = arg1;
        UpplyFilters();
    }
}

void MainWindow::on_destinationIpSearch_currentIndexChanged(const QString &arg1)
{
    if (is_window_configured)
    {
        this->current_dst_search_val = arg1;
        UpplyFilters();
    }
}
