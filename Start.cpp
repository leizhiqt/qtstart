#include "Start.h"

QtStart::QtStart(){
    mWin = new MainWindow();
    mWin->show();

    client = new Client();
    qDebug("start");
}


QtStart::~QtStart(){
    delete mWin;
    delete client;
    qDebug("destroy and Exit");
}

//MainWindow *mWin;
//Client *client;

//void start(){
//    mWin = new MainWindow();
//    mWin->show();

//    client = new Client();
//    qDebug("start");
//}

//void destroy(){
//    delete mWin;
//    delete client;
//    qDebug("destroy and Exit");
//}
