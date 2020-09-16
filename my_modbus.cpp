#include "my_modbus.h"
#include <QModbusRtuSerialSlave>
#include <QModbusTcpServer>
#include <QDebug>
#include <QSettings>
#include <QLineEdit>
my_modbus::my_modbus(QObject *parent) : QObject(parent)
  , modbusDevice(nullptr)
{

}
my_modbus::~my_modbus()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;
}
void my_modbus::init()
{
    modbusDevice = new QModbusTcpServer();
    QModbusDataUnitMap reg;
    reg.insert(QModbusDataUnit::Coils, { QModbusDataUnit::Coils, 0, 50 });
    reg.insert(QModbusDataUnit::DiscreteInputs, { QModbusDataUnit::DiscreteInputs, 0, 50 });
    reg.insert(QModbusDataUnit::InputRegisters, { QModbusDataUnit::InputRegisters, 0, 50 });
    reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, 0, 50 });

    modbusDevice->setMap(reg);

    connect(modbusDevice, SIGNAL(dataWritten(QModbusDataUnit::RegisterType,int,int  )),
            this, SLOT(bus_dataWritten(QModbusDataUnit::RegisterType, int,int)));
    connect(modbusDevice, SIGNAL(stateChanged(QModbusDevice::State)),
            this, SLOT(bus_stateChanged(QModbusDevice::State)));
    connect(modbusDevice, SIGNAL(errorOccurred(QModbusDevice::Error)),
            this, SLOT(bus_errorOccurred(QModbusDevice::Error)));

    setupDeviceData();
//        modbusDevice->setValue(QModbusServer::ListenOnlyMode, toggled);
    //    if (modbusDevice)
//    if (modbusDevice)
//        modbusDevice->setValue(QModbusServer::DeviceBusy, toggled ? 0xffff : 0x0000);

    //
//    connect(ui->listenOnlyBox, &QCheckBox::toggled, this, [this](bool toggled) {
//        if (modbusDevice)
//            modbusDevice->setValue(QModbusServer::ListenOnlyMode, toggled);
//    });
//    emit ui->listenOnlyBox->toggled(ui->listenOnlyBox->isChecked());
//    connect(ui->setBusyBox, &QCheckBox::toggled, this, [this](bool toggled) {
//        if (modbusDevice)
//            modbusDevice->setValue(QModbusServer::DeviceBusy, toggled ? 0xffff : 0x0000);
//    });


}
int my_modbus::connect_bus()
{

    QSettings settings("MySoft","jgwl");

    QString IP=settings.value("editor/IP").toString();
    QString Port=settings.value("editor/Port").toString();
    QString serveraddress=settings.value("editor/serveraddress").toString();
    bool intendToConnect = (modbusDevice->state() == QModbusDevice::UnconnectedState);

    if (intendToConnect) {
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, QVariant(Port.toInt()));
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, QVariant(IP.toStdString().c_str()));
        modbusDevice->setServerAddress(serveraddress.toInt());
        qDebug()<<QString("IP %1 port %2 addres %3" ).arg(IP).arg(Port).arg(serveraddress);

//        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, QVariant(502));
//        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, QVariant("192.168.0.73"));

//        modbusDevice->setServerAddress(255);
        if (!modbusDevice->connectDevice()) {
            qDebug()<<(tr("Connect failed: ") + modbusDevice->errorString(), 5000)<<endl;
            emit send_fail(QString::fromLocal8Bit("modbus连接失败，请重启软件"));
        } else {
            qDebug()<<"modbus success"<<endl;
        }
    } else {
        modbusDevice->disconnectDevice();
        qDebug()<<"disconnect"<<endl;
        emit send_fail(QString::fromLocal8Bit("modbus连接失败，请重启软件"));
    }
    return 1;
}
int my_modbus::disconnect_bus()
{
    return 1;

}
void my_modbus::stop()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;

}

