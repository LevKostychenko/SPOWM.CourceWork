#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "SnifferLogic.h"
#include "SniffManager.h"
#include "PackageBlock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_startButton_clicked();
    void on_package_added();
    void on_stopButton_clicked();
    void terminate_manager_thread();

private:
    Ui::MainWindow* ui;
    SnifferLogicBase* _snifferLogic;
    HostLogicBase* _hostLogic;
    void SetUpDDLItems();
    void SetUpHostName();
    SniffManager* _sniffManager;
    QThread* _managerThread;
    bool is_manager_thread_created;
    bool is_window_configured;
    QWidget* scroll_widg;
    QLayout* scroll_layout;

signals:
    void finish_manager_thread();

private slots:
    void on_ipBox_currentTextChanged(const QString &arg1);
};
#endif // MAINWINDOW_H
