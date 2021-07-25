#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //点击按钮 弹出文件对话框，选择文件
    connect(ui->pushButton,&QPushButton::clicked,[=](){

         QString filePath = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\zhangtao\\Desktop");
         qDebug() << filePath;

         if(filePath.isEmpty())
         {
             QMessageBox::warning(this,"警告","文件路径不能为空");
             return;
         }
         else
         {
             //将文件路径放入到 lineEdit中
             ui->lineEdit->setText(filePath);


             //读文件
             //文本编码格式类
             QTextCodec * codec = QTextCodec::codecForName("gbk");

             //将文件内容 读取到 textEdit中
             QFile file(filePath);

             //指定打开方式
             file.open(QIODevice::ReadOnly);

             //Qt默认支持的格式是utf-8
             QByteArray array;
//             array = file.readAll();



             while (!file.atEnd()) {
                  array += file.readLine();
             }


             ui->textEdit->setText(array);
             //ui->textEdit->setText( codec->toUnicode(array)  );

             file.close();



             //写文件
//             file.open(QIODevice::Append); //QIODevice::Append追加的方式写文件
//             file.write("啊啊啊啊!");
//             file.close();



             //读取文件信息
             QFileInfo  info(filePath);

             qDebug() << "文件后缀名:" <<info.suffix() << "文件大小：" <<info.size() <<
                         "文件名："<< info.fileName() << "文件路径："<<info.filePath();

             qDebug() << "创建日期：" << info.created().toString("yyyy-MM-dd hh:mm:ss")<<
                         "最后修改日期："<<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
         }


    });
}

Widget::~Widget()
{
    delete ui;
}
