#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:


    //自定义槽函数 写到public slots  Qt 5.0版本以上 可以写成全局函数或者public作用域下 或者 lambda表达式
public slots:

    //返回值是void
    //需要声明 也需要有实现
    //可以有参数  可以发生重载
    void treat();


    void treat(QString foodName);
};

#endif // STUDENT_H
