#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap做绘图设备  对不同平台做了显示的优化
//    QPixmap pix(300,300);

//    pix.fill(Qt::white);

//    QPainter painter(&pix);

//    painter.setPen( QPen(Qt::red) );
//    painter.drawEllipse(QPoint(150,150) , 100,100);

//    pix.save("E:\\pix.png");

    //QImage做绘图设备   不同平台下显示效果一样，可以对像素的访问做了优化

//    QImage img(300,300,QImage::Format_RGB32);

//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen( QPen(Qt::green) );
//    painter.drawEllipse(QPoint(150,150) , 100,100);
//    img.save("E:\\img.png");


    //QPicture  记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.setPen( QPen(Qt::blue) );
    painter.drawEllipse(QPoint(150,150) , 100,100);
    painter.end();

    pic.save("E:\\pic.zt");

}

void Widget::paintEvent(QPaintEvent *)
{
    QImage img;
    img.load(":/Image/Luffy.png");

    QPainter painter(this);


//    //修改像素点
//    for(int i  = 100;i< 150;i++)
//    {
//        for(int j = 100;j< 150;j++)
//        {
//           QRgb value  = qRgb(255,0,0);
//           img.setPixel(i,j,value);

//        }
//    }

//    painter.drawImage(0,0,img);

    //重现QPicture命令
    QPicture pic;
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
