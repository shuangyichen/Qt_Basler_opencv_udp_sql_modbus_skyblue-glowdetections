#include "confirm.h"
#include "ui_confirm.h"

confirm::confirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirm)
{
    ui->setupUi(this);
    connect(ui->confirm_2,SIGNAL(clicked()),this,SLOT(yes()));
//    connect(ui->cancel,SIGNAL(clicked()),qApp, SLOT(quit()));

}

confirm::~confirm()
{
    delete ui;
}

void confirm::yes()
{
    accept();
}
