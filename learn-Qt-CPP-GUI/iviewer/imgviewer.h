#ifndef VIEWER_H
#define VIEWER_H
#include <QImage>
#include <QWidget>
#include <QStringList>
#include <QLabel>

class ImgViewer : public QLabel
{
    Q_OBJECT
public:
    void addPaths(const QStringList &paths);
    void displayImage(const QString &url);
    void setCurrentIndex(int &index);
    int getCurrentIndex();
    QStringList getPath();
    //to do...

private:
    QImage m_image;
    QPixmap m_pixmap;
    QStringList m_paths;
    int m_currentIndex{-1};
};

#endif // VIEWER_H
