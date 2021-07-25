#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //tableWidget表格控件使用

    //设置列数
    ui->tableWidget->setColumnCount(3);

    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");


    //设置行数
    ui->tableWidget->setRowCount(5);

    QList<QString> nameList;
    nameList << "亚瑟"<< "安琪拉"<<"妲己"<<"赵云"<< "孙悟空";
    QStringList sexList;
    sexList << "男"<< "女"<< "女"<< "男"<< "中立";


    for(int i  = 0 ; i < 5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(nameList[i]));

        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(sexList.at(i)));

        //int 转 QString   QString::number(int)
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem( QString::number(i+18)  ));
    }





}

Widget::~Widget()
{
    delete ui;
}
