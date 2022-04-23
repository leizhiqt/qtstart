#ifndef RTSP_PLAYER_H
#define RTSP_PLAYER_H


#include "ffmpegutils.h"
#include <QObject>


class RTSP_Player : public QObject
{
    Q_OBJECT
public:
    enum PlayerState {
        FFmpegInitFail = 0,
        FFmpegInitSucc,
        FFmpegStoped
    };

    explicit RTSP_Player(FFmpegUtils *ffmpeg = nullptr, QObject *parent = nullptr);
    void SetPlayerUrl(QString playerUrl);

signals:
    void SigOpenUrlResult(int result);

public slots:
    void PlayerStart();
    void PlayerStop();

private:
    volatile bool   m_stopped;              // 停止播放标识，为true时停止播放，退出播放循环
    QString         m_playerUrl;            // 播放url
    FFmpegUtils        *m_ffmpeg;               // MyFFmepg指针
};

#endif // RTSP_PLAYER_H
