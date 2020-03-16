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

    ifClickedOperator = false;
    ifClickedDot = false;
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
    ifClickedDot = false;
    opFlag = 0;
    currentEcho = "";
    tmpStorage = "";
    result = 0;
    echoResult = "";
}
void MainWindow::on_pushButton_0_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="0";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="0";
        ui->lineEdit->setText(tmpStorage);

    }

}
void MainWindow::on_pushButton_1_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="1";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="1";
        ui->lineEdit->setText(tmpStorage);

    }


}
void MainWindow::on_pushButton_2_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="2";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="2";
        ui->lineEdit->setText(tmpStorage);

    }



}
void MainWindow::on_pushButton_3_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="3";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="3";
        ui->lineEdit->setText(tmpStorage);

    }



}
void MainWindow::on_pushButton_4_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="4";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="4";
        ui->lineEdit->setText(tmpStorage);

    }



}
void MainWindow::on_pushButton_5_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="5";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="5";
        ui->lineEdit->setText(tmpStorage);

    }


}
void MainWindow::on_pushButton_6_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="6";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="6";
        ui->lineEdit->setText(tmpStorage);

    }


}
void MainWindow::on_pushButton_7_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="7";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="7";
        ui->lineEdit->setText(tmpStorage);

    }



}
void MainWindow::on_pushButton_8_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="8";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="8";
        ui->lineEdit->setText(tmpStorage);

    }



}
void MainWindow::on_pushButton_9_clicked()
{
    if(!ifClickedOperator)
    {
        result = 0;
        currentEcho+="9";
        ui->lineEdit->setText(currentEcho);
    } else{
        tmpStorage+="9";
        ui->lineEdit->setText(tmpStorage);

    }


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
        result += currentEcho.toFloat()+tmpStorage.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 2:
        result = currentEcho.toFloat() - tmpStorage.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 3:
        result = currentEcho.toFloat() * tmpStorage.toFloat();
        echoResult = QString("%1").arg(result);
        ui->lineEdit->setText(echoResult);
        break;
    case 4:
        if(tmpStorage.toFloat()==0)
        {
            ui->lineEdit->setText("error!");
            //QTimer::singleShot(1000,this,SLOT(on_pushButton_clear_clicked()));
            break;
        }else {
            result = currentEcho.toFloat() / tmpStorage.toFloat();
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
            currentEcho+=".";
            ui->lineEdit->setText(currentEcho);
        }else {
            tmpStorage+=".";
            ui->lineEdit->setText(tmpStorage);
        }
    } else {

        if(ifClickedOperator)
        {
            tmpStorage+=".";
            ui->lineEdit->setText(tmpStorage);

        }

    }
    ifClickedDot = true;

}
MainWindow::~MainWindow()
{
    delete ui;
}
