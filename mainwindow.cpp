#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QString>
#include <QByteArray>
#include <QDebug>

#include <qpainter.h>

#include "Start.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
#include <libavformat/version.h>
#include <libavutil/time.h>
#include <libavutil/mathematics.h>
}

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
    //connect(minimumAct, SIGNAL(triggered()), this, SLOT(hide()));
    //maximumAct = new QAction("Maximum Window", this);
    //connect(maximumAct, SIGNAL(triggered()), this, SLOT(showMaximized()));
    //restoreAct = new QAction("Restore Window", this);
    //connect(restoreAct, SIGNAL(triggered()), this, SLOT(showNormal()));

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
    //pContextMenu->show();



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

    //m_ffmpeg = new FFmpegUtils;
    //connect(m_ffmpeg, SIGNAL(MyFFmpegSigGetOneFrame(QImage)), this, SLOT(SlotGetOneFrame(QImage)));

    this->update();
    this->show();
    //this->hide();
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


//void MainWindow::on_pushButton_clicked()
//{
//    qDebug("pushButtonConnect");
//    qtStart->client->takeShow();
//}

void MainWindow::closing()
{
    qDebug("pushButtonConnect");
    destroy();
}

//void MainWindow::PlayStart(){
//    this->PlayStop();
//    qDebug("begin");
//    m_playThread = new QThread();
//    m_player = new RTSP_Player(m_ffmpeg);
//    m_player->SetPlayerUrl("rtsp地址");

//    connect(this,SIGNAL(SigPlayStart()),m_player, SLOT(PlayerStart()));

//    m_player->moveToThread(m_playThread);
//    m_playThread->start();
//}

//void MainWindow::PlayStop()
//{
//    if (m_player)
//    {
//        m_player->PlayerStop();
//    }

//    if (m_playThread)
//    {
//        m_playThread->quit();
//        m_playThread->wait(1000);
//        delete m_playThread;
//        m_playThread = nullptr;
//    }

//    if (m_player)
//    {
//        delete m_player;
//        m_player = nullptr;
//    }
//}

void MainWindow::on_pushButton_clicked()
{
//      this->PlayStart();
//      emit SigPlayStart();
}

//void MainWindow::SlotGetOneFrame(QImage img){
//    m_image = img;
//    this->update();
//}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);

//    if (m_image.size().width() <= 0)
//        return;

//    QImage img = m_image.scaled(ui->labVideo->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

//    int x = ui->labVideo->geometry().x();
//    int y = ui->labVideo->geometry().y();
//    painter.drawImage(QPoint(x, y), img);
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    this->PlayStop();
//}
