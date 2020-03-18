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
    initAll();
}

void MainWindow::initAll()
{
    ifWorkFinished = true;
    if(!oPStack.isEmpty())
        oPStack.clear();
    if(!expOutPutStack.isEmpty())
        expOutPutStack.clear();
    oPStack.push('#');
}
void MainWindow::clickedNum(char num)
{
    if(ifWorkFinished)
    {
        ui->lineEdit->setText(QString(num));
        ifWorkFinished=false;
    }else
    {
        QString theLine = ui->lineEdit->text();
        ui->lineEdit->setText(theLine+num);
    }

}

//void MainWindow::initButton()
//{
//    ifClickedOperator = false;
//    ifClickedDot = false;
//    opFlag = 0;
//    valueA = "0";
//    valueB = "0";
//    echoResult = "0";
//    result = 0;
//}
//void MainWindow::clickNumButton(QString num)
//{
//    if(!ifClickedOperator)
//    {
//        result = 0;
//        valueA+=num;
//        ui->lineEdit->setText(valueA);
//    } else{
//        valueB+=num;
//        ui->lineEdit->setText(valueB);

//    }

//}
void MainWindow::on_pushButton_AC_clicked()
{
    ui->lineEdit->setText("0");
    initAll();

}
void MainWindow::on_pushButton_0_clicked()
{

    clickedNum('0');

}
void MainWindow::on_pushButton_1_clicked()
{

    clickedNum('1');

}
void MainWindow::on_pushButton_2_clicked()
{

    clickedNum('2');



}
void MainWindow::on_pushButton_3_clicked()
{

    clickedNum('3');



}
void MainWindow::on_pushButton_4_clicked()
{

    clickedNum('4');



}
void MainWindow::on_pushButton_5_clicked()
{

    clickedNum('5');


}
void MainWindow::on_pushButton_6_clicked()
{

    clickedNum('6');


}
void MainWindow::on_pushButton_7_clicked()
{

    clickedNum('7');


}
void MainWindow::on_pushButton_8_clicked()
{

    clickedNum('8');

}
void MainWindow::on_pushButton_9_clicked()
{

    clickedNum('9');

}
void MainWindow::on_pushButton_leftBracket_clicked()
{
    if(ifWorkFinished)
    {
        ui->lineEdit->setText("(");
        ifWorkFinished = false;
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+"(");
        ifWorkFinished = false;
    }



}
void MainWindow::on_pushButton_rightBracket_clicked()
{
    if(ifWorkFinished)
    {
        ui->lineEdit->setText(")");
        ifWorkFinished = false;
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+")");
        ifWorkFinished = false;
    }

}
void MainWindow::on_pushButton_backSP_clicked()
{
    QString theline = ui->lineEdit->text();
    ui->lineEdit->setText(theline.mid(0,theline.size()-1));

}

void MainWindow::on_pushButton_add_clicked()
{
    //如果一开始就按+号
    if(ifWorkFinished){
        ui->lineEdit->setText("");
        initAll();
        ifWorkFinished = false;
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+"+");
        ifWorkFinished = false;

    }

}
void MainWindow::on_pushButton_sub_clicked()
{
    //一开始就按-号，做负数显示
    if(ifWorkFinished)
    {
        ui->lineEdit->setText("-");
        ifWorkFinished = false;
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+"-");
        ifWorkFinished = false;
    }

}
void MainWindow::on_pushButton_mult_clicked()
{
    if(ifWorkFinished)
    {
        //ui->lineEdit->setText("You start with x !?");
        initAll();
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+"x");
        ifWorkFinished = false;


    }

}
void MainWindow::on_pushButton_divi_clicked()
{
    if(ifWorkFinished)
    {
        //ui->lineEdit->setText("You start with ÷ !?");
        initAll();
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+"÷");
        ifWorkFinished = false;
    }

}

void MainWindow::on_pushButton_equal_clicked()
{


}
void MainWindow::on_pushButton_dot_clicked()
{
    if(ifWorkFinished)
    {
        //ui->lineEdit->setText("You start with . !?");
        initAll();
    }else {
        QString theline = ui->lineEdit->text();
        ui->lineEdit->setText(theline+".");
        ifWorkFinished = false;
    }

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
