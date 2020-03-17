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
