/*
 * FileName:mainwindow.h
 * Name: Xiang Jiewen  Student-ID: 2018051604079
 * Class: SE.class 3
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void newFile();
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    void open();
    void find();
    void openRecentFile();
    //void updateStatusBar();
    void goToCell();
    void sort();
    void about();

    void on_actionSave_triggered();

    void on_actionSaveas_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaset_triggered();

    void on_actionDelete_triggered();

    void on_actionCut_triggered();

    void on_actionRow_triggered();

    void on_actionColumn_triggered();

    void on_actionAll_triggered();

    void on_actionShow_Grid_toggled(bool arg1);

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionFind_triggered();

    void on_actionGo_to_Cell_triggered();

    void on_actionSort_triggered();

private:
    Ui::MainWindow *ui;
    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;
    FindDialog *findDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    QString curFile;
    QString strippedName(const QString &fullFileName);
    QStringList recentFiles;
    Spreadsheet *spreadsheet;

    bool okToContinue();
    void readSettings();
    void writeSettings();
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void setRecentFileActions();
    void setStatusBar();
    bool loadFile(const QString &fileName);



};
#endif // MAINWINDOW_H
