#include "udpreceiver.h"
#include "ui_udpreceiver.h"
#include <QByteArray>
#include <iostream>
#include <QString>
#include <iostream>
#include <sstream>
#include <iomanip>
const quint16 PORT = 60010;
UdpReceiver::UdpReceiver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UdpReceiver)
{
//    ui->setupUi(this);
    uSocket = new QUdpSocket;
    uSocket->bind(QHostAddress("192.168.0.73"), PORT);
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}

UdpReceiver::~UdpReceiver()
{
    delete ui;
}

QString UdpReceiver::receive()
{
    using namespace std;
    stringstream inter;
    stringstream stream;
    string result;
    QByteArray ba;
    QString icNo;
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        QString msg;
        bool ok;
        msg.append(ba.toHex());
        unsigned long long dec = msg.toLongLong(&ok, 16);
        stream << dec;
        stream >> result;
        inter << setw(10) << setfill('0') << result;
        inter >> result;  //result是字符串
        cout << result << endl;
        icNo = QString::fromStdString(result);
        return icNo;

//        std::cout << ba.data() << std::endl;
    }
}

