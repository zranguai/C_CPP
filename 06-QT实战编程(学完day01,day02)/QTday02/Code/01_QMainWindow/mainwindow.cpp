#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(600,400);

    //1、菜单栏 只能有一个
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction * newAction = fileMenu->addAction("新建");

    //添加分割线
    fileMenu->addSeparator();

    QAction * openAction = fileMenu->addAction("打开");


    //2、工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    toolBar->setFloatable(false);

    //设置移动 （总开关）
    toolBar->setMovable(false);

    //工具栏中放入小部件
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //状态栏  只能有一个
    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);

    QLabel * label1 = new QLabel("左侧提示信息",this);
    stBar->addWidget(label1);

    QLabel * label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);



    //铆接部件 （浮动窗口）  可以有多个
    QDockWidget * dock = new QDockWidget("aaa" ,this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

    //只允许左右停靠
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    //核心部件  只能有一个
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}



MainWindow::~MainWindow()
{

}
