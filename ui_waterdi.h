/********************************************************************************
** Form generated from reading UI file 'waterdi.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATERDI_H
#define UI_WATERDI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waterdi
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *waterdi)
    {
        if (waterdi->objectName().isEmpty())
            waterdi->setObjectName(QString::fromUtf8("waterdi"));
        waterdi->resize(400, 300);
        widget_2 = new QWidget(waterdi);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 16, 382, 138));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        widget = new QWidget(waterdi);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 160, 382, 138));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirm_2 = new QPushButton(widget);
        confirm_2->setObjectName(QString::fromUtf8("confirm_2"));

        horizontalLayout->addWidget(confirm_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(waterdi);

        QMetaObject::connectSlotsByName(waterdi);
    } // setupUi

    void retranslateUi(QDialog *waterdi)
    {
        waterdi->setWindowTitle(QCoreApplication::translate("waterdi", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("waterdi", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\230\257\345\220\246\347\241\256\350\256\244\345\220\257\345\212\250\345\220\253\346\260\264\346\243\200\346\265\213\357\274\237</span></p></body></html>", nullptr));
        confirm_2->setText(QCoreApplication::translate("waterdi", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waterdi: public Ui_waterdi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATERDI_H
