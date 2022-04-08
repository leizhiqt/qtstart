#include "Start.h"

MainWindow *mWin;
Client *client;

void start(){
    mWin = new MainWindow();
    mWin->show();

    client = new Client();
    qDebug("start");
}

void destroy(){
    delete mWin;
    delete client;
    qDebug("destroy and Exit");
}
