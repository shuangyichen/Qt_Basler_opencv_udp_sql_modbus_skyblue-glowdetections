#include "setting.h"
#include "ui_setting.h"
#include <QSettings>

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    Load_Setting();
}

Setting::~Setting()
{
    delete ui;
}



void Setting::Load_Setting()
{
    QSettings settings("MySoft","jgwl");

    QString IP=settings.value("editor/IP").toString();
    QString Port=settings.value("editor/Port").toString();
    QString serveraddress=settings.value("editor/serveraddress").toString();
    QString log_path=settings.value("editor/log_path").toString();

    ui->lineEdit_IP->setText(IP);
    ui->lineEdit_Port->setText(Port);
    ui->lineEdit_serveraddress->setText(serveraddress);
    ui->lineEdit_log_path->setText(log_path);

}
void Setting::Save_Setting()
{
    QSettings settings("MySoft","jgwl");
    settings.setValue("editor/IP",ui->lineEdit_IP->text());
    settings.setValue("editor/Port",ui->lineEdit_Port->text());
    settings.setValue("editor/serveraddress",ui->lineEdit_serveraddress->text());
    settings.setValue("editor/log_path",ui->lineEdit_log_path->text());
}


void Setting::on_buttonBox_accepted()
{
    Save_Setting();
}
