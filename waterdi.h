#ifndef WATERDI_H
#define WATERDI_H

#include <QDialog>

namespace Ui {
class waterdi;
}

class waterdi : public QDialog
{
    Q_OBJECT

public:
    explicit waterdi(QWidget *parent = nullptr);
    ~waterdi();

public slots:
    void yes();

private:
    Ui::waterdi *ui;
};

#endif // WATERDI_H
