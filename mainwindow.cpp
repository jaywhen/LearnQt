#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("XClc");
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);//Set display right
    ui->lineEdit->setStyleSheet("font-size:24px");//set font size as 24 px
    ui->lineEdit->setText("0");//set init word as "0"
    //ui->lineEdit->setText("0");
    ifClickedOperator = false;
    opFlag = 0;
    currentEcho = "";
    tmpStorage = "";
    result = 0;
    echoResult = "";


}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->lineEdit->setText("0");
    ifClickedOperator = false;
    opFlag = 0;
    currentEcho = "";
    tmpStorage = "";
    result = 0;
    echoResult = "";

}
void MainWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->setText("0");

}
void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit->setText("1");


}
void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("2");


}
void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("3");


}
void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText("4");


}
void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("5");


}
void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText("6");


}
void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText("7");


}
void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText("8");


}
void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText("9");


}

void MainWindow::on_pushButton_add_clicked()
{
    ui->lineEdit->setText("+");


}
void MainWindow::on_pushButton_sub_clicked()
{
    ui->lineEdit->setText("-");
}
void MainWindow::on_pushButton_divi_clicked()
{
    ui->lineEdit->setText("÷");
}
void MainWindow::on_pushButton_mult_clicked()
{
    ui->lineEdit->setText("x");
}
void MainWindow::on_pushButton_equal_clicked()
{
    ui->lineEdit->setText("=");
}
void MainWindow::on_pushButton_dot_clicked()
{
    ui->lineEdit->setText(".");
}
MainWindow::~MainWindow()
{
    delete ui;
}
