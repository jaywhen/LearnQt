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

    if (ifFirstUse()) {

        qDebug() << "nihao";
        this->welcome();
        setUsed();
        firstLoad();

    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_imgViewer;
}



void MainWindow::open() {

    QFileDialog openFilesDialog(this);
    openFilesDialog.setWindowTitle(tr("Open imgs that let's the stackoverflow!"));
    QStringList filetypes;
    filetypes << "PNG (*.png)" <<"JPG (*jpg)";
    openFilesDialog.setNameFilters(filetypes);

    openFilesDialog.setFileMode(QFileDialog::ExistingFiles);

    if(openFilesDialog.exec() == QDialog::Accepted) {

        QStringList imgfiles = openFilesDialog.selectedFiles();
        qDebug() << imgfiles;
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

static bool ifInTheRange(int index, int low, int high) {
    if(index >= low && index <= high) return true;
    return false;
}

void MainWindow::nextImg() {

    int index = m_imgViewer->getCurrentIndex();
    index += 1;
    m_imgViewer->setCurrentIndex(index);


    int low = 0;
    int high = m_imgViewer->getPath().length() - 1;

    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {

        index = m_imgViewer->getCurrentIndex();
        QString url = m_imgViewer->getPath().at(index);
        m_imgViewer->displayImage(url);
        qDebug() << "now current index is "<<m_imgViewer->getCurrentIndex();

    } else {
        QString mes = "in the last picture";
        errorBox(mes);
        index -= 1;
        m_imgViewer->setCurrentIndex(index);
    }


}

void MainWindow::preImg() {

    int index = m_imgViewer->getCurrentIndex();
    index -= 1;
    m_imgViewer->setCurrentIndex(index);


    int low = 0;
    int high = m_imgViewer->getPath().length() - 1;
    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {

        index = m_imgViewer->getCurrentIndex();
        QString url = m_imgViewer->getPath().at(index);
        m_imgViewer->displayImage(url);
        qDebug() << "now current index is "<<m_imgViewer->getCurrentIndex();


    } else {
            QString mes = "in the first pictrue";
            errorBox(mes);
            index+=1;
            m_imgViewer->setCurrentIndex(index);
    }




}

void MainWindow::on_action_Next_triggered()
{
    this->nextImg();

}

void MainWindow::on_actionPre_triggered()
{
    this->preImg();
}

void MainWindow::on_action_About_me_triggered()
{

    QMessageBox::information(this, "About me", tr("<h2>A img viewer\n</h2>"
                                                  "<p> 2018051604079 向杰文(JayWhenXiang) \n</p>"
                                                  "<p><a href=\"https://jaywhen.com/\">Author's home page</a>\n"
                                                  "<p><a href=\"https://github.com/jaywhen/LearnQt/tree/master/learn-Qt-CPP-GUI/iviewer\">Code Repositories </a>"

                                                  )
                             );
}

void MainWindow::deletCurrent() {

    int index{0};
    int low = 0;
    int high = m_imgViewer->getPath().length() - 1;

    //have only one pic
    if (low == high) {

        m_imgViewer->setBkNull();

    }
    if(ifInTheRange(m_imgViewer->getCurrentIndex(), low, high)) {

        //del the last one
        if (m_imgViewer->getCurrentIndex() == high) {

            this->on_actionPre_triggered();
            index = m_imgViewer->getCurrentIndex();
            index += 1;
            m_imgViewer->deleteImg(index);
            index -= 1;
            m_imgViewer->setCurrentIndex(index);

        } else {
            //del onther one
            this->on_action_Next_triggered();
            //delete

            index = m_imgViewer->getCurrentIndex();
            index -= 1;
            m_imgViewer->deleteImg(index);
            m_imgViewer->setCurrentIndex(index);

        }



        qDebug () << "now current index is " << m_imgViewer->getCurrentIndex();
        qDebug () << "now both have " << m_imgViewer->getPath().length();

    } else {
            QString mes = "in the end";
            errorBox(mes);
            index-=1;
            m_imgViewer->setCurrentIndex(index);
    }



}

void MainWindow::keyPressEvent(QKeyEvent *ev) {

    switch (ev->key()) {

    case Qt::Key_Delete: deletCurrent();break;
    default:break;

    }
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::createDb() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");
    if(db.open()) {
           qDebug() << "Db set success!";
       } else {
           qDebug() << "Db set error";
       }

    QString creatStr = "create table Info (usr INT)";

    QSqlQuery quer;
    if( !quer.exec(creatStr) ) {
        qDebug() << "error";
    }else {
        qDebug() << "success";


    }

    QString queyStr = "insert into Info (usr) values(0);";
    if ( quer.exec(queyStr) ) {
        qDebug() << "success";
    } else {
        qDebug() << "error";
    }

}

void MainWindow::welcome() {
    QMessageBox::information(this, "Welcome", "<h2>Welcome to IViewer!\n</h2>"
                                              "<p> 2018051604079 向杰文 (JayWhenXiang) \n</p>"
                                              "If this is your first use IViewer\n"
                                              "You will see this INFOdialog and it will tell you some\n"
                                              "tips to you use it.\n"
                                              "You can enter space to next picture, and backspace to pre-picture\n"
                                              "You can also enter del key to delete current img && jump to next img\n"
                                              "<p> And the two site below is the author's info, you can contact he just click the link!\n </p>"
                                              "<p><a href=\"https://jaywhen.com/\">Author's home page</a>\n"
                                              "<p><a href=\"https://github.com/jaywhen/LearnQt/tree/master/learn-Qt-CPP-GUI/iviewer\">Code Repositories </a>"

                             );
}

int MainWindow::getDbNum() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");
    if(db.open()) {
           qDebug() << "Db set success!";
       } else {
           qDebug() << "Db set error";
       }

    QSqlQuery query;
    QString select = "SELECT usr FROM Info;";

    if ( query.exec(select) ) {
        qDebug() << "select success";
    } else {
        qDebug() << "select error";
    }
    query.next();

    int ret{0};
    ret = query.value(0).toInt();
    qDebug () << "ret is "<<ret;
    return ret;

}
bool MainWindow::ifFirstUse() {

    QFile db("../info.db");
    if(! db.exists()) {
        qDebug() << "will create a db";
        createDb();
        return true;     //if first use? true
    } else {
        qDebug() << "have a db";
        if( getDbNum() == 0 ) {
            qDebug() << "get db num is 0";
            return true; //if first use? true
        }
        return false;    //if first use? false

    }

}

void MainWindow::setUsed() {

    QString update = "UPDATE Info SET usr = 1;";
    QSqlQuery query;
    if( query.exec(update) ) {
        qDebug() << "update success" ;

    } else {
        qDebug() << "error";
    }

}

void MainWindow::firstLoad() {
    //
    QStringList expic = {"../iviewer/img/Bob.png", "../iviewer/img/mod_synths_D_SimpleDesktops.png", "../iviewer/img/sbg.png", "../iviewer/img/sk1.png", "../iviewer/img/star.png", "../iviewer/img/Uno_Xray.png"};
    m_imgViewer->addPaths(expic);

    //from the first index
    m_imgViewer->displayImage(expic.at(0));

    int index = 0;
    m_imgViewer->setCurrentIndex(index);

}
