#include "PackageBlock.h"
#include "ui_packageblock.h"

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
