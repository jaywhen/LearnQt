#include "filesio.h"
#include <QDebug>
#include <QTextStream>

FilesIO::FilesIO(QObject* parent) :
    QObject(parent)
{}

void FilesIO::save(const QString &data, const QUrl &url)
{
    m_file.setFileName(url.toLocalFile());
    m_file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&m_file);
    out<<data;
    m_file.close();
}

QString FilesIO::open(const QUrl &url)
{
    m_file.setFileName(url.toLocalFile());
    m_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text = m_file.readAll();
    m_file.close();

    return text;
}
