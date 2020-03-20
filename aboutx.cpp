/*
 * Just a menu window, for more details
 * you can check:
 * ---------------------------------------------------------
 * about.ui                                                 |
 * mainwindow.cpp->void on_actionWhat_is_XCalc_triggered(); |
 * ---------------------------------------------------------
 */

#include "aboutx.h"
#include "ui_aboutx.h"

AboutX::AboutX(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutX)
{
    ui->setupUi(this);
}

AboutX::~AboutX()
{
    delete ui;
}
