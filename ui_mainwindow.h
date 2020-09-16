/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *MB;
    QLabel *Imagelabel;
    QWidget *top;
    QHBoxLayout *horizontalLayout;
    QLabel *Title;
    QSpacerItem *horizontalSpacer;
    QLabel *timeUpdate;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *setting;
    QPushButton *CameraStop;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *MBwronglight;
    QLabel *MBwrong;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *waterrunlight;
    QLabel *waterrun;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *waterpreparedlight;
    QLabel *waterprepared;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *MBpreparedlight;
    QLabel *MBprepared;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *MBrunlight;
    QLabel *MBrun;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *waterwronglight;
    QLabel *waterwrong;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *output;
    QPushButton *waterTest;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *LPNum;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *sampleNumber;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *name;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *materials;
    QPushButton *carIDconfirm;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1917, 1092);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MB = new QPushButton(centralWidget);
        MB->setObjectName(QString::fromUtf8("MB"));
        MB->setGeometry(QRect(1500, 520, 141, 51));
        Imagelabel = new QLabel(centralWidget);
        Imagelabel->setObjectName(QString::fromUtf8("Imagelabel"));
        Imagelabel->setGeometry(QRect(40, 150, 831, 481));
        Imagelabel->setFrameShape(QFrame::Panel);
        top = new QWidget(centralWidget);
        top->setObjectName(QString::fromUtf8("top"));
        top->setGeometry(QRect(10, 10, 1901, 121));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(top->sizePolicy().hasHeightForWidth());
        top->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(top);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Title = new QLabel(top);
        Title->setObjectName(QString::fromUtf8("Title"));

        horizontalLayout->addWidget(Title);

        horizontalSpacer = new QSpacerItem(307, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        timeUpdate = new QLabel(top);
        timeUpdate->setObjectName(QString::fromUtf8("timeUpdate"));

        horizontalLayout->addWidget(timeUpdate);

        horizontalSpacer_2 = new QSpacerItem(306, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        setting = new QPushButton(top);
        setting->setObjectName(QString::fromUtf8("setting"));

        horizontalLayout->addWidget(setting);

        CameraStop = new QPushButton(top);
        CameraStop->setObjectName(QString::fromUtf8("CameraStop"));

        horizontalLayout->addWidget(CameraStop);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(220, 640, 1241, 181));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        MBwronglight = new QLabel(widget_8);
        MBwronglight->setObjectName(QString::fromUtf8("MBwronglight"));

        horizontalLayout_6->addWidget(MBwronglight);

        MBwrong = new QLabel(widget_8);
        MBwrong->setObjectName(QString::fromUtf8("MBwrong"));

        horizontalLayout_6->addWidget(MBwrong);


        gridLayout->addWidget(widget_8, 2, 4, 1, 1);

        widget_11 = new QWidget(widget_2);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_11->sizePolicy().hasHeightForWidth());
        widget_11->setSizePolicy(sizePolicy1);
        horizontalLayout_9 = new QHBoxLayout(widget_11);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        waterrunlight = new QLabel(widget_11);
        waterrunlight->setObjectName(QString::fromUtf8("waterrunlight"));
        sizePolicy1.setHeightForWidth(waterrunlight->sizePolicy().hasHeightForWidth());
        waterrunlight->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(waterrunlight);

        waterrun = new QLabel(widget_11);
        waterrun->setObjectName(QString::fromUtf8("waterrun"));

        horizontalLayout_9->addWidget(waterrun);


        gridLayout->addWidget(widget_11, 0, 0, 2, 1);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        waterpreparedlight = new QLabel(widget_9);
        waterpreparedlight->setObjectName(QString::fromUtf8("waterpreparedlight"));
        sizePolicy1.setHeightForWidth(waterpreparedlight->sizePolicy().hasHeightForWidth());
        waterpreparedlight->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(waterpreparedlight);

        waterprepared = new QLabel(widget_9);
        waterprepared->setObjectName(QString::fromUtf8("waterprepared"));

        horizontalLayout_7->addWidget(waterprepared);


        gridLayout->addWidget(widget_9, 0, 2, 2, 1);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        MBpreparedlight = new QLabel(widget_10);
        MBpreparedlight->setObjectName(QString::fromUtf8("MBpreparedlight"));
        sizePolicy1.setHeightForWidth(MBpreparedlight->sizePolicy().hasHeightForWidth());
        MBpreparedlight->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(MBpreparedlight);

        MBprepared = new QLabel(widget_10);
        MBprepared->setObjectName(QString::fromUtf8("MBprepared"));

        horizontalLayout_8->addWidget(MBprepared);


        gridLayout->addWidget(widget_10, 2, 2, 1, 1);

        widget_12 = new QWidget(widget_2);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_10 = new QHBoxLayout(widget_12);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        MBrunlight = new QLabel(widget_12);
        MBrunlight->setObjectName(QString::fromUtf8("MBrunlight"));

        horizontalLayout_10->addWidget(MBrunlight);

        MBrun = new QLabel(widget_12);
        MBrun->setObjectName(QString::fromUtf8("MBrun"));

        horizontalLayout_10->addWidget(MBrun);


        gridLayout->addWidget(widget_12, 2, 0, 1, 1);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        waterwronglight = new QLabel(widget);
        waterwronglight->setObjectName(QString::fromUtf8("waterwronglight"));
        sizePolicy1.setHeightForWidth(waterwronglight->sizePolicy().hasHeightForWidth());
        waterwronglight->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(waterwronglight);

        waterwrong = new QLabel(widget);
        waterwrong->setObjectName(QString::fromUtf8("waterwrong"));

        horizontalLayout_5->addWidget(waterwrong);


        gridLayout->addWidget(widget, 0, 4, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        output = new QTextEdit(centralWidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(10, 840, 1901, 181));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(output->sizePolicy().hasHeightForWidth());
        output->setSizePolicy(sizePolicy2);
        waterTest = new QPushButton(centralWidget);
        waterTest->setObjectName(QString::fromUtf8("waterTest"));
        waterTest->setGeometry(QRect(1030, 520, 151, 51));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(1000, 150, 731, 351));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        LPNum = new QLineEdit(widget_4);
        LPNum->setObjectName(QString::fromUtf8("LPNum"));

        gridLayout_2->addWidget(LPNum, 0, 1, 1, 1);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(widget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        sampleNumber = new QLabel(widget_5);
        sampleNumber->setObjectName(QString::fromUtf8("sampleNumber"));

        horizontalLayout_2->addWidget(sampleNumber);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        name = new QLabel(widget_6);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_3->addWidget(name);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        materials = new QLabel(widget_7);
        materials->setObjectName(QString::fromUtf8("materials"));

        horizontalLayout_4->addWidget(materials);


        verticalLayout->addWidget(widget_7);

        carIDconfirm = new QPushButton(centralWidget);
        carIDconfirm->setObjectName(QString::fromUtf8("carIDconfirm"));
        carIDconfirm->setGeometry(QRect(1740, 170, 101, 51));
        MainWindow->setCentralWidget(centralWidget);
        MB->raise();
        Imagelabel->raise();
        top->raise();
        output->raise();
        waterTest->raise();
        widget_3->raise();
        widget_2->raise();
        carIDconfirm->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MB->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250MB\345\200\274\345\210\244\345\256\232", nullptr));
        Imagelabel->setText(QString());
        Title->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600;\">\345\205\254\351\261\274\344\272\222\350\201\224\345\234\260\346\235\220\350\264\250\351\207\217\346\243\200\346\265\213</span></p></body></html>", nullptr));
        timeUpdate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">time</span></p></body></html>", nullptr));
        setting->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        CameraStop->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        MBwronglight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        MBwrong->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">MB\345\200\274\345\210\244\345\256\232\346\225\205\351\232\234</span></p></body></html>", nullptr));
        waterrunlight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        waterrun->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\220\253\346\260\264\345\217\212\351\242\227\347\262\222\347\272\247\351\205\215\346\243\200\346\265\213\350\277\220\350\241\214</span></p></body></html>", nullptr));
        waterpreparedlight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        waterprepared->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\220\253\346\260\264\345\217\212\351\242\227\347\262\222\347\272\247\351\205\215\346\243\200\346\265\213\345\244\207\345\246\245</span></p></body></html>", nullptr));
        MBpreparedlight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        MBprepared->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">MB\345\200\274\345\210\244\345\256\232\345\244\207\345\246\245</span></p></body></html>", nullptr));
        MBrunlight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        MBrun->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">MB\345\200\274\345\210\244\345\256\232\350\277\220\350\241\214</span></p></body></html>", nullptr));
        waterwronglight->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        waterwrong->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\220\253\346\260\264\345\217\212\351\242\227\347\262\222\347\272\247\351\205\215\346\243\200\346\265\213\346\225\205\351\232\234</span></p></body></html>", nullptr));
        waterTest->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\345\220\253\346\260\264\345\217\212\347\272\247\351\205\215\346\243\200\346\265\213", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">\350\275\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        LPNum->setText(QCoreApplication::translate("MainWindow", "\346\270\235", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">\346\212\275\346\243\200\347\274\226\345\217\267\357\274\232</span></p></body></html>", nullptr));
        sampleNumber->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">\344\276\233\345\225\206\345\220\215\347\247\260\357\274\232</span></p></body></html>", nullptr));
        name->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">\345\234\260\346\235\220\345\220\215\347\247\260:</span></p></body></html>", nullptr));
        materials->setText(QString());
        carIDconfirm->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\350\275\246\347\211\214\345\217\267\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
