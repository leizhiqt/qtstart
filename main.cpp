#include <QApplication>

#include "Start.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start();
//    QObject::connect(&a,SIGNAL(aboutToQuit()),mWin,SLOT(closing()));
//    const int retval=a.exec();
//    destroy();
//    return retval;
    return a.exec();
}
