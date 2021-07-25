#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //修改SpinBox  右侧滚动条 跟着移动

    void(QSpinBox:: *spinBoxP)(int) = &QSpinBox::valueChanged;

    connect(ui->spinBox,spinBoxP , [=](int val){
            ui->horizontalSlider->setValue(val);
    });


    //右侧滚动条移动，左侧跟着改变数字

    connect(ui->horizontalSlider,&QSlider::valueChanged , [=](int val){
            ui->spinBox->setValue(val);
    });
}

//设置值
void SmallWidget::setData(int val)
{
    ui->horizontalSlider->setValue(val);

}
//获取值
int SmallWidget::getData()
{
    return ui->horizontalSlider->value();

}

SmallWidget::~SmallWidget()
{
    delete ui;
}
