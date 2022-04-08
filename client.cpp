#include "client.h"
#include "Start.h"

Client::Client()
{

}

void Client::takeShow()
{
    //mWin->hide();
    if(mWin->ui->lineEdit->isVisible())
        mWin->ui->lineEdit->hide();
    else
        mWin->ui->lineEdit->show();
}
