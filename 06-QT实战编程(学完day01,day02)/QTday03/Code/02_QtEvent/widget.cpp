#include "widget.h"
#include "ui_widget.h"
#include <QTimer> //定时器类
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //开启定时器
    id1 = startTimer(1000); //单位 毫秒


    id2 = startTimer(2000); //单位 毫秒



    //创建定时器对象
    QTimer * timer1 = new QTimer(this);
    timer1->start(500);

    //每隔0.5秒 会抛出一个信号timeout出来
    connect(timer1,&QTimer::timeout , [=](){
        //每隔0.5秒中 让label_4数字++
        static int num = 1;
        ui->label_4->setText( QString::number(num++) );
    });


    //点击暂停按钮  停止定时器
    connect(ui->pushButton,&QPushButton::clicked,[=](){
         timer1->stop();
    });


    //给label添加事件过滤器 ，做更高级的拦截操作

    //1、给控件安装过滤器
    ui->label->installEventFilter(this);

}

//重写过滤器事件
bool Widget::eventFilter(QObject * obj , QEvent * e)
{
    if(obj == ui->label)
    {

        if( e->type() == QEvent::MouseButtonPress)
        {
            //如果是鼠标按下  拦截事件，不向下分发

            QMouseEvent *ev = static_cast<QMouseEvent *>(e);

            QString str =  QString("事件过滤器  鼠标按下了 x =  %1  y = %2 " ).arg(ev->x()).arg(ev->y());
            qDebug() << str;

            return true;
        }

    }

    //其他事件抛给父类
    return QWidget::eventFilter(obj,e);

}


//添加定时器事件
void Widget::timerEvent(QTimerEvent * e)
{

    if(e->timerId() == id1)
    {
        //每隔1秒中 让label_2数字++
        static int num = 1;
        ui->label_2->setText( QString::number(num++) );
    }
    if(e->timerId() == id2)
    {
        //每隔2秒让label_3数字++
        static int num2 = 1;
        ui->label_3->setText( QString::number(num2++) );
    }
}

Widget::~Widget()
{
    delete ui;
}
