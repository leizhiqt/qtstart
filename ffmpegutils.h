#ifndef FFMPEGUTILS_H
#define FFMPEGUTILS_H

#include <QObject>
#include <QImage>

#define __STDC_CONSTANT_MACORS
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
}


class FFmpegUtils : public QObject
{
    Q_OBJECT
public:
    explicit FFmpegUtils(QObject *parent = 0);
    ~FFmpegUtils();

    void MyFFmpegSetUrl(QString rtspUrl);
    void MyFFmpegInfo();

    int MyFFmpegInit();
    void MyFFmpegDestroy();
    int MyFFmpepReadFrame();
signals:
    void MyFFmpegSigGetOneFrame(QImage img);

public slots:

private:
    int              m_videoIndex;
    QString          m_rtspUrl;
    AVPicture        m_AVPicture;
    AVCodec         *m_AVCodec;
    AVFormatContext *m_AVFormatContext;
    AVCodecContext  *m_AVCodecContext;
    AVFrame         *m_AVFrame;
    AVFrame         *m_AVFrameRGB;
    AVPacket        *m_AVPacket;
    SwsContext      *m_SwsContext;
    uint8_t         *m_OutBuffer;
    AVPixelFormat ConvertDeprecatedFormat(enum AVPixelFormat format);
};

#endif // FFMPEGUTILS_H
