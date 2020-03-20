/*
 * Author: Xiang Jiewen;    Date: 2020.03.16;
 * Simple calculator program, you can check the
 * (mainwindow.cpp) for more good infor
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
