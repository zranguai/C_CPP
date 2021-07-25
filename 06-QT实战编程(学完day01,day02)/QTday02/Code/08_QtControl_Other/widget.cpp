#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮 切换 stacked容器

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->btn_ScrollArea,&QPushButton::clicked,[=](){
           ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
           ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
           ui->stackedWidget->setCurrentIndex(2);
    });

    //下拉框使用
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    //点击按钮 选中拖拉机下拉框内容
    connect(ui->btn_select,&QPushButton::clicked,[=](){
//        ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    //利用QLabel显示图片
    ui->label_img->setPixmap(QPixmap(":/Image/butterfly.png"));


    //利用QLabel显示动态图片  格式要求 gif
    QMovie * movie =new QMovie(":/Image/mario.gif");
    ui->label_movie->setMovie(movie);

    movie->start();


}

Widget::~Widget()
{
    delete ui;
}
