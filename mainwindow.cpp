/* Author: Xiang Jiewen;    Date: 2020.03.18;
 *
 * Note:
 * XCacl's core code are all there, so
 * If you are reading the whole program for the first time
 * and want to quickly grasp the logic of the whole program,
 * i recommended to read the following functions directly:
 * -----------------------------------------------
 * QVector<QString> splitStr(QString beSplit);   |
 * void infixToSuffix(QVector<QString> beStack); |
 * Stat caclPostfix();                            |
 * -----------------------------------------------
 *
 * There are many bugs hidden in this program,
 * if(you find them)
 * {
 *      please issues me on the github:
 *      https://github.com/jaywhen/XCalc/issues
 *      Thank you!
 * }
 *
 * For more information of this program, please check the
 * README.md file
 * That's all, stay at home, we can defeat the virus!
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("XCacl");
    setWindowIcon(QIcon(":/icons/caclf.png"));
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);   //Set display right
    ui->lineEdit->setStyleSheet("font-size:24px");//set font size as 24 px
    ui->lineEdit->setText("0");                   //set init word as "0"
    initAll();
}

//set all stat init
void MainWindow::initAll()
{
    ifWorkFinished = true;
    if(!oPStack.isEmpty())
        oPStack.clear();
    if(!expOutPutStack.isEmpty())
        expOutPutStack.clear();
    if(!completeExp.isEmpty())
        completeExp.clear();
    if(!caclStack.isEmpty())
        caclStack.clear();
}

int MainWindow::getPriority(QChar op)
{
    //op.cell(), returns the cell (least significant byte) of the Unicode character.
    //The smaller the number, the higher the priority
    switch (op.cell()) {
    case '+':
    case '-': return 2;
    case 'x':
    case '/': return 1;
    case '(': return 0;
    case ')': return -1; //')'special priority, special handling
    }
    return 0;
}

//just some bools ------------------------------------
bool MainWindow::isOpStr(QChar str)
{
    if(str=='+' || str=='-' || str=='x' || str=='/' || '(' || ')')
        return true;
    else
        return false;
}

bool MainWindow::isNumStr(QString str)
{
    if(str[0].isDigit() || (str[0]=="-"&& str[1].isDigit()))
        return true;
    else
        return false;
}
//bools over -----------------------------------------

//the core code --------------------------------------
QVector<QString> MainWindow::splitStr(QString beSplit)
{
    qDebug()<<beSplit;
    qDebug()<<"---------";
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
        if(isOpStr(beSplit[i])) //if is op
        {
            if(i==beSplit.size())
                break;
            //this is a little bug wait to debug

            QString tmpOp;
            tmpOp = beSplit[i];
            newString.push_back(tmpOp);
            qDebug()<<"now i is : "<<i<<"   "<<beSplit[i]<<"-----";
            qDebug()<<"tmop is : "<<tmpOp;
        }
    }

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
    for(int a=0; a<newString.size();++a)
    {
        qDebug()<<newString[a]<<"  off set";
    }


    return newString;

}


void MainWindow::infixToSuffix(QVector<QString> beStack)
{

    for(int i=0; i<beStack.size(); ++i)
    {
        if(isNumStr(beStack[i]))
        {
            expOutPutStack.push(beStack[i]);
            continue;
        }else
        {
            if(beStack[i][0]=="(")
            {
                oPStack.push(beStack[i]);
                continue;
            }
            else if(beStack[i][0]==")")
            {
                while(1)
                {
                    if(oPStack.top()=="(")
                    {
                        oPStack.pop();
                        break;
                    }
                    else {
                        expOutPutStack.push(oPStack.top());
                        oPStack.pop();
                    }

                }
                continue;
            }
            else if(oPStack.size()==0 || getPriority(beStack[i][0])<getPriority(oPStack.top()[0]) || oPStack.top()=="(")
            {
                //when the priority of the op to be added
                //is lower than that of the top of the stack
                oPStack.push(beStack[i]);
                continue;
            } else if(isOpStr(beStack[i][0]) && getPriority(beStack[i][0])>=getPriority(oPStack.top()[0] ) )
            {
                while(!oPStack.empty() && getPriority(beStack[i][0])>=getPriority(oPStack.top()[0]))
                {
                    expOutPutStack.push(oPStack.top());
                    oPStack.pop();
                }
                oPStack.push(beStack[i]);
            }
        }
    }
    for(int k=0; k<oPStack.size(); ++k)
    {
        //qDebug()<<oPStack.top()<<";";
        expOutPutStack.push(oPStack.pop());
    }

    qDebug()<<"============comp==============";
    int sz = expOutPutStack.size();
    for(int a = 0; a<sz; ++a)
        completeExp.push_front(expOutPutStack.pop());
    for(int b = 0; b<sz; ++b)
        qDebug()<<completeExp[b];

}
//now we got a complete output stack
Stat MainWindow::caclPostfix()
{
    bool ifStkOverflow = false;
    qDebug()<<"final";
    double num1, num2;
    for(int i=0; i<completeExp.size(); ++i)
    {
        //if is num, just push in stack
        if(isNumStr(completeExp[i]))
        {
            caclStack.push(completeExp[i].toFloat());
            qDebug()<<caclStack.top();
        }else {
            //if is op,
            switch (completeExp[i][0].cell()) {
            case '+':
                num2 = caclStack.pop();
                num1 = caclStack.pop();
                caclStack.push(num1+num2);
                qDebug()<<num1+num2;
                break;
            case '-':
                num2 = caclStack.pop();
                num1 = caclStack.pop();
                caclStack.push(num1-num2);
                qDebug()<<num1-num2;
                break;
            case 'x':
                num2 = caclStack.pop();
                num1 = caclStack.pop();
                caclStack.push(num1*num2);
                qDebug()<<num1*num2;
                break;
            case '/':
                num2 = caclStack.pop();
                num1 = caclStack.pop();
                if(num2==0)
                {
                    qDebug()<<"num2==0";
                    qDebug()<<"num1 / num2 : "<<num1<<" / "<<num2;

                    ifStkOverflow = true;
                    //caclStack.push("")

                }else{
                    caclStack.push(num1/num2);
                    qDebug()<<"not 0: "<<num1/num2;

                }

                break;
            }
        }

    }
    if(ifStkOverflow){

        return 0;
    } else{

        qDebug()<<caclStack.top();
        QString result =QString("%1").arg(caclStack.top());
        ui->lineEdit->setText(result);
        //ui->lineEdit->setText(QString::number(caclStack.top()));
        return 1;


    }

}

void MainWindow::on_pushButton_equal_clicked()
{
    //Press the "=" sign to change the expression on the screen to a suffix expression
    //just for debug ....

     QString theline =ui->lineEdit->text();
     QVector<QString> suffix = splitStr(theline);
     infixToSuffix(suffix);
     int x = caclPostfix();
     if(x)
     {
         initAll();
     }else{
        ui->lineEdit->setText("error!divide by zero...");
     }

}

//the core code over----------------------------------

//ops ---------------------------------------------
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
    //一开始就按-号，做负号显示
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

void MainWindow::on_pushButton_AC_clicked()
{
    ui->lineEdit->setText("0");
    initAll();

}
//ops over ----------------------------------------

// nums -------------------------------------------
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
//nums over--------------------------------

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
