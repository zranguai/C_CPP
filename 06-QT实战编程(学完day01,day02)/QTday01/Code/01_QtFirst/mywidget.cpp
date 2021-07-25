#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>
//命名规范
// 类名 首字母 大小  单词和单词之间 首字母 大写
// 变量、函数名 首字母小写 单词和单词之间 首字母 大写

//快捷键
// 运行 ctrl + R
// 编译 ctrl + B
// 查询 ctrl + F
// 注释 ctrl + /
// 帮助 F1
// 字体缩放  ctrl + 鼠标滚轮
// 整行代码移动  ctrl + shift + ↑ ↓
// 自动对齐  ctrl + i
// 同名之间的.h .cpp切换  F4

// 帮助文档 F1    左侧列表中按钮    C:\Qt\Qt5.6.0\5.6\mingw49_32\bin


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //按钮
    QPushButton * btn = new QPushButton;

    //btn->show(); //show用顶层方式弹出

    //如果想显示到当前窗口中 ，需要做依赖
    btn->setParent(this);

    //显示文本
    btn->setText("德玛西亚");

    //按钮2
    QPushButton * btn2 = new QPushButton("第二个",this);

    //移动btn2
    btn2->move(100,100);

    //重置窗口大小
    resize(600,400);

    //按钮 可以重置大小吗？ 可以
    //btn->resize(300,200);

    //指定窗口标题
    setWindowTitle("第一个窗口");

    //设置窗口固定大小
    setFixedSize(600,400);


    //创建自定义的按钮
    MyPushButton * myBtn  = new MyPushButton;
    myBtn->setParent(this);
    myBtn->setText("我的按钮");
    myBtn->move( 300,200);


    //点击按钮  关闭窗口
    //connect(  信号发送者，发送的信号，信号的接受者，处理的槽函数）
    //信号和槽 优点： 松散耦合
   // connect(myBtn, &QPushButton::clicked , this, &QWidget::close );
    connect( myBtn , &MyPushButton::clicked ,this, &MyWidget::close);

}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget析构调用";
}
