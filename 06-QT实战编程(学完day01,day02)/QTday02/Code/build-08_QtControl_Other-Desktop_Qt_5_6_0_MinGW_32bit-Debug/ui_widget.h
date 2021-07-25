/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_13;
    QWidget *page_2;
    QToolButton *toolButton;
    QWidget *page_3;
    QRadioButton *radioButton;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioButton_2;
    QWidget *tab_2;
    QToolButton *toolButton_2;
    QWidget *tab_3;
    QPushButton *pushButton_14;
    QPushButton *btn_ScrollArea;
    QPushButton *btn_ToolBox;
    QPushButton *btn_TabWidget;
    QComboBox *comboBox;
    QPushButton *btn_select;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_img;
    QLabel *label_movie;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(778, 625);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 40, 301, 301));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(70, 30, 131, 301));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -61, 112, 360));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(40, 30, 151, 281));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 151, 203));
        pushButton_13 = new QPushButton(page);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(30, 40, 75, 23));
        toolBox->addItem(page, QString::fromUtf8("\345\256\266\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 151, 203));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(30, 30, 37, 18));
        toolBox->addItem(page_2, QString::fromUtf8("\346\234\213\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        radioButton = new QRadioButton(page_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 50, 89, 16));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 251, 231));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(60, 90, 89, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        toolButton_2 = new QToolButton(tab_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(80, 50, 37, 18));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_14 = new QPushButton(tab_3);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(40, 50, 75, 23));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(page_6);
        btn_ScrollArea = new QPushButton(Widget);
        btn_ScrollArea->setObjectName(QStringLiteral("btn_ScrollArea"));
        btn_ScrollArea->setGeometry(QRect(370, 50, 75, 23));
        btn_ToolBox = new QPushButton(Widget);
        btn_ToolBox->setObjectName(QStringLiteral("btn_ToolBox"));
        btn_ToolBox->setGeometry(QRect(370, 110, 75, 23));
        btn_TabWidget = new QPushButton(Widget);
        btn_TabWidget->setObjectName(QStringLiteral("btn_TabWidget"));
        btn_TabWidget->setGeometry(QRect(370, 160, 75, 23));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 370, 69, 22));
        btn_select = new QPushButton(Widget);
        btn_select->setObjectName(QStringLiteral("btn_select"));
        btn_select->setGeometry(QRect(40, 430, 75, 23));
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(160, 370, 42, 22));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(210, 370, 160, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_img = new QLabel(Widget);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(400, 220, 271, 181));
        label_img->setFrameShape(QFrame::NoFrame);
        label_movie = new QLabel(Widget);
        label_movie->setObjectName(QStringLiteral("label_movie"));
        label_movie->setGeometry(QRect(400, 400, 271, 171));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(2);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_12->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_13->setText(QApplication::translate("Widget", "PushButton", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\345\256\266\344\272\272", 0));
        toolButton->setText(QApplication::translate("Widget", "...", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Widget", "\346\234\213\345\217\213", 0));
        radioButton->setText(QApplication::translate("Widget", "RadioButton", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", 0));
        radioButton_2->setText(QApplication::translate("Widget", "RadioButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\231\276\345\272\246", 0));
        toolButton_2->setText(QApplication::translate("Widget", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\350\260\267\346\255\214", 0));
        pushButton_14->setText(QApplication::translate("Widget", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\344\274\240\346\231\272", 0));
        btn_ScrollArea->setText(QApplication::translate("Widget", "scroll Area", 0));
        btn_ToolBox->setText(QApplication::translate("Widget", "ToolBox", 0));
        btn_TabWidget->setText(QApplication::translate("Widget", "TabWidget", 0));
        btn_select->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\346\213\226\346\213\211\346\234\272", 0));
        label_img->setText(QString());
        label_movie->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
