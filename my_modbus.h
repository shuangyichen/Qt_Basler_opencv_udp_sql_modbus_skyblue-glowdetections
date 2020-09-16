#ifndef MY_MODBUS_H
#define MY_MODBUS_H

#include <QObject>
#include <QModbusServer>
#include <QTime>
#include <QTimer>

class my_modbus : public QObject
{
    Q_OBJECT
public:
    explicit my_modbus(QObject *parent = nullptr);
    ~my_modbus();
    void init();
    int connect_bus();
    int disconnect_bus();
    void stop();


signals:
    void get_coil_state(int index,quint16 value);
    void get_register_state(int index,quint16 value);
    void send_fail(QString);

public slots:
    void bus_dataWritten(QModbusDataUnit::RegisterType table, int address, int size);
    void bus_stateChanged(QModbusDevice::State state);
    void bus_errorOccurred(QModbusDevice::Error newError);
    bool set_coil(int index,bool flag);
    bool set_discrete_input(int index,bool flag);
    bool set_input_register(int index,int value);
    bool set_holding_register(int index,int value);


private:
    QModbusServer *modbusDevice;
    void setupDeviceData();
    QTime last_recieve_time;
    int last_recieve_number=0;
    QTimer *timer_watchdog;
    int low_s,high_s;
    QString low_hex,high_hex;

};

#endif // MY_MODBUS_H
