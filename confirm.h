﻿#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>

namespace Ui {
class confirm;
}

class confirm : public QDialog
{
    Q_OBJECT

public:
    explicit confirm(QWidget *parent = nullptr);
    ~confirm();
public slots:
    void yes();

private:
    Ui::confirm *ui;
};

#endif // CONFIRM_H
