QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network websockets

CONFIG += c++11

DESTDIR=$$OUT_PWD/bin

#设置c编译器flag参数
QMAKE_CFLAGS += -static
#设置c++编译器flag参数
QMAKE_CXXFLAGS += -static
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
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
