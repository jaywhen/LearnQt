#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
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
    QString test = "-3";
    double t = test.toFloat();
    qDebug()<<t;
    initAll();
}
int MainWindow::getPriority(QChar op)
{
    //op.cell(), returns the cell (least significant byte) of the Unicode character.
    //The smaller the number, the higher the priority
    switch (op.cell()) {
    case '#': return 3;
    case '+':
    case '-': return 2;
    case 'x':
    case '/': return 1;
    case '(': return 0;
    case ')': return -1; //')'special priority, special handling
    }
    return 0;
}
QVector<QString> MainWindow::splitStr(QString beSplit)
{
    //Rough Division
    QVector<QString> newString;
    for(int i=0; i<beSplit.size(); ++i)
    {
        //Process unsigned numbers first
        QString thenum;
        while (beSplit[i].isDigit() || beSplit[i]=='.') {
            thenum += beSplit[i];
            ++i;
        }
        if(thenum.size())
            newString.push_back(thenum);
        if(!(beSplit[i].isDigit() || beSplit[i]=='.')) //if is op
        {
            QString tmpOp;
            tmpOp = beSplit[i];
            newString.push_back(tmpOp);
        }
    }

    //return newString;//will be comment


    //now we got the newString(QVector)
    //Handle minus sign
    for(int j=0; j<newString.size(); ++j)
    {
        //assume we have - 36 + 1 * 4 / 2
        if(j==0 && newString.size() > 1 && newString[j] == '-' && newString[j+1][0].isDigit())
        {
            newString[j+1].insert(0, '-');
            newString.remove(j);
        }else if(j==0 && newString.size() > 1 && newString[j] == '-' && newString[j+1][0]=='(')
            newString.insert(0, "0");
        else if(newString[j] == "-" && j != 0 && newString[j-1]=="(" && j != newString.size() - 1 && newString[j+1][0].isDigit())
        {
            newString[j+1].insert(0, "-");
            newString.remove(j);
        }
    }
    //debug
    qDebug()<<newString[0];
    qDebug()<<newString[1];
    qDebug()<<newString[2];

    return newString;





}
void MainWindow::infixToSuffix()
{
    //QString theExp = ui->lineEdit->text();

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
        ui->lineEdit->setText(theline+"/");
        ifWorkFinished = false;
    }

}

void MainWindow::on_pushButton_equal_clicked()
{
    //Press the "=" sign to change the expression on the screen to a suffix expression
    //just for debug ....
     //QString haha =ui->lineEdit->text();
     //QVector<QString> yes = splitStr(haha);






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
