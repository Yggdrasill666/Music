#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml/MainWindow.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &a,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);
  return a.exec();
}
