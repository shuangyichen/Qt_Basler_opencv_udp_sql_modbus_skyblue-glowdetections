#ifndef SQL_SERVER_H
#define SQL_SERVER_H

#include <QObject>
#include "QtSql/QSqlDatabase"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QBuffer>

class sql_server : public QObject
{
    Q_OBJECT

public slots:
    void ReadData(QString IC);
    void ReadDatathroughcarID(QString carID);

public:
    explicit sql_server(QObject *parent = nullptr);
//    void ReadData(QString IC);
    void WriteTest(QString ID,QString wet,QString dry,QString sha1,QString sha2,QString sha3,QString sha4,QString sha5,QString sha6,QString sha7,QString sha8);
    void WriteData(QString ID,bool MB,QImage IMG,QImage img);
    void Writetest1();

signals:
    void send_signal(QString,QString);
    void send_fail_signal();

};

#endif // SQL_SERVER_H
