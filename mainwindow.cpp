/*
 * FileName:mainwindow.cpp
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"
#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    setActions();
    setMenus();
    readSettings();

    findDialog = 0;
    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActions()
{
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

}

void MainWindow::setMenus()
{
    for (int i = 0; i < MaxRecentFiles; ++i)
        ui->menuFile->addAction(recentFileActions[i]);
}

//void MainWindow::setContextMenu()
//{
//    spreadsheet->addAction(ui->actionCut);
//    spreadsheet->addAction(ui->actionCopy);
//    spreadsheet->addAction(ui->actionPaset);
//    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
//}

bool MainWindow::okToContinue()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("XSpreadsheet"),
                        tr("The document has been modified.\n"
                           "Do you want to save your changes?"),
                        QMessageBox::Yes | QMessageBox::No
                        | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
            return save();
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

//void MainWindow::updateStatusBar()
//{
//    locationLabel->setText(spreadsheet->currentLocation());
//    formulaLabel->setText(spreadsheet->currentFormula());
//}

//void MainWindow::setStatusBar()
//{

//    locationLabel = new QLabel(" W999 ");
//    locationLabel->setAlignment(Qt::AlignHCenter);
//    locationLabel->setMinimumSize(locationLabel->sizeHint());

//    formulaLabel = new QLabel;
//    formulaLabel->setIndent(3);

//    ui->statusbar->addWidget(locationLabel);
//    ui->statusbar->addWidget(formulaLabel, 1);

//    connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)),
//            this, SLOT(updateStatusBar()));
//    connect(spreadsheet, SIGNAL(modified()),
//            this, SLOT(spreadsheetModified()));

//    updateStatusBar();

//}

void MainWindow::readSettings()
{
    QSettings settings("Software Inc.", "XSpreadsheet");

    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid", true).toBool();
    ui->actionShow_Grid->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc", true).toBool();
    ui->actionShow_Grid->setChecked(autoRecalc);
}

void MainWindow::writeSettings()
{
    QSettings settings("Software Inc.", "XSpreadsheet");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
    settings.setValue("showGrid", ui->actionShow_Grid->isChecked());
    settings.setValue("autoRecalc", ui->actionAuto_Recalculate->isChecked());
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while (i.hasNext()) {
        if (!QFile::exists(i.next()))
            i.remove();
    }

    for (int j = 0; j < MaxRecentFiles; ++j) {

        if (j < recentFiles.count()) {
            QString text = tr("&%1 %2")
                           .arg(j + 1)
                           .arg(strippedName(recentFiles[j]));

            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);

        } else {
            recentFileActions[j]->setVisible(false);
        }
    }

}


QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);

    QString shownName = tr("Untitled");

    if (!curFile.isEmpty()) {
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);        
        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg(shownName)
                                   .arg(tr("XSpreadsheet")));
}
void MainWindow::newFile()
{
    if (okToContinue()) {
        spreadsheet->clear();
        setCurrentFile("");
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                               tr("Save Spreadsheet"), ".",
                               tr("XSpreadsheet files (*.sp)"));
    if (fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MainWindow::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    if (!spreadsheet->writeFile(fileName)) {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);

    return true;
}

void MainWindow::openRecentFile()
{
    if (okToContinue()) {
        QAction *action = qobject_cast<QAction *>(sender());
        if (action)
            loadFile(action->data().toString());
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if (!spreadsheet->readFile(fileName)) {
        ui->statusbar->showMessage(tr("Loading canceled"), 2000);
        return false;
    }

    setCurrentFile(fileName);
    ui->statusbar->showMessage(tr("File loaded"), 2000);
    return true;
}


void MainWindow::goToCell()
{
    GoToCellDialog dialog(this);
    if (dialog.exec()) {
        QString str = dialog.lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
                                    str[0].unicode() - 'A');
    }
}
void MainWindow::sort()
{
    SortDialog dialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    dialog.setColumnRange('A' + range.leftColumn(),
                          'A' + range.rightColumn());

    if (dialog.exec()) {
        SpreadsheetCompare compare;
        compare.keys[0] =
              dialog.primaryColumnCombo->currentIndex();
        compare.keys[1] =
              dialog.secondaryColumnCombo->currentIndex() - 1;
        compare.keys[2] =
              dialog.tertiaryColumnCombo->currentIndex() - 1;
        compare.ascending[0] =
              (dialog.primaryOrderCombo->currentIndex() == 0);
        compare.ascending[1] =
              (dialog.secondaryOrderCombo->currentIndex() == 0);
        compare.ascending[2] =
              (dialog.tertiaryOrderCombo->currentIndex() == 0);
        spreadsheet->sort(compare);
    }
}

void MainWindow::find()
{
    if (!findDialog) {
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(const QString &,
                                            Qt::CaseSensitivity)),
                spreadsheet, SLOT(findNext(const QString &,
                                           Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(const QString &,
                                                Qt::CaseSensitivity)),
                spreadsheet, SLOT(findPrevious(const QString &,
                                               Qt::CaseSensitivity)));
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();

}

void MainWindow::open()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Open Spreadsheet"), ".",
                                   tr("XSpreadsheet files (*.sp)"));
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About XSpreadsheet"),
                       tr("<h2>XSpreadsheet 1.0</h2>"
                          "<p>A Spreadsheet program followed Qt demo."
                          "<p>For learn more:<p>"
                          "<p><a href=\"https://github.com/jaywhen/SpreadShiiiiit\">代码地址</a>"
                          "<p><a href=\"https://jaywhen.com/\">作者主页</a>"
                          ));
}


void MainWindow::on_actionSave_triggered()
{
    this->save();
}

void MainWindow::on_actionSaveas_triggered()
{
    this->saveAs();

}

void MainWindow::on_actionOpen_triggered()
{
    this->open();
}

void MainWindow::on_actionNew_triggered()
{
    this->newFile();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    spreadsheet->copy();
}

void MainWindow::on_actionPaset_triggered()
{
    spreadsheet->paste();

}

void MainWindow::on_actionDelete_triggered()
{
    spreadsheet->del();
}

void MainWindow::on_actionCut_triggered()
{
    spreadsheet->cut();
}

void MainWindow::on_actionRow_triggered()
{
    spreadsheet->selectCurrentRow();
}

void MainWindow::on_actionColumn_triggered()
{
    spreadsheet->selectCurrentColumn();
}

void MainWindow::on_actionAll_triggered()
{
    spreadsheet->selectAll();
}

void MainWindow::on_actionShow_Grid_toggled(bool arg1)
{
    spreadsheet->setShowGrid(arg1);
}

void MainWindow::on_actionAbout_triggered()
{
    this->about();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionFind_triggered()
{
    this->find();
}

void MainWindow::on_actionGo_to_Cell_triggered()
{
    this->goToCell();
}

void MainWindow::on_actionSort_triggered()
{
    this->sort();
}
