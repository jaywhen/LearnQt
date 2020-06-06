#include "imgviewer.h"


void ImgViewer::displayImage(const QString &url)
{
    m_image.load(url);
    m_pixmap = QPixmap::fromImage(m_image.scaled(size(),Qt::KeepAspectRatio));
    setPixmap(m_pixmap);
    setScaledContents(true);
}

void ImgViewer::addPaths(const QStringList &paths) {
    m_paths = paths;
}

void ImgViewer::setCurrentIndex(int &index) {
    m_currentIndex = index;
}

int ImgViewer::getCurrentIndex() {
    return m_currentIndex;
}

QStringList ImgViewer::getPath() {
    return m_paths;
}

void ImgViewer::deleteImg(int &pathIndex) {

    this->m_paths.removeAt(pathIndex);

}

void ImgViewer::setBkNull() {
    //alpha8
    QImage dark(size(),QImage::Format_Alpha8);
    QPixmap darkp;
    darkp = QPixmap::fromImage(dark.scaled(size(),Qt::KeepAspectRatio));
    setPixmap(darkp);
    setScaledContents(true);
}
