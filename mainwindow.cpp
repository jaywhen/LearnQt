#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("XClc");
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);   //Set display right
    ui->lineEdit->setStyleSheet("font-size:24px");//set font size as 24 px
    ui->lineEdit->setText("0");                   //set init word as "0"
    initButton(); //all button set as 0

}

void MainWindow::initButton()
{
    ifClickedOperator = false;
    ifClickedDot = false;
    opFlag = 0;
    valueA = "0";
    valueB = "0";
    echoResult = "0";
    result = 0;
}
void MainWindow::clickNumButton(QString num)
{
    if(!ifClickedOperator)
    {
        result = 0;
        valueA+=num;
        ui->lineEdit->setText(valueA);
    } else{
        valueB+=num;
        ui->lineEdit->setText(valueB);

    }

}
void MainWindow::on_pushButton_AC_clicked()
{
    ui->lineEdit->setText("0");
    ifClickedOperator = false;
    ifClickedDot = false;
    opFlag = 0;
    valueA = "";
    valueB = "";
    result = 0;
    echoResult = "";
}
void MainWindow::on_pushButton_0_clicked()
{
    clickNumButton("0");

}
void MainWindow::on_pushButton_1_clicked()
{
    clickNumButton("1");

}
void MainWindow::on_pushButton_2_clicked()
{
    clickNumButton("2");



}
void MainWindow::on_pushButton_3_clicked()
{
    clickNumButton("3");



}
void MainWindow::on_pushButton_4_clicked()
{
    clickNumButton("4");



}
void MainWindow::on_pushButton_5_clicked()
{
    clickNumButton("5");


}
void MainWindow::on_pushButton_6_clicked()
{
    clickNumButton("6");


}
void MainWindow::on_pushButton_7_clicked()
{
    clickNumButton("7");


}
void MainWindow::on_pushButton_8_clicked()
{
    clickNumButton("8");

}
void MainWindow::on_pushButton_9_clicked()
{
    clickNumButton("9");

}

void MainWindow::on_pushButton_add_clicked()
{
    if(!ifClickedOperator)
    {
        ui->lineEdit->setText("+");
        ifClickedOperator = true;
        opFlag = 1;
    } else {
        ui->lineEdit->setText("error!");

    }

}
void MainWindow::on_pushButton_sub_clicked()
{
    if(!ifClickedOperator)
    {
        ui->lineEdit->setText("-");
        ifClickedOperator = true;
        opFlag = 2;
    } else {
        ui->lineEdit->setText("error!");

    }

}
void MainWindow::on_pushButton_mult_clicked()
{
    if(!ifClickedOperator)
    {
        ui->lineEdit->setText("x");
        ifClickedOperator = true;
        opFlag = 3;
    } else {
        ui->lineEdit->setText("error!");

    }
}
void MainWindow::on_pushButton_divi_clicked()
{
    if(!ifClickedOperator)
    {
        ui->lineEdit->setText("÷");
        ifClickedOperator = true;
        opFlag = 4;
    } else {
        ui->lineEdit->setText("error!");

    }
}

void MainWindow::on_pushButton_equal_clicked()
{
    switch (opFlag)
    {
    case 1:
        result += valueA.toFloat()+valueB.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 2:
        result = valueA.toFloat() - valueB.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 3:
        result = valueA.toFloat() * valueB.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 4:
        if(valueB.toFloat()==0)
        {
            ui->lineEdit->setText("error!");
            //QTimer::singleShot(1000,this,SLOT(on_pushButton_clear_clicked()));
            break;
        }else {
            result = valueA.toFloat() / valueB.toFloat();
            echoResult = QString("%1").arg(result);
            ui->lineEdit->setText(echoResult);
            break;


        }

    }
}
void MainWindow::on_pushButton_dot_clicked()
{
    if(!ifClickedDot)
    {
        if(!ifClickedOperator)
        {
            valueA+=".";
            ui->lineEdit->setText(valueA);
        }else {
            valueB+=".";
            ui->lineEdit->setText(valueB);
        }
    } else {

        if(ifClickedOperator)
        {
            valueB+=".";
            ui->lineEdit->setText(valueB);

        }

    }
    ifClickedDot = true;

}
//menu bar
void MainWindow::on_actionWhat_is_XCalc_triggered()
{
    AboutX *ab = new AboutX();
    ab->setWindowTitle("About me");
    ab->show();

}
MainWindow::~MainWindow()
{
    delete ui;
}
