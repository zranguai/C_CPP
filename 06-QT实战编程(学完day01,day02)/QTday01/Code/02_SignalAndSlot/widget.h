#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "student.h"
#include "teacher.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


    Teacher * zt;
    Student * st;


    //下课
    void classIsOver();
};

#endif // WIDGET_H
