#include "mainwindow.h"
#include <QApplication>
#include "SnifferException.h"
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int code;

    w.show();
    code = a.exec();

    return code;
}
