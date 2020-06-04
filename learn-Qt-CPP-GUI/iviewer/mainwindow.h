#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileSelector>
#include <QMessageBox>
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

private slots:
    void on_action_Open_triggered();

    void on_action_Next_triggered();

    void on_actionPre_triggered();
    void errorBox(QString &errstr);

    void on_action_About_me_triggered();

private:
    Ui::MainWindow *ui;
    ImgViewer* m_imgViewer;
};
#endif // MAINWINDOW_H
