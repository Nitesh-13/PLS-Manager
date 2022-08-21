#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
