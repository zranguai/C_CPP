#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}


void Student::treat()
{
    qDebug() << "请老师吃饭";
}


void Student::treat(QString foodName)
{
    //QString 转 char *    通过.toUtf8转为 QByteArray 类型  通过 .data()转为 char *

     qDebug() << "请老师吃饭 , 老师要吃： " << foodName.toUtf8().data();
}
