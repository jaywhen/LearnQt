#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    setModal(true);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);


}
About::~About()
{
    delete ui;
}
