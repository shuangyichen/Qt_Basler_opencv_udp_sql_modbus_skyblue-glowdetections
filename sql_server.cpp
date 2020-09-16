#include "sql_server.h"
#include <QDebug>
#include "mainwindow.h"

sql_server::sql_server(QObject *parent) : QObject(parent)
{
    qDebug()<<"sql prepared";
}

void sql_server::ReadData(QString IC)
{
//    qDebug()<<"?";
//    MainWindow main;
    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<"?";

    // 建立连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("JG_XC16");
    db.setUserName("zjuser");
    db.setPassword("zj100");

    if(!db.open())
    {
        qDebug("=== %s","error");
    }else
    {
        qDebug("==== ok");
    }

    QSqlQuery query;

//    query.prepare( “insert into student (id, name) ”
//                      “values (:id, :name) ”);
//    query.bindValue(0, 5);
//    query.bindValue(1, “sixth ”);
    query.prepare("SELECT TOP (1) * FROM [JG_XC16].[dbo].[View_Interface_CRPM_QC_MateSamplingInspection] where s_ic=? order by InputDateTime desc");
//    query.prepare("select top 1 * from [dbo].[View_Interface_CRPM_QC_MateSamplingInspection] where s_ic=? order by InputDateTime desc");
    query.addBindValue(IC);

    query.exec();

    while(query.next())
    // 开始就先执行一次next() 函数，那么query 指向结果集的第一条记录
    {
        qDebug()<<"4";
//            int rowNum = query.at();
            // 获取query 所指向的记录在结果集中的编号
//            int columnNum = query.record().count();
            // 获取每条记录中属性（即列）的个数
//            int fieldNo = query.record().indexOf( "name");
            // 获取 ” name ”属性所在列的编号，列从左向右编号，最左边的编号为 0
//           Qstring carNo = query.value(3).toInt();
           QString carNo = query.value(2).toString();
            // 获取id 属性的值，并转换为int 型
           QString sampleNo = query.value(1).toString();
           QString provider = query.value(4).toString();
           QString materials = query.value(5).toString();
           QString ID = query.value(0).toString();
            // 获取name 属性的值
           QStringList msg;
           msg << carNo << sampleNo << provider << materials <<ID;
           QString str = msg.join(",");
//           emit main.showIDmsg(str,IC);
//           return str;
            qDebug() << "carNo is : "<< carNo // 将结果输出
                    << "sampleNo is : "<< sampleNo
                    << "provider is : "<< provider
                    << " materials is : "<< materials;
            emit send_signal(str,IC);
//            emit send_signal("1","2");
//           return str;
    }
    qDebug()<<"5";
//    return IC;

}


void sql_server::ReadDatathroughcarID(QString carID)
{
//    qDebug()<<"?";
//    MainWindow main;
    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<"?";

    // 建立连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("JG_XC16");
    db.setUserName("zjuser");
    db.setPassword("zj100");

    if(!db.open())
    {
        qDebug("=== %s","error");
    }else
    {
        qDebug("==== ok");
    }

    QSqlQuery query3;

//    query.prepare( “insert into student (id, name) ”
//                      “values (:id, :name) ”);
//    query.bindValue(0, 5);
//    query.bindValue(1, “sixth ”);
    query3.prepare("SELECT TOP (1) * FROM [JG_XC16].[dbo].[View_Interface_CRPM_QC_MateSamplingInspection] where CarNo=? order by InputDateTime desc");
//    query.prepare("select top 1 * from [dbo].[View_Interface_CRPM_QC_MateSamplingInspection] where s_ic=? order by InputDateTime desc");
    query3.addBindValue(carID);

    query3.exec();

    if(query3.exec())
    // 开始就先执行一次next() 函数，那么query 指向结果集的第一条记录
    {
        while(query3.next()){


//            int rowNum = query.at();
            // 获取query 所指向的记录在结果集中的编号
//            int columnNum = query.record().count();
            // 获取每条记录中属性（即列）的个数
//            int fieldNo = query.record().indexOf( "name");
            // 获取 ” name ”属性所在列的编号，列从左向右编号，最左边的编号为 0
//           Qstring carNo = query.value(3).toInt();
//           QString carNo = query3.value(2).toString();
            // 获取id 属性的值，并转换为int 型
           QString sampleNo = query3.value(1).toString();
           QString provider = query3.value(4).toString();
           QString materials = query3.value(5).toString();
           QString ID = query3.value(0).toString();
           QString IC = query3.value(3).toString();
            // 获取name 属性的值
           QStringList msg;
           msg << carID << sampleNo << provider << materials <<ID;
           QString str = msg.join(",");
//           emit main.showIDmsg(str,IC);
//           return str;
            qDebug() << "carNo is : "<< carID // 将结果输出
                    << "sampleNo is : "<< sampleNo
                    << "provider is : "<< provider
                    << " materials is : "<< materials;
            emit send_signal(str,IC);
        }
//            emit send_signal("1","2");
//           return str;
    }
    else{
        emit send_fail_signal();
    }
    qDebug()<<"5";
//    return IC;

}

