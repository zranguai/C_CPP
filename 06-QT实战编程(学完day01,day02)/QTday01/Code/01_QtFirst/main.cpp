#include "mywidget.h"
#include <QApplication> //QApplication 应用程序类


//程序入口  argc  命令行变量数量    命令行变量数组
int main(int argc, char *argv[])
{

    //a 应用程序对象  在Qt中 应用程序对象  有且仅有一个
    QApplication a(argc, argv);

    //通过 窗口类 实例化对象  w
    MyWidget w;
    //窗口是不会默认弹出的，需要调用show方法进行显示
    w.show();


    //a.exec(); 进入消息循环机制   阻塞功能
    return a.exec();

//    while(1)
//    {
//        if( 点击叉子 )
//        {
//            break;
//        }
//    }

}
