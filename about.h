#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {class About;}
QT_END_NAMESPACE

class About : public QDialog
{
    Q_OBJECT
public:
    About(QWidget *parent = nullptr);
    ~About();
private:
    Ui::About *ui;
};

#endif // ABOUT_H