void sql_server::Writetest1()
{
    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<QSqlDatabase::drivers();


    // 建立连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("JG_XC16");
    db.setUserName("zjuser");
    db.setPassword("zj100");
    if(!db.open())
    {
        qDebug("=== %s","error");
    }else
    {
        qDebug("==== ok");
    }

    QSqlQuery query2;
    query2.prepare("SELECT * FROM [JG_XC16].[dbo].[CRPM_QC_MateSamplingInspection_Detection] where CQMIID=?");
    query2.addBindValue(QString("52DAE17F-A9F7-4983-8CE8-D6471100AA70"));
    query2.exec();
    if(query2.first())
    {
        qDebug()<<"1111111111";
    }
    else{
        qDebug()<<"2222222";
    }

}

void sql_server::WriteTest(QString ID,QString wet,QString dry,QString sha1,QString sha2,QString sha3,QString sha4,QString sha5,QString sha6,QString sha7,QString sha8)
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    double Wet = (double)wet.toDouble();
    double Dry = (double)dry.toDouble();
    double Sha1 = (double)sha1.toDouble();
    double Sha2 = (double)sha2.toDouble();
    double Sha3 = (double)sha3.toDouble();
    double Sha4 = (double)sha4.toDouble();
    double Sha5 = (double)sha5.toDouble();
    double Sha6 = (double)sha6.toDouble();
    double Sha7 = (double)sha7.toDouble();
    double Sha8 = (double)sha8.toDouble();
//    double Sha9 = (double)sha9.toDouble()/100;
    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<"?";

    // 建立连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("JG_XC16");
    db.setUserName("zjuser");
    db.setPassword("zj100");
    if(!db.open())
    {
        qDebug("=== %s","error");
    }else
    {
        qDebug("==== ok");
    }
    QSqlQuery query2;
    query2.prepare("SELECT * FROM [JG_XC16].[dbo].[CRPM_QC_MateSamplingInspection_Detection] where CQMIID=?");
    query2.addBindValue(ID);

    query2.exec();
    if (query2.first())
    {
        QSqlQuery query7;
        QString ss = QString("UPDATE [dbo].[CRPM_QC_MateSamplingInspection_Detection] SET WetWeight=:ww,DryWeight=:dw,shai1=:sha1,shai2=:sha2,shai3=:sha3,shai4=:sha4,shai5=:sha5,shai6=:sha6,shai7=:sha7,shai8=:sha8,JudgeDateTime=:time where CQMIID='%1' ").arg(ID);
        query7.prepare(ss);
        query7.bindValue(":ww",Wet);
        query7.bindValue(":dw",Dry);
        query7.bindValue(":sha1",Sha1);
        query7.bindValue(":sha2",Sha2);
        query7.bindValue(":sha3",Sha3);
        query7.bindValue(":sha4",Sha4);
        query7.bindValue(":sha5",Sha5);
        query7.bindValue(":sha6",Sha6);
        query7.bindValue(":sha7",Sha7);
        query7.bindValue(":sha8",Sha8);
//        query7.bindValue(":sha9",Sha9);
        query7.bindValue(":time",time);
        query7.exec();
        qDebug()<<"Update finished";
    }
    else
    {
        QSqlQuery query1;
        query1.prepare("INSERT INTO [dbo].[CRPM_QC_MateSamplingInspection_Detection](CQMIID,WetWeight,DryWeight,shai1,shai2,shai3,shai4,shai5,shai6,shai7,shai8,JudgeDateTime)VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
        query1.addBindValue(ID);
        query1.addBindValue(Wet);
        query1.addBindValue(Dry);
        query1.addBindValue(Sha1);
        query1.addBindValue(Sha2);
        query1.addBindValue(Sha3);
        query1.addBindValue(Sha4);
        query1.addBindValue(Sha5);
        query1.addBindValue(Sha6);
        query1.addBindValue(Sha7);
        query1.addBindValue(Sha8);
//        query1.addBindValue(Sha9);
        query1.addBindValue(time);

        query1.exec();
        qDebug()<<"insert finished";
    }
}

