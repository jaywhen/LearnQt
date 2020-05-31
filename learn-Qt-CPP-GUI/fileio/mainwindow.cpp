#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile fileName("../untitled/test.txt");
    qDebug()<<"suc";
    if(!fileName.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"error";
        return;
    }
    QTextStream in(&fileName);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug()<<line;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

