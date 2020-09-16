#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BaslerCamer.h"//添加封装类头文件
#include <udp.h>
#include <QTimer>
#include <QDateTime>
#include <QTextTable>
#include <QTextTableFormat>
#include <QScrollBar>
#include <QImage>
#include <QDebug>
#include "sql_server.h"
#include "my_modbus.h"
#include <QString>
#include <opencv2/opencv.hpp>
#include <dialog.h>
#include <setting.h>
#include "confirm.h"
#include "waterdi.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showIDmsg(QString msg,QString cardNum);
    void fail2find();
    void fail_send(QString);

private slots:
    void on_CameraStart_clicked();

    void on_CameraStop_clicked();

//    void on_Exp_Slider_valueChanged(int value);

//    void on_GainSlider_valueChanged(int value);

//    void on_Exp_Edit_textChanged();

//    void on_GainEdit_textChanged();

//    void on_Soft_checkBox_clicked();

//    void on_CSoftTrigger_clicked();

//    void on_ExtTrigcheckBox_clicked();


    void ShowImage(QImage img);//显示图像
    void timerUpdate(void);
    void onStatusInfo(QString msg);
    void MBTEST(cv::Mat image,int i);
//    void showIDmsg(QString msg,QString cardNum);
    void MB_not_ok();
    void MB_ok();
    void finish_MB_test_once(QImage img);
    void reciece_register_state(int address,quint16 value);
    void reciece_coil_state(int address, quint16 value);
    void detect_once(int i);
    void detect_process();
    void decode_sha();
    void camStop();
 //   void Init();
    void on_waterTest_clicked();
    void on_MB_clicked();
    cv::Mat QImageToMat(QImage image);
    int bSums(cv::Mat src);
    QImage Mat2QImage(cv::Mat mtx);
    void on_setting_clicked();
//    void processPendingDatagram();
    void  color_transfer_with_spilt( cv::Mat &input, std::vector<cv::Mat> &chls );
    void  color_retransfer_with_merge( cv::Mat &output, std::vector<cv::Mat> &chls );
    void timer_5s();
    void on_carIDconfirm_clicked();
//    void fail_send(QString);
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    BaslerCamer *B_camera;//封装类对象
    QTimer *timer;
    QTimer *mytimer;
    int m_status_count;
    udp *udpReiver;
//    sql_server *sqlread;
    my_modbus* my_test_bus;
    QList<QString> sha;
    int MB_outputs[3];
    bool Flag_MB_1;
    bool Flag_MB_2;
    bool Flag_water;
    QString ID;
    bool MB_result;
    bool MB_status_last;
    bool MB_status_cur;
    bool waterfinished;
    Dialog* dialog;
    Setting* set;
    QImage IMG;
    int click_MB_time;
    confirm* con;
    waterdi* water;




public:
    void timerEvent(QTimerEvent * event);//定时器事件
    int m_nTimerId;//定时器返回值
    sql_server *sqlread;
//    QDialog* dialog;
//    void showIDmsg(QString msg,QString cardNum);

};

#endif // MAINWINDOW_H
