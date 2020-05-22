/*
 * FileName:main.h
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
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
