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

private:
    Ui::MainWindow* ui;
    SnifferLogicBase* _snifferLogic;
    HostLogicBase* _hostLogic;
    void SetUpDDLItems();
    void SetUpHostName();
    void ClearSearchDDLs();
    void UpdateScrollArea(QList<Package> packages);
    void UpplyFilters();
    bool IsPackageSuitableForApplyingFilters(Package package);
    void ShowMessageWindow(QString message);
    SniffManager* _sniffManager;
    QThread* _managerThread;
    bool is_manager_thread_created;
    bool is_window_configured;
    QWidget* scroll_widg;
    QLayout* scroll_layout;
    QList<QString> _existing_dest_ips;
    QList<QString> _existing_src_ips;
    QList<Package> _existing_packages;
    QString current_dst_search_val;
    QString current_src_search_val;
    QString current_protocol_search_val;

signals:
    void finish_manager_thread();

private slots:
    void on_ipBox_currentTextChanged(const QString &arg1);
    void on_actionCler_triggered();
    void on_protocolSearch_currentIndexChanged(const QString &arg1);
    void on_srcIpSearch_currentIndexChanged(const QString &arg1);
    void on_destinationIpSearch_currentIndexChanged(const QString &arg1);
    void on_error_occured(SnifferException* exception);
};
#endif // MAINWINDOW_H
