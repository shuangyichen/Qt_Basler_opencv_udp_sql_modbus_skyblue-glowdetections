#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->login,SIGNAL(clicked()),this,SLOT(login()));
//    connect(ui->pushButton_2,SIGNAL(clicked()),qApp, SLOT(quit()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::login()
{
    if(ui->username->text().trimmed() == tr("JGWL") && ui->password->text() == tr("88888888"))
    {
//        set = new Setting(this);
//        set->setModal(true);
//        set->resize(600,1000);
//        set->show();
//        set->setAttribute(Qt::WA_DeleteOnClose);

        accept();//关闭窗体，并设置返回值为Accepted
    }
    else
    {                              //标题              内容                OK按钮
        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);       	// 清空输入框内容
        ui->username->clear();
        ui->password->clear();
        //光标定位
        ui->username->setFocus();
    }


}
