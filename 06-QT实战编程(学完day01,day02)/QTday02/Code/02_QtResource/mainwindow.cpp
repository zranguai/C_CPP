#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //给新建添加小图标
    //ui->actionNew->setIcon(QIcon("E:/Image/Luffy.png"));

    //资源文件添加   语法：   ": + 前缀名  + 文件名称"
    ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));

    ui->actionOpen->setIcon(QIcon(":/Image/LuffyQ.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
