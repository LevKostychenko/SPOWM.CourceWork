/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCler;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *ipBox;
    QSpacerItem *verticalSpacer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *hostNameLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *protocolSearch;
    QComboBox *srcIpSearch;
    QComboBox *destinationIpSearch;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *infoLayout;
    QLabel *infoLabel;
    QVBoxLayout *dataLayout;
    QLabel *dataLabel;
    QMenuBar *menubar;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(789, 534);
        MainWindow->setMaximumSize(QSize(1100, 600));
        actionCler = new QAction(MainWindow);
        actionCler->setObjectName(QString::fromUtf8("actionCler"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Asus/Downloads/icons8-\320\274\320\265\321\202\320\273\320\260-40.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCler->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Swis721 Cn BT"));
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        ipBox = new QComboBox(centralwidget);
        ipBox->setObjectName(QString::fromUtf8("ipBox"));

        verticalLayout_2->addWidget(ipBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("background-color: #b4f5a6;\n"
"border-radius: 5px;\n"
"border: none; \n"
"min-height: 40px;"));

        verticalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setFont(font);
        stopButton->setStyleSheet(QString::fromUtf8("background-color: #fa6052;\n"
"border: none; \n"
"outline: none;\n"
"border-radius: 5px;\n"
"min-height: 40px;\n"
"margin-bottom: 20px;"));

        verticalLayout_2->addWidget(stopButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        hostNameLabel = new QLabel(centralwidget);
        hostNameLabel->setObjectName(QString::fromUtf8("hostNameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Swis721 Cn BT"));
        font1.setPointSize(9);
        hostNameLabel->setFont(font1);

        horizontalLayout_5->addWidget(hostNameLabel);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        protocolSearch = new QComboBox(centralwidget);
        protocolSearch->setObjectName(QString::fromUtf8("protocolSearch"));

        horizontalLayout_6->addWidget(protocolSearch);

        srcIpSearch = new QComboBox(centralwidget);
        srcIpSearch->setObjectName(QString::fromUtf8("srcIpSearch"));

        horizontalLayout_6->addWidget(srcIpSearch);

        destinationIpSearch = new QComboBox(centralwidget);
        destinationIpSearch->setObjectName(QString::fromUtf8("destinationIpSearch"));

        horizontalLayout_6->addWidget(destinationIpSearch);


        verticalLayout_3->addLayout(horizontalLayout_6);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 642, 345));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        infoLayout = new QVBoxLayout();
        infoLayout->setObjectName(QString::fromUtf8("infoLayout"));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Swis721 Cn BT"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        infoLabel->setFont(font2);
        infoLabel->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        infoLayout->addWidget(infoLabel);


        horizontalLayout->addLayout(infoLayout);

        dataLayout = new QVBoxLayout();
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));
        dataLabel = new QLabel(centralwidget);
        dataLabel->setObjectName(QString::fromUtf8("dataLabel"));
        dataLabel->setFont(font2);
        dataLabel->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
""));

        dataLayout->addWidget(dataLabel);


        horizontalLayout->addLayout(dataLayout);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 789, 26));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTools->menuAction());
        menuTools->addAction(actionCler);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCler->setText(QCoreApplication::translate("MainWindow", "Cler", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose IP to bind", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start sniff", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop sniff", nullptr));
        hostNameLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "  PROTOCOL", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "SOURCE IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "DESTINATION IP", nullptr));
        infoLabel->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        dataLabel->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
