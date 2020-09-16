#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpReceiver; }
QT_END_NAMESPACE

class UdpReceiver : public QMainWindow
{
    Q_OBJECT

public:
    UdpReceiver(QWidget *parent = nullptr);
    ~UdpReceiver();


public slots:
    QString receive();

private:
    Ui::UdpReceiver *ui;
    QUdpSocket *uSocket;
};
#endif // UDPRECEIVER_H
