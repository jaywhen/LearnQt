#include "filesio.h"
#include <QtGui/QTextDocument>
//#include <QtGui/QTextCursor>
//#include <QtGui/QFontDatabase>
//#include <QtGui/QFontMetricsF>
#include <QtCore/QFileInfo>
FilesIO::FilesIO()
    :m_doc(0)
{}
/*
 * how to use:
 * FileDialog {
 *       id: fileDialog
 *       nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
 *       onAccepted: {
 *           if (fileDialog.selectExisting)
 *               document.fileUrl = fileUrl
 *           else
 *               document.saveAs(fileUrl, selectedNameFilter)
 *       }
 *   }
 */
void FilesIO::saveAs(const QUrl &arg, const QString &filetype)
{
    bool isHtml = filetype.contains(QLatin1String("htm"));
    QLatin1String ext(isHtml ? ".html" : ".txt");
    QString localPath = arg.toLocalFile();
    if(!localPath.endsWith(ext))
        localPath += ext;
    QFile f(localPath);
    if (!f.open(QFile::WriteOnly) | QFile::Truncate | (isHtml ? QFile::NotOpen : QFile::Text)) {
        emit error(tr("Cannot save: ") + f.errorString());
        return;
    }
    f.write((isHtml ? m_doc->toHtml() : m_doc->toPlainText()).toLocal8Bit());
    f.close();
    setFileUrl(QUrl::fromLocalFile(localPath));
}
