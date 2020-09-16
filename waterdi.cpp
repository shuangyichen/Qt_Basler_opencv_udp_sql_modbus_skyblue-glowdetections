#include "waterdi.h"
#include "ui_waterdi.h"

waterdi::waterdi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waterdi)
{
    ui->setupUi(this);
    connect(ui->confirm_2,SIGNAL(clicked()),this,SLOT(yes()));
}

waterdi::~waterdi()
{
    delete ui;
}

void waterdi::yes()
{
    accept();
}

