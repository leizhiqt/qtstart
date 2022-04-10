#include "client.h"
#include "Start.h"

//Client::Client()
//{

//}

void Client::takeShow()
{
    //mWin->hide();
    //qtStart->mWin;
    if(qtStart->mWin->ui->lineEdit->isVisible())
        qtStart->mWin->ui->lineEdit->hide();
    else
        qtStart->mWin->ui->lineEdit->show();
}
