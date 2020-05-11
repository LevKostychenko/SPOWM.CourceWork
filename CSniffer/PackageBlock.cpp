#include "PackageBlock.h"
#include "ui_packageblock.h"
#include <QMouseEvent>

PackageBlock::PackageBlock(Ui::MainWindow* uiMainWindow, QWidget* parent, Package package) :
    QWidget(parent),
    ui(new Ui::PackageBlock),
    _uiMainWindow(uiMainWindow),
    _package(package)
{
    ui->setupUi(this);
    QFont default_font("Swis721 Cn BT", 9, QFont::Serif);

    QLabel* protocol_label = new QLabel(this->_package.StringProtocol);
    QLabel* src_ip_label = new QLabel(this->_package.SourceIp);
    QLabel* dst_ip_label = new QLabel(this->_package.DestinationIp);

    QHBoxLayout* h_box_layout = new QHBoxLayout();
    h_box_layout->addWidget(protocol_label);
    h_box_layout->addWidget(src_ip_label);
    h_box_layout->addWidget(dst_ip_label);

    this->setLayout(h_box_layout);
}

PackageBlock::~PackageBlock()
{
    delete ui;
}

void PackageBlock::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->_uiMainWindow->infoLayout = new QVBoxLayout();
        QLabel* info_label = new QLabel("Info");
        QFont default_font("Swis721 Cn BT", 9, QFont::Bold);
        info_label->setFont(default_font);

        //this->_uiMainWindow->infoLayout->addWidget(info_label);

        QLabel* prot_lab = new QLabel("Protocol: " + this->_package.StringProtocol);
        QLabel* src_ip_lab = new QLabel("Src IP: " + this->_package.SourceIp);
        QLabel* dst_ip_lab = new QLabel("Destination IP: " + this->_package.DestinationIp);
        QLabel* size_lab = new QLabel("Seze (Bytes): " + QString::number(this->_package.RequestSize));

        QString is_for_this_host_str = this->_package.IsForThisHost ? "true" : "false";
        QLabel* is_for_this_host_lab = new QLabel("Is for this host: " + is_for_this_host_str);
        QString is_from_this_host_str = this->_package.IsFromThisHost ? "true" : "false";
        QLabel* is_from_this_host_lab = new QLabel("Is from this host: " + is_from_this_host_str);

        this->_uiMainWindow->infoLayout->addWidget(prot_lab);
        this->_uiMainWindow->infoLayout->addWidget(src_ip_lab);
        this->_uiMainWindow->infoLayout->addWidget(dst_ip_lab);
        this->_uiMainWindow->infoLayout->addWidget(size_lab);
        this->_uiMainWindow->infoLayout->addWidget(is_for_this_host_lab);
        this->_uiMainWindow->infoLayout->addWidget(is_from_this_host_lab);
    }
}

