#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //点击移动按钮  让图片移动
    posX = 0;
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        posX += 20;

        //手动调用绘图事件
        update();
    });


    QTimer * timer = new QTimer(this);
    timer->start(10);

    connect(timer,&QTimer::timeout,[=](){
         posX ++;
         update();
    });

}


//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //画资源图片

    //如果超出屏幕，强制变为 0位置

    QPixmap pix(":/Image/Luffy.png");

    if(posX > this->width())
    {
        posX = -pix.width();
    }

    painter.drawPixmap(posX,0,QPixmap(":/Image/Luffy.png"));



//    if(posX > this->width())
//    {
//        posX = 0;
//    }

//    painter.drawPixmap(posX,0,QPixmap(":/Image/Luffy.png"));






   /////////////////////////////// //高级设置
//    painter.drawEllipse(QPoint(100,100) , 50,50);

//    //设置抗锯齿能力   效率会稍微比低
//    painter.setRenderHint(QPainter::Antialiasing);

//    painter.drawEllipse(QPoint(250,100) , 50,50);



//    painter.drawRect(QRect(20,20,50,50));

//    //移动画家
//    painter.translate(100,0);

//    //保存画家状态
//    painter.save();

//    painter.drawRect(QRect(20,20,50,50));

//    painter.translate(100,0);

//    //取出画家状态
//    painter.restore();

//    painter.drawRect(QRect(20,20,50,50));


   /////////////////////////////// //基础设置
//    //设置画笔
//    QPen pen(QColor(255,0,0));

//    //设置画笔宽度
//    pen.setWidth(3);
//    //设置风格
//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);


//    //画刷
//    QBrush brush(Qt::cyan);

//    //设置风格
//    brush.setStyle(Qt::Dense4Pattern);

//    painter.setBrush(brush);


//    //画线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));


//    //画圆
//    painter.drawEllipse( QPoint(100,100) , 50,50);


//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //写字
//    painter.drawText(QRect(10,200,150,100),"好好学习，天天向上");
}

Widget::~Widget()
{
    delete ui;
}
