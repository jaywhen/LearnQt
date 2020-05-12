#ifndef FILESIO_H
#define FILESIO_H

#include <QObject>
#include <QFile>
//#include <QFileInfo>
#include <QUrl>
class FilesIO : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
public:
    explicit FilesIO(QObject *parent = 0);

    //void setData



public slots:
    void save(const QString &data, const QUrl &url);
    QString open(const QUrl &url);


//protected slots:
//    void dataRefresh();


//signals:
//    void dataChanged();


private:
    QFile m_file;
    //QString m_data;
    //QTimer m_Timer;

};

#endif // FILESIO_H
