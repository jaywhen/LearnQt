/*
 * FileName:gotocelldialog.h
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
 */
#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H


#include <QDialog>
#include "ui_gotocelldialog.h"

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged();
};

#endif // GOTOCELLDIALOG_H