void my_modbus::bus_dataWritten(QModbusDataUnit::RegisterType table, int address, int size)
{
    QString str;
    int ret1;
//    qDebug()<<"data write."<<endl;
//    qDebug()<<size;
//    qDebug()<<address;
    for (int i = 0; i < size; ++i) {
        quint16 value;
        QString text;
        switch (table) {
        case QModbusDataUnit::Coils:
//            modbusDevice->data(QModbusDataUnit::Coils, address + i, &value);
            modbusDevice->data(QModbusDataUnit::Coils, address+i, &value);
            if(i==6)
            {
                //watch dog
                last_recieve_time=QTime::currentTime();
            }
//            else {
//                qDebug()<<"coil value "<<QString::number(value)<<endl;
//                emit get_coil_state(address + i,value);
                            emit get_coil_state(address+ i,value);
//            }
            break;
        case QModbusDataUnit::HoldingRegisters:
            modbusDevice->data(QModbusDataUnit::HoldingRegisters, address + i, &value);
//            qDebug()<<"address"<<QString::number(i)<<"HoldingRegister value "<<QString::number(value)<<endl;

            if(i%2==0)
            {
                high_s=value;
                high_hex = QString("%1").arg(high_s, 4, 16, QLatin1Char('0'));
            }
            if(i%2==1)
            {
                low_s=value;
                low_hex = QString("%1").arg(low_s, 4, 16, QLatin1Char('0'));

            QString s=high_hex+low_hex;

             str = QString("%1%2").arg(high_hex).arg(low_hex);
             bool ok;
            ret1=str.toInt(&ok,16);
            emit get_register_state(floor(i/2),ret1);
             }
//            QString s=high_hex+low_hex;

//             str = QString("%1%2").arg(high_hex).arg(low_hex);
//             bool ok;
//            ret1=str.toInt(&ok,16);
//            emit get_register_state(i,value);
            break;
        default:
            break;
        }
    }

}
void my_modbus::bus_stateChanged(QModbusDevice::State state)
{
    qDebug()<<"bus state changed";
    int i =state;

}
void my_modbus::bus_errorOccurred(QModbusDevice::Error newError)
{
    qDebug()<<"error modbus."<<endl;

}
void my_modbus::setupDeviceData()
{
    if (!modbusDevice)
        return;

    for (int i = 0; i < 10; ++i)
        modbusDevice->setData(QModbusDataUnit::Coils, i, false);

    for (int i = 0; i < 10; ++i) {

        modbusDevice->setData(QModbusDataUnit::DiscreteInputs, i,
            false);
    }
    bool ok;
    for(int i=0;i<10;i++)
    {
        QLineEdit *widget=new QLineEdit("1222222222222222222222222222222222222222");

            modbusDevice->setData(QModbusDataUnit::InputRegisters, i,widget->text().toInt(&ok, 16));

            modbusDevice->setData(QModbusDataUnit::HoldingRegisters, i,widget->text().toInt(&ok, 16));
    }

}

bool my_modbus::set_coil(int index,bool flag)
{
    if (!modbusDevice)
    {
        qDebug()<<"fail connect"<<endl;
        return false;
    }
    return modbusDevice->setData(QModbusDataUnit::Coils, index, flag);

}
bool my_modbus::set_discrete_input(int index,bool flag)
{
    if (!modbusDevice)
    {
        qDebug()<<"fail connect"<<endl;
        return false;
    }
    return modbusDevice->setData(QModbusDataUnit::DiscreteInputs, index, flag);

}
bool my_modbus::set_input_register(int index,int value)
{
    if (!modbusDevice)
    {
        qDebug()<<"fail connect"<<endl;
        return false;
    }
    return modbusDevice->setData(QModbusDataUnit::InputRegisters, index, value);
}
bool my_modbus::set_holding_register(int index,int value)
{
    if (!modbusDevice)
    {
        qDebug()<<"fail connect"<<endl;
        return false;
    }
    return modbusDevice->setData(QModbusDataUnit::InputRegisters, index, value);
}
