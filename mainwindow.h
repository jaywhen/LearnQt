#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "aboutx.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    //--------------------------------
    void initAll();
    void clickedNum(char num);
    QVector<QString> splitStr(QString beSplit);
    void infixToSuffix(QVector<QString> beStack);
    int caclPostfix();
    int getPriority(QChar op);
    bool isNumStr(QString str);
    bool isOpStr(QChar str);


    ~MainWindow();
private slots:

    //operation button
    void on_pushButton_AC_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_sub_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_divi_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_backSP_clicked();
    void on_pushButton_leftBracket_clicked();
    void on_pushButton_rightBracket_clicked();

    //numeric button
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    //menu button
    void on_actionWhat_is_XCalc_triggered();

private:
    Ui::MainWindow *ui;

    //after modify
    QVector<QString> redesign; //Store split string
    QVector<QString> completeExp;
    QStack<QString> oPStack;
    QStack<QString> expOutPutStack;
    QStack<double> caclStack;

    bool ifWorkFinished;

};
#endif // MAINWINDOW_H
