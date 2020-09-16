#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>
#include <iostream>
#include <QString>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "sql_server.h"

class udp : public QObject
{
    Q_OBJECT
public:
    explicit udp(QObject *parent = nullptr);
    QUdpSocket *uSocket;

public slots:
    void receive();
//    void readyRead();

signals:
//    void readyRead();
//    void udpreveive();
    void sendIC(QString);

};

#endif // UDP_H
