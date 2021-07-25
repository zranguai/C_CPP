#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击设置按钮，将小控件设置到一半位置
    connect(ui->btn_set,&QPushButton::clicked,[=](){
            ui->widget->setData(50);
    });

    //点击获取按钮，获取当前显示数字
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->getData();
    });
}

Widget::~Widget()
{
    delete ui;
}
