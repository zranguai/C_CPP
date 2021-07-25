#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建 创建对话框
    connect(ui->actionNew,&QAction::triggered,this,[=](){

        //对话框分类  模态对话框   非模态对话框
        //模态对话框  不可以对其他窗口进行操作
        //非模态对话框  可以对其他窗口进行操作


        //模态对话框创建
//        QDialog dlg(this);
//        dlg.resize(120,30);
//        dlg.exec();

        //非模态对话框创建
//          QDialog *dlg2 = new QDialog(this);
//          dlg2->resize(120,30);
//          dlg2->show();
//          //设置 55号属性
//          dlg2->setAttribute(Qt::WA_DeleteOnClose);


        //QMessageBox对话框

        //错误提示对话框
        //QMessageBox::critical(this,"错误","critical");

        //信息提示对话框
        //QMessageBox::information(this,"信息","info");

        //询问提示对话框
        // 参数1   父窗口  参数2  标题  参数3  提示信息  参数4  按键类型  参数5  默认关联回车按键
//        if( QMessageBox::Save ==  QMessageBox::question(this,"询问","question" , QMessageBox::Save | QMessageBox::Cancel ,QMessageBox::Cancel))
//        {
//             qDebug()<<"点击的是保存";
//        }
//        else
//        {
//             qDebug()<<"点击的是取消";
//        }

        //警告提示对话框
        //QMessageBox::warning(this,"警告","warning");

        //颜色对话框
//         QColor color = QColorDialog::getColor(Qt::red);
//         qDebug() << color.red() << color.green() << color.blue() ;

        //文件对话框
//          QString fileName = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\zhangtao\\Desktop","(*.doc)");
//          qDebug () <<fileName;

        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug() << "字体" << font.family().toUtf8().data() << "字号"<< font.pointSize()
                 << "是否加粗"<<font.bold() << "是否倾斜" << font.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
