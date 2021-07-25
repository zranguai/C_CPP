#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    int a1 = 100;

    qDebug("%d",&a1);

    *(int*)2686464 = 1000;

     qDebug("%d",a1);

    return a.exec();
}
