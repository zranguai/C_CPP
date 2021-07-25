#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    //添加定时器事件
    void timerEvent(QTimerEvent *);

    //第一个定时器 标志
    int id1;
    //第二个定时器 标志
    int id2;


    //重写过滤器事件
    bool eventFilter(QObject *, QEvent *);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
