#ifndef FILESIO_H
#define FILESIO_H

#include <QQuickTextDocument>
#include <QtGui/QTextCharFormat>
#include <qqmlfile.h>

class FilesIO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    //Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
public:
    FilesIO();
    QUrl fileUrl() const;

public Q_SLOTS:
    void saveAs(const QUrl &arg, const QString &fileType);
    void setFileUrl(const QUrl &arg);

Q_SIGNALS:
    void error(QString message);

private:
    QTextDocument *m_doc;
    QUrl m_fileUrl;


};

#endif // FILESIO_H
