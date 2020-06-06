//#include <QtWidgets> /* Qt5 use #include <QtWidgets> instead of #include <QtGui> */
#include "finddialog.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QLayout>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwarkCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    //have not text, can not click button


    connect(lineEdit, &QLineEdit::textChanged, this, &FindDialog::enableFindButton);

    connect(findButton, &QPushButton::clicked, this, &FindDialog::findClicked);
    connect(closeButton, &QPushButton::clicked, this, &FindDialog::close);


    //connect(lineEdit, SIGNAL(textChanged(const QString &)),
    //            this, SLOT(enableFindButton(const QString &)));
    //connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    //connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    //layout
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwarkCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());


}


void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}


void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if(backwarkCheckBox->isChecked()){
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }

}

FindDialog::~FindDialog() {}

