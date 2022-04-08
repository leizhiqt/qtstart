#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QString>
#include <QByteArray>
#include <QDebug>

#include "Start.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),count(10)
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

    quitAct = new QAction(QStringLiteral("Exit"),this);
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    // 关联托盘事件
    connect(systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));

    pContextMenu = new QMenu(this);
    pContextMenu->addAction(minimumAct);
    pContextMenu->addAction(maximumAct);
    pContextMenu->addAction(restoreAct);
    pContextMenu->addSeparator();
    pContextMenu->addAction(quitAct);

    systemTray->setContextMenu(pContextMenu);
    pContextMenu->show();



    //connect(ui->pushButton, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
     //   this, SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));


    ui->pushButton->setText("OK");
    ui->pushButton->setStyleSheet("color:red");

    QPalette pal = ui->pushButton->palette();
    pal.setColor(QPalette::ButtonText, Qt::black);    //设置按钮上的字体颜色，理论上可以，实际上就是可以
    pal.setColor(QPalette::Button, Qt::white);      //设置按钮背景颜色，理论上可以，实际上不可以
    ui->pushButton->setPalette(pal);

    QFont boldFont = ui->pushButton->font();
    boldFont.setBold(true);//字体加粗
    boldFont.setPointSize(24);//字体加粗
    ui->pushButton->setFont(boldFont);//设置字体加粗
    ui->pushButton->setDefault(true);//设置字体加粗

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


void MainWindow::on_pushButton_clicked()
{
    qDebug("pushButtonConnect");
    client->takeShow();
}

void MainWindow::closing()
{
    qDebug("pushButtonConnect");
    destroy();
}
