#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

//返回值  参数列表   函数名
void func(int a)
{
    qDebug("hello world");

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();


    func(1);

    qDebug("%d" , func);

    //利用函数指针 指向函数地址
    void(*pFunc)(int) = (void(*)(int))4199952;

    pFunc(1);



    return a.exec();
}
