//2018051604079 Xiang Jiewen
#ifndef FILESIO_H
#define FILESIO_H

#include <QObject>
#include <QFile>
//#include <QFileInfo>
#include <QUrl>
class FilesIO : public QObject
{
    Q_OBJECT
public:
    explicit FilesIO(QObject *parent = 0);


public slots:
    void saveas();
    void save(const QString &data, const QUrl &url);
    QString open(const QUrl &url);



private:
    QFile m_file;

};

#endif // FILESIO_H
