#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QString>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon icon(":win.ico");
    systemTray = new QSystemTrayIcon(this);
    systemTray->setIcon(icon);
    systemTray->setToolTip("Test Radio Buttons");
    systemTray->show();

    minimumAct = new QAction("Minimum Window", this);

    //Note the differences between hide() and showMinimized().
    connect(minimumAct, SIGNAL(triggered()), this, SLOT(hide()));
    maximumAct = new QAction("Maximum Window", this);
    connect(maximumAct, SIGNAL(triggered()), this, SLOT(showMaximized()));
    restoreAct = new QAction("Restore Window", this);
    connect(restoreAct, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAct = new QAction(QStringLiteral("退出"),this);
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    // 关联托盘事件
    connect(systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));

    pContextMenu = new QMenu(this);
    //pContextMenu->addAction(minimumAct);
    //pContextMenu->addAction(maximumAct);
    //pContextMenu->addAction(restoreAct);
    pContextMenu->addSeparator();
    pContextMenu->addAction(quitAct);

    systemTray->setContextMenu(pContextMenu);
    pContextMenu->show();

    this->update();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(systemTray->isVisible())
    {
        hide();
        systemTray->showMessage("Tips", "The program is running behind!");
        event->ignore();
    }
}

int MainWindow::OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger
        || reason == QSystemTrayIcon::DoubleClick)
    {
        // 显示主窗口
        if(this->isHidden())
            this->showNormal();
        else
            this->hide();
    }
    return 0;
}
