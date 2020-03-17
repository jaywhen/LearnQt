#ifndef ABOUTX_H
#define ABOUTX_H

#include <QWidget>

namespace Ui {
class AboutX;
}

class AboutX : public QWidget
{
    Q_OBJECT

public:
    explicit AboutX(QWidget *parent = nullptr);
    ~AboutX();

private:
    Ui::AboutX *ui;
};

#endif // ABOUTX_H
