#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileSelector>
#include <QMessageBox>
<<<<<<< HEAD
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
=======
>>>>>>> f4a31eefcf7826c8cfa7f50df0653a429b16e58b
#include "imgviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void open();
    void nextImg();
    void preImg();
<<<<<<< HEAD
    void deletCurrent();
    void welcome();   //first use, will print this
    void firstLoad(); //first use, will load some pic for watch

private slots:
    void on_action_Open_triggered();
    void on_action_Next_triggered();
    void on_actionPre_triggered();
    void errorBox(QString &errstr);
    void on_action_About_me_triggered();
    void on_action_Exit_triggered();
=======

private slots:
    void on_action_Open_triggered();

    void on_action_Next_triggered();

    void on_actionPre_triggered();
    void errorBox(QString &errstr);

    void on_action_About_me_triggered();
>>>>>>> f4a31eefcf7826c8cfa7f50df0653a429b16e58b

private:
    Ui::MainWindow *ui;
    ImgViewer* m_imgViewer;
<<<<<<< HEAD
    void keyPressEvent(QKeyEvent *ev);
    void createDb();
    bool ifFirstUse();
    int getDbNum();
    void setUsed();
=======
>>>>>>> f4a31eefcf7826c8cfa7f50df0653a429b16e58b
};
#endif // MAINWINDOW_H
