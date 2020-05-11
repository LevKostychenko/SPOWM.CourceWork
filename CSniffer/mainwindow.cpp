#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    SetUpDDLItems();
    SetUpHostName();
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
}

void MainWindow::SetUpHostName()
{
    ui->hostNameLabel->setText(this->_hostLogic->GetHostName());
}

void MainWindow::on_startButton_clicked()
{
    if (!this->is_manager_thread_created)
    {
        QString binding_ip = ui->ipBox->currentText();
        this->_sniffManager = new SniffManager(binding_ip);
        this->_managerThread = new QThread();
        this->_sniffManager->moveToThread(this->_managerThread);

        connect(this->_managerThread, SIGNAL(started()), this->_sniffManager, SLOT(start_sniff()));
        connect(this->_sniffManager, SIGNAL(package_append()), this, SLOT(on_package_added()));

        this->is_manager_thread_created = true;
        this->_managerThread->start();
        this->is_window_configured = true;
    }
}

void MainWindow::on_stopButton_clicked()
{
    this->_managerThread->terminate();
}

void MainWindow::on_package_added()
{ 
    Package package = this->_sniffManager->GetLastAddedPackage();   

    PackageBlock* package_block = new PackageBlock(ui, this->scroll_widg, package);
    this->scroll_layout ->addWidget(package_block);
    ui->scrollArea->setWidget(this->scroll_widg);
}

void MainWindow::terminate_manager_thread()
{
    this->_managerThread->terminate();
}

void MainWindow::on_ipBox_currentTextChanged(const QString &arg1)
{
    if (this->is_window_configured)
    {
        this->_managerThread->terminate();
        this->_sniffManager->SetNewIp(arg1);
    }
}
