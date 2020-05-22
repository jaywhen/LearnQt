/*
 * FileName:sortdialog.cpp
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
 */
#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

#include "ui_sortdialog.h"

class SortDialog : public QDialog, public Ui::SortDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);

    void setColumnRange(QChar first, QChar last);
};

#endif // SORTDIALOG_H

