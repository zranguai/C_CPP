#include "mypushbutton.h"
#include <QDebug>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::~MyPushButton()
{
    qDebug() << "MyPushButton的析构函数调用";
}
