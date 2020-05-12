//2018051604079 Xiang Jiewen
#include <QApplication>
#include <QQmlApplicationEngine>
#include "filesio.h"
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<FilesIO>("FilesIO", 1, 0, "FilesIO");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
