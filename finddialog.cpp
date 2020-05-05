/*
 * FileName:finddialog.cpp
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
 */
#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    ui->findButton->setEnabled(false);
    setWindowTitle(tr("Find"));

}

FindDialog::~FindDialog()
{
    delete ui;
}
void FindDialog::findClicked()
{
    QString text = ui->lineEdit->text();
    Qt::CaseSensitivity cs =
            ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    if (ui->backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}
void FindDialog::on_findButton_clicked()
{
    this->findClicked();
}
void FindDialog::enableFindButton(const QString &text)
{
    ui->findButton->setEnabled(!text.isEmpty());
}
void FindDialog::on_lineEdit_textChanged(const QString &arg1)
{
    this->enableFindButton(arg1);
}

void FindDialog::on_closeButton_clicked()
{
    this->close();
}
