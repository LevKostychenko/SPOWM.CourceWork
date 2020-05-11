#ifndef PACKAGEBLOCK_H
#define PACKAGEBLOCK_H

#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class PackageBlock;
}

class PackageBlock : public QWidget
{
    Q_OBJECT

public:
    explicit PackageBlock(Ui::MainWindow* uiMainWindow = nullptr, QWidget* parent = nullptr, Package package = Package());
    ~PackageBlock();

private:
    Ui::MainWindow* _uiMainWindow;
    Ui::PackageBlock *ui;
    Package _package;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // PACKAGEBLOCK_H
