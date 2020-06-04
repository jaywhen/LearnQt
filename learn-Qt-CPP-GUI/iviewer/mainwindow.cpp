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


//    QString fileurl = QFileDialog::getOpenFileName(this,
//                                                   tr("Open a img Dir"), "." ,
//                                                   tr("PNG files (.png)") );
    QFileDialog openFilesDialog(this);
    openFilesDialog.setWindowTitle(tr("Open a many many imgs"));
    QStringList filetypes;
    filetypes << "PNG (*.png)" <<"JPG (*jpg)";
    openFilesDialog.setNameFilters(filetypes);

    openFilesDialog.setFileMode(QFileDialog::ExistingFiles);

//    QStringList filesName = QFileDialog::selectedFiles();
//    if(!fileurl.isEmpty()) {

//    }
    if(openFilesDialog.exec() == QDialog::Accepted) {

        QStringList imgfiles = openFilesDialog.selectedFiles();
        m_imgViewer->addPaths(imgfiles);

        //from the first index
        m_imgViewer->displayImage(imgfiles.at(0));

        int index = 0;
        m_imgViewer->setCurrentIndex(index);
        //m_imgViewer->displayimgs


        qDebug() << imgfiles;

    }

    //QStringList allfile = QFileSelector::allSelectors();

}

void MainWindow::on_action_Open_triggered()
{
    this->open();
}

void MainWindow::nextImg() {
    int index = m_imgViewer->getCurrentIndex();
    index += 1;
    QString url = m_imgViewer->getPath().at(index);
    m_imgViewer->displayImage(url);
    //index += 1;
    m_imgViewer->setCurrentIndex(index);
    qDebug () << "next is " <<index;
}

void MainWindow::preImg() {
    int index = m_imgViewer->getCurrentIndex();
    index -= 1;
    QString url = m_imgViewer->getPath().at(index);
    m_imgViewer->displayImage(url);
    //index += 1;
    m_imgViewer->setCurrentIndex(index);
}





static bool ifInTheRange(int index, int low, int high) {
    if(index >= low && index <= high) return true;
    return false;
}


void MainWindow::on_action_Next_triggered()
{
    int low = 0;
    int high = m_imgViewer->getPath().length();
    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {
        this->nextImg();
    }


}

void MainWindow::on_actionPre_triggered()
{
    this->preImg();


}
