#include "udp.h"
#include "QDebug"

udp::udp(QObject *parent) : QObject(parent)
{
    const quint16 PORT = 60010;
    uSocket = new QUdpSocket;
    uSocket->bind(QHostAddress("192.168.0.73"), PORT);
    qDebug()<<"udp prepared";
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}
void udp::receive()
{
    using namespace std;
    stringstream inter;
    stringstream stream;
    string result;
    QByteArray ba;
    QString icNo;
//    sql_server sql;
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
//        QString s = "0259220538";  //test
//        qDebug()<<"num";
        emit sendIC(icNo);


//        std::cout << ba.data() << std::endl;
    }
}
