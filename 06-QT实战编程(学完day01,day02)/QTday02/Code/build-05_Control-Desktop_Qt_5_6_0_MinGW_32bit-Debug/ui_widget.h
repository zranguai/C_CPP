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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_Man;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(581, 461);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 91, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(30, 60, 111, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/OnePiece.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 130, 55, 70));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rbtn_Man = new QRadioButton(groupBox);
        rbtn_Man->setObjectName(QStringLiteral("rbtn_Man"));

        verticalLayout->addWidget(rbtn_Man);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(100, 130, 67, 70));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 230, 91, 114));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(true);

        verticalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout_3->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout_3->addWidget(checkBox_4);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(180, 40, 371, 291));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "abc", 0));
        toolButton->setText(QApplication::translate("Widget", "\346\265\267\350\264\274\346\227\227", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\200\247\345\210\253", 0));
        rbtn_Man->setText(QApplication::translate("Widget", "\347\224\267", 0));
        radioButton_2->setText(QApplication::translate("Widget", "\345\245\263", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\251\232\345\220\246", 0));
        radioButton_3->setText(QApplication::translate("Widget", "\345\267\262\345\251\232", 0));
        radioButton_4->setText(QApplication::translate("Widget", "\346\234\252\345\251\232", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\351\244\220\345\216\205\350\260\203\346\237\245", 0));
        checkBox->setText(QApplication::translate("Widget", "\347\216\257\345\242\203\345\245\275", 0));
        checkBox_2->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\245\275", 0));
        checkBox_3->setText(QApplication::translate("Widget", "\344\273\267\346\240\274\345\256\236\346\203\240", 0));
        checkBox_4->setText(QApplication::translate("Widget", "\350\200\201\346\235\277\345\250\230\345\245\275", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
