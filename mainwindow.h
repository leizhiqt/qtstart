#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QAction>
#include <QImage>

#include <QThread>

#include "ffmpegutils.h"
#include "rtsp_player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
//    void paintEvent(QPaintEvent *event);

private:
    void closeEvent(QCloseEvent *event);

private slots:
    int OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason);
    void closing();

    void on_pushButton_clicked();
    //    void SlotGetOneFrame(QImage img);

//signals:
//    void SigPlayStart();

public:
    Ui::MainWindow *ui;

private:
    QSystemTrayIcon *systemTray;
    QAction *minimumAct,*maximumAct,*restoreAct,*quitAct;
    QMenu *pContextMenu;
    int count;

private:
    QImage m_image;
    FFmpegUtils *m_ffmpeg=nullptr;
    //RTSP_Player *m_player=nullptr;
    //QThread *m_playThread = nullptr;

//private:
//    void PlayStart();
//    void PlayStop();
//    void MyFFmpegTest();
};
#endif // MAINWINDOW_H
