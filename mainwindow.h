#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent *event);
private slots:
    int OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason);
    void on_pushButton_clicked();

    void closing();

public:
    Ui::MainWindow *ui;
private:
    QSystemTrayIcon *systemTray;
    QAction *minimumAct,*maximumAct,*restoreAct,*quitAct;
    QMenu *pContextMenu;

    int count;
};
#endif // MAINWINDOW_H
