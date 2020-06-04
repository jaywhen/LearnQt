#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_imgViewer(new ImgViewer)
{
    ui->setupUi(this);
    setWindowTitle(tr("IViewer"));
    setCentralWidget(m_imgViewer);
    //m_imgViewer->displayImage();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_imgViewer;
}



void MainWindow::open() {

    QFileDialog openFilesDialog(this);
    openFilesDialog.setWindowTitle(tr("Open a many many imgs"));
    QStringList filetypes;
    filetypes << "PNG (*.png)" <<"JPG (*jpg)";
    openFilesDialog.setNameFilters(filetypes);

    openFilesDialog.setFileMode(QFileDialog::ExistingFiles);

    if(openFilesDialog.exec() == QDialog::Accepted) {

        QStringList imgfiles = openFilesDialog.selectedFiles();
        m_imgViewer->addPaths(imgfiles);

        //from the first index
        m_imgViewer->displayImage(imgfiles.at(0));

        int index = 0;
        m_imgViewer->setCurrentIndex(index);
        qDebug() << "now is "<<m_imgViewer->getCurrentIndex();
        //m_imgViewer->displayimgs


        qDebug() << imgfiles;

    }


}

void MainWindow::errorBox(QString &errstr) {
    QString err = "ops You are " + errstr + " ! \n";
    QMessageBox::warning(this, errstr, err);
}

void MainWindow::on_action_Open_triggered()
{
    this->open();
}

void MainWindow::nextImg() {
    int index = m_imgViewer->getCurrentIndex();
    QString url = m_imgViewer->getPath().at(index);
    m_imgViewer->displayImage(url);
    //index += 1;
    m_imgViewer->setCurrentIndex(index);
}

void MainWindow::preImg() {
    int index = m_imgViewer->getCurrentIndex();
    //index -= 1;
    QString url = m_imgViewer->getPath().at(index);
    m_imgViewer->displayImage(url);
    //index += 1;
    m_imgViewer->setCurrentIndex(index);
    qDebug () << "pre is " <<index;
}





static bool ifInTheRange(int index, int low, int high) {
    if(index >= low && index <= high) return true;
    return false;
}


void MainWindow::on_action_Next_triggered()
{
    int index = m_imgViewer->getCurrentIndex();
    index += 1;
    m_imgViewer->setCurrentIndex(index);


    int low = 0;
    int high = m_imgViewer->getPath().length() - 1;
    qDebug() << "high is "<< high;
    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {

        this->nextImg();
        qDebug() << "now is "<<m_imgViewer->getCurrentIndex();

    } else {
        QString mes = "in the end";
        errorBox(mes);
    }


}

void MainWindow::on_actionPre_triggered()
{
    int index = m_imgViewer->getCurrentIndex();
    index -= 1;
    m_imgViewer->setCurrentIndex(index);


    int low = 0;
    int high = m_imgViewer->getPath().length() - 1;
    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {

        this->preImg();
    } else {
            QString mes = "in the begin";
            errorBox(mes);
    }



}

void MainWindow::on_action_About_me_triggered()
{
//    QString mes = "A img viewer\n";
//    mes += tr("<a href=\"https://jaywhen.com/\">Author's home page</a>");
//    mes += tr("<a href=\"https://github.com/jaywhen/LearnQt/tree/master/learn-Qt-CPP-GUI/iviewer\">Code Repositories </a>");
    QMessageBox::information(this, "About me", tr("<h2>A img viewer\n</h2>"
                                                  "<p><a href=\"https://jaywhen.com/\">Author's home page</a>\n"
                                                  "<p><a href=\"https://github.com/jaywhen/LearnQt/tree/master/learn-Qt-CPP-GUI/iviewer\">Code Repositories </a>"

                                                  )




                             );


}
