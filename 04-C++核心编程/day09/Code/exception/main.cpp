#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

//异常接口声明   throw(空)代表 不允许抛出异常
void func()throw(int ,double)
{

    throw 3.14;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    try
    {
        func();
    }
    catch(int)
    {
        qDebug() << "int 类型的异常捕获"<<endl;
    }
    catch(...)
    {
         qDebug() << "其他 类型的异常捕获"<<endl;
    }

    return a.exec();
}
