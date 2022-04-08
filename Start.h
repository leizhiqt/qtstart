#ifndef START_H
#define START_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

extern MainWindow *mWin;
extern Client *client;

extern void start();
extern void destroy();

#endif // START_H
