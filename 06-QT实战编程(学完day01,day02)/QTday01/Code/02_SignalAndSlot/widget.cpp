#include "widget.h"
#include <QPushButton>
#include <QDebug>
// Teacher老师类
// Student学生类
// 下课后  老师会触发一个 饿了 的信号
// 学生响应这个信号 并且 请老师吃饭



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->zt = new Teacher(this);
    this->st = new Student(this);

    //连接信号和槽
    //connect(zt,&Teacher::hungry,st,&Student::treat);

    //classIsOver();


    //连接有参信号和槽
    // 函数指针 可以指向 函数地址
//    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;

//    void(Student:: *studentSlot)(QString ) = &Student::treat;

//    connect(zt,teacherSignal, st,studentSlot);

   // classIsOver();

    //创建按钮
    QPushButton * btn = new QPushButton("下课" , this);

    resize(600,400);


    void(Teacher:: *teacherSignal2)() = &Teacher::hungry;

    void(Student:: *studentSlot2)() = &Student::treat;

    connect(zt,teacherSignal2, st,studentSlot2);

    //1、信号是可以连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);
    //2、可以断开信号和槽
    disconnect(zt,teacherSignal2, st,studentSlot2);

    //3、一个信号可以响应多个槽函数

    //4、多个信号可以连接同一个槽函数

    //5、信号和槽函数的参数类型 必须一一对应
    //   信号的参数个数 可以多余槽函数的参数个数，反之不可以 , 参数类型要一一对应


    //Qt4版本信号和槽写法
    //利用Qt4版本连接有参信号和槽
    //优势 ：参数直观
    //劣势 ：参数类型不做匹配检测
    // Qt4本质   SIGNAL("hungry(int)")SLOT("treat(QString)")
//    connect(zt, SIGNAL(hungry(QString)) , st , SLOT(treat(QString)));

//    classIsOver();


    //[=] 函数体内可以使用Lambda所在作用范围内所有可见的局部变量
    QPushButton * btn2 = new QPushButton("aaa",this);
    QPushButton * btn3 = new QPushButton("aaa",this);
    [=](){
        btn2->setText("bbb");
        btn3->setText("bbb");
    }();

    //最常用lambda使用 [=](){}
    QPushButton * btn4 = new QPushButton("aaa",this);
    btn4->move( 100, 0);

    //当进行信号和槽连接时候，控件内会进入一个锁的状态
    connect(btn4,&QPushButton::clicked,this,[=](){
        btn4->setText("bbb");
    });


   //加上mutable修饰符后，可以修改按值传递进来的拷贝
   QPushButton * myBtn = new QPushButton (this);
   QPushButton * myBtn2 = new QPushButton (this);
   myBtn2->move(100,100);
   int m = 10;

   connect(myBtn,&QPushButton::clicked,this,[m] () mutable { m = 20; qDebug() << m; });

   connect(myBtn2,&QPushButton::clicked,this,[=] ()  { qDebug() << m; });

   qDebug() << m;


   //-> 返回值类型
   int num = [=]()->int{
        return 1000;
   }();
   qDebug() << "num = " << num ;


   //点击按钮 关闭窗口
   connect(btn4,&QPushButton::clicked,[=](){
        //this->close();
        st->treat("宫保鸡丁");
   });

}

void Widget::classIsOver()
{
    //触发自定义信号
//    emit this->zt->hungry();


   emit this->zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{

}
