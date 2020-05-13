#include "PackageBlock.h"
#include "ui_packageblock.h"
#include <QMouseEvent>
#include <QTextBlock>

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
        auto old_info_layout = this->_uiMainWindow->infoWidget->layout();
        auto old_hex_layout = this->_uiMainWindow->hexWidget->layout();
        auto old_ascii_layout = this->_uiMainWindow->asciiWidget->layout();

        if (old_info_layout != nullptr)
        {
            qDeleteAll(this->_uiMainWindow->infoWidget->findChildren<QLabel *>());
            qDeleteAll(this->_uiMainWindow->infoWidget->findChildren<QVBoxLayout*>());
        }

        if (old_hex_layout != nullptr)
        {
            qDeleteAll(this->_uiMainWindow->hexWidget->findChildren<QLabel *>());
            qDeleteAll(this->_uiMainWindow->hexWidget->findChildren<QVBoxLayout*>());
        }

        if (old_ascii_layout != nullptr)
        {
            qDeleteAll(this->_uiMainWindow->asciiWidget->findChildren<QLabel *>());
            qDeleteAll(this->_uiMainWindow->asciiWidget->findChildren<QVBoxLayout*>());
        }

        QVBoxLayout* new_info_layout = new QVBoxLayout(this->_uiMainWindow->infoWidget);
        QLabel* hex_text = new QLabel(this->_package.PayloadHexData);
        hex_text->setWordWrap(true);
        QLabel* ascii_text = new QLabel(this->_package.PayloadASCIIData);
        ascii_text->setWordWrap(true);

        auto ascii_layout = new QVBoxLayout(this->_uiMainWindow->asciiWidget);
        auto hex_layout = new QVBoxLayout(this->_uiMainWindow->hexWidget);

        ascii_layout->addWidget(ascii_text);
        hex_layout->addWidget(hex_text);

        QLabel* prot_lab = new QLabel("Protocol: " + this->_package.StringProtocol);
        QLabel* src_ip_lab = new QLabel("Src IP: " + this->_package.SourceIp);
        QLabel* dst_ip_lab = new QLabel("Destination IP: " + this->_package.DestinationIp);
        QLabel* size_lab = new QLabel("Size (Bytes): " + QString::number(this->_package.RequestSize));

        QString is_for_this_host_str = this->_package.IsForThisHost ? "true" : "false";
        QLabel* is_for_this_host_lab = new QLabel("Is for this host: " + is_for_this_host_str);
        QString is_from_this_host_str = this->_package.IsFromThisHost ? "true" : "false";
        QLabel* is_from_this_host_lab = new QLabel("Is from this host: " + is_from_this_host_str);

        new_info_layout->addWidget(prot_lab);
        new_info_layout->addWidget(src_ip_lab);
        new_info_layout->addWidget(dst_ip_lab);
        new_info_layout->addWidget(size_lab);
        new_info_layout->addWidget(is_for_this_host_lab);
        new_info_layout->addWidget(is_from_this_host_lab);

        this->_uiMainWindow->hexWidget->setLayout(hex_layout);
        this->_uiMainWindow->asciiWidget->setLayout(ascii_layout);
        this->_uiMainWindow->infoWidget->setLayout(new_info_layout);
    }
}

