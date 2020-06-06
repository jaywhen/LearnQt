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
<<<<<<< HEAD
    void deleteImg(int &pathIndex);
    int getCurrentIndex();
    void setBkNull();   //set background as dark color
=======
    int getCurrentIndex();
>>>>>>> f4a31eefcf7826c8cfa7f50df0653a429b16e58b
    QStringList getPath();
    //to do...

private:
    QImage m_image;
    QPixmap m_pixmap;
    QStringList m_paths;
    int m_currentIndex{-1};
};

#endif // VIEWER_H
