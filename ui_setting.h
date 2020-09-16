/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_Port;
    QLineEdit *lineEdit_serveraddress;
    QLineEdit *lineEdit_log_path;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QString::fromUtf8("Setting"));
        Setting->resize(284, 232);
        layoutWidget = new QWidget(Setting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 243, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_IP = new QLineEdit(layoutWidget);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        verticalLayout_2->addWidget(lineEdit_IP);

        lineEdit_Port = new QLineEdit(layoutWidget);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));

        verticalLayout_2->addWidget(lineEdit_Port);

        lineEdit_serveraddress = new QLineEdit(layoutWidget);
        lineEdit_serveraddress->setObjectName(QString::fromUtf8("lineEdit_serveraddress"));

        verticalLayout_2->addWidget(lineEdit_serveraddress);

        lineEdit_log_path = new QLineEdit(layoutWidget);
        lineEdit_log_path->setObjectName(QString::fromUtf8("lineEdit_log_path"));

        verticalLayout_2->addWidget(lineEdit_log_path);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QCoreApplication::translate("Setting", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Setting", "IP\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("Setting", "\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("Setting", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        label_6->setText(QCoreApplication::translate("Setting", "\346\227\245\345\277\227\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
