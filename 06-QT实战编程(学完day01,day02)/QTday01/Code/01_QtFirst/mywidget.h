#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT  //Q_OBJECT宏  支持信号和槽

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
};

#endif // MYWIDGET_H
