#include "mainwindow.h"

#include <QApplication>
#include <QMutex>
#include <QMessageLogContext>
#include <QtMessageHandler>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();

    QByteArray localMsg = msg.toLocal8Bit();

    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        //调试信息
        strMsg = QString("Debug:");
        break;
    case QtWarningMsg:
        //警告信息
        strMsg = QString("Warning:");
        break;
    case QtCriticalMsg:
        //严重错误
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        //致命错误
        strMsg = QString("Fatal:");
        break;
    }

    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("DateTime:%1 Message:%2 File:%3  "
                                 "Line:%4  Function:%5 ")
            .arg(strDateTime).arg(localMsg.constData()).arg(context.file)
            .arg(context.line).arg(context.function);

    // 输出信息至文件中（读写、追加形式）
    QString  MyLogFilePath = "";
    MyLogFilePath += "log.txt";
    QFile file(MyLogFilePath);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << strMessage << "\r\n";
    file.flush();
    file.close();

    // 解锁
    mutex.unlock();
}


int main(int argc, char *argv[])
{
    // 安装消息处理程序
    qInstallMessageHandler(myMessageOutput);

    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    return a.exec();
}
