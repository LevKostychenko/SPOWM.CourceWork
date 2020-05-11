/********************************************************************************
** Form generated from reading UI file 'packageblock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGEBLOCK_H
#define UI_PACKAGEBLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageBlock
{
public:

    void setupUi(QWidget *PackageBlock)
    {
        if (PackageBlock->objectName().isEmpty())
            PackageBlock->setObjectName(QString::fromUtf8("PackageBlock"));
        PackageBlock->resize(468, 50);

        retranslateUi(PackageBlock);

        QMetaObject::connectSlotsByName(PackageBlock);
    } // setupUi

    void retranslateUi(QWidget *PackageBlock)
    {
        PackageBlock->setWindowTitle(QCoreApplication::translate("PackageBlock", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageBlock: public Ui_PackageBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEBLOCK_H
