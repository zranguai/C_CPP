#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

    //设置鼠标追踪
   // setMouseTracking(true);
}


//鼠标进入事件
void MyLabel::enterEvent(QEvent *)
{
//    qDebug() << "鼠标进入了";

}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent *)
{

//     qDebug() << "鼠标离开了";
}


//鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev)
{

    //鼠标左键按下  打印信息
//    if(ev->button() == Qt::LeftButton)
//    {
        QString str =  QString("鼠标按下了 x =  %1  y = %2 " ).arg(ev->x()).arg(ev->y());
        qDebug() << str;
//    }


}
//鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    if(ev->button() == Qt::LeftButton)
    {
        QString str =  QString("鼠标释放了 x =  %1  y = %2 " ).arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }

}
//鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)
//    {
        QString str =  QString("鼠标移动了 x =  %1  y = %2 " ).arg(ev->x()).arg(ev->y());
        qDebug() <<str;
//    }
}


//事件分发器 :用途，分发事件
bool MyLabel::event(QEvent *e)
{

    if( e->type() == QEvent::MouseButtonPress)
    {
        //如果是鼠标按下  拦截事件，不向下分发

        QMouseEvent *ev = static_cast<QMouseEvent *>(e);

        QString str =  QString("event中  鼠标按下了 x =  %1  y = %2 " ).arg(ev->x()).arg(ev->y());
        qDebug() << str;

        return true;
    }


    //其他事件  抛给父类去处理
    return QLabel::event(e);
}
