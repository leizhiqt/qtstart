#include "rtsp_player.h"

#include <QThread>

RTSP_Player::RTSP_Player(FFmpegUtils *ffmpeg, QObject *parent)
    : QObject(parent)
    , m_ffmpeg(ffmpeg)
{

}

void RTSP_Player::SetPlayerUrl(QString playerUrl)
{
    this->m_playerUrl = playerUrl;
}

void RTSP_Player::PlayerStart()
{
    qDebug("player start");
    if (m_ffmpeg == NULL){
        emit SigOpenUrlResult(RTSP_Player::FFmpegInitFail);
        return;
    }

    m_ffmpeg->MyFFmpegSetUrl(this->m_playerUrl);
    if (m_ffmpeg->MyFFmpegInit() != 0) {
        emit SigOpenUrlResult(RTSP_Player::FFmpegInitFail);
        return;
    }

    emit SigOpenUrlResult(RTSP_Player::FFmpegInitSucc);

    m_stopped = false;

    while (1) {
        if (m_stopped){
            qDebug("--------------- stop ----------------");
            break;
        }

        if (!m_ffmpeg) {
            break;
        }

        if (m_ffmpeg->MyFFmpepReadFrame() < 0) {
            qDebug("--------------- get frame fail, stop -----------");
            break;
        }

        QThread::msleep(0.02);
    }

    m_ffmpeg->MyFFmpegDestroy();
    emit SigOpenUrlResult(RTSP_Player::FFmpegStoped);
    qDebug("---------------- quit -----------------");

    return;
}

void RTSP_Player::PlayerStop()
{
    m_stopped = true;
}
