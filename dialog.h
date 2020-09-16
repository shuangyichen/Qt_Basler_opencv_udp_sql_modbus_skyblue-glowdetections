#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <setting.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:

    void login();


private:
    Ui::Dialog *ui;
    Setting* set;
};

#endif // DIALOG_H
