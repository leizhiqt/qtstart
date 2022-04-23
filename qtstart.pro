QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network websockets

CONFIG += c++11

DESTDIR=$$OUT_PWD/bin

#设置c编译器flag参数
#QMAKE_CFLAGS += -static
#设置c++编译器flag参数
#QMAKE_CXXFLAGS += -static
#设置链接器flag参数
#QMAKE_LFLAGS += -static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_MESSAGELOGCONTEXT

message($$PWD)
message($$OUT_PWD)
message($$DESTDIR)

SOURCES += \
    Start.cpp \
    client.cpp \
    #ffmpegutils.cpp \
    #rtsp_player.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS += \
    Start.h \
    client.h \
    #ffmpegutils.h \
    #rtsp_player.h \
    mainwindow.h

INCLUDEPATH += /home/zhi/ffmpeg-linux64/include
LIBS += -L/home/zhi/ffmpeg-linux64/lib -lavformat -lavcodec -lavutil -lavdevice -lavfilter -lswresample -lswscale -lz -llzma -lbz2

FORMS += \
    mainwindow.ui

RESOURCES += \
        icon.qrc

OBJECTS_DIR=$$OUT_PWD/tmp/obj
MOC_DIR=$$OUT_PWD/tmp/moc
RCC_DIR=$$OUT_PWD/tmp/rcc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


