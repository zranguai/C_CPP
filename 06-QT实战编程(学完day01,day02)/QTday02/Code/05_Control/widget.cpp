#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //单选按钮 默认选中 男
    ui->rbtn_Man->setChecked(true);

    //点击女单选按钮 打印输出
    connect(ui->radioButton_2, &QRadioButton::clicked,[=](){
        qDebug() << "选中了女的";
    });

    //复选按钮 点击环境好之后 监听
    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
         qDebug() << state;
    });

    //listWidget
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");

//    ui->listWidget->addItem(item);

//    item->setTextAlignment(Qt::AlignHCenter);


    //QStringList   QList<QString>  list<String>
    QStringList list;
    list << "锄禾日当午"<< "汗滴禾下土"<< "谁知盘中餐"<< "粒粒皆辛苦";
    ui->listWidget->addItems(list);


}

Widget::~Widget()
{
    delete ui;
}