void sql_server::WriteData(QString ID,bool MB,QImage IMG,QImage img)
{


    int MB_result;
    if (MB)
    {
        MB_result = 1;//QString::fromLocal8Bit("合格");
    }
    else
    {
        MB_result = 0;//QString("不合格");
    }

    //pic from QImage to base64
    QImage newIMG = IMG.scaled(400,400);
    QImage newimg = img.scaled(400,400);
    QByteArray ba;
    QBuffer buf(&ba);
    newimg.save(&buf, "bmp");
    QString hexed = ba.toBase64();
    buf.close();
    QByteArray ba1;
    QBuffer buf1(&ba1);
    newIMG.save(&buf1, "bmp");
    QString hexed1 = ba1.toBase64();
    buf1.close();

    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");



    // 建立连接
    qDebug()<<QSqlDatabase::drivers();
//    qDebug()<<QSqlDatabase::drivers();


    // 建立连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("JG_XC16");
    db.setUserName("zjuser");
    db.setPassword("zj100");
    if(!db.open())
    {
        qDebug("=== %s","error");
    }else
    {
        qDebug("==== ok");
    }



    QSqlQuery query5;
    query5.prepare("SELECT * FROM [JG_XC16].[dbo].[CRPM_QC_MateSamplingInspection_Detection] where CQMIID=?");
    query5.addBindValue(ID);

    query5.exec();


    if(query5.first())
    // 开始就先执行一次next() 函数，那么query 指向结果集的第一条记录
    {
        QSqlQuery query2;
        QString ss = QString("UPDATE [dbo].[CRPM_QC_MateSamplingInspection_Detection] SET MudJudge=:mj,MudImg=:mi,MudImg3D=:mi3d,JudgeDateTime=:jdt where CQMIID='%1' ").arg(ID);
        query2.prepare(ss);

        query2.bindValue(":mj",MB_result);
        query2.bindValue("mi",hexed1);
        query2.bindValue("mi3d",hexed);
        query2.bindValue("jdt",time);
    //    query.addBindValue(ID);   //QString 转换 uniqueidentifier?
        query2.exec();
        qDebug()<<"Update finished";
    }
    else{
        QSqlQuery query1;
        query1.prepare("INSERT INTO [dbo].[CRPM_QC_MateSamplingInspection_Detection](CQMIID,MudJudge,MudImg,MudImg3D,JudgeDateTime)VALUES(?,?,?,?,?)");
        query1.addBindValue(ID);
        query1.addBindValue(MB_result);
        query1.addBindValue(hexed1);
        query1.addBindValue(hexed);
        query1.addBindValue(time);
        query1.exec();

        qDebug()<<"Insert finished";

    }


}
