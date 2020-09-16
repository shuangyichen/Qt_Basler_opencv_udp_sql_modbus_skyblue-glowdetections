#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "BaslerCamer.h"
#include <QSettings>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_status_count = 0;
    Flag_MB_1 = false;
    Flag_MB_2 = false;
    Flag_water = false;
    QString one="0";
    sha<<one<<one<<one<<one<<one<<one<<one<<one<<one<<one<<one<<one;


//    B_camera = new BaslerCamer();//实例化封装类
    udpReiver = new udp();
    sqlread = new sql_server();
    connect(udpReiver,SIGNAL(sendIC(QString)),sqlread,SLOT(ReadData(QString)));
    connect(sqlread,SIGNAL(send_signal(QString,QString)),this,SLOT(showIDmsg(QString,QString)));
    connect(sqlread,SIGNAL(send_fail_signal()),this,SLOT(fail2find()));
//    B_camera->CamInit();//相机初始化
    timer = new QTimer(this);
    QFont ft;//*("Microsoft YaHei", 14, 75);
    ft.setPointSize(26);
    ft.setBold(75);
    ui->Title->setFont(ft);
    ui->timeUpdate->setFont(ft);
    QFont ft1;
    ft1.setPointSize(20);
    ft1.setBold(75);
    ui->setting->setFont(ft1);
    ui->setting->setFixedSize(200,70);
    ui->setting->setStyleSheet("background: rgb(139,137,137)");
    ui->CameraStop->setFont(ft1);
    ui->CameraStop->setFixedSize(200,70);
    ui->CameraStop->setStyleSheet("background: rgb(139,137,137)");
    ui->waterTest->setFont(ft1);
    ui->waterTest->setFixedSize(300,100);
    ui->waterTest->setStyleSheet("background: rgb(139,137,137)");
    ui->MB->setFont(ft1);
    ui->MB->setFixedSize(300,100);
    ui->MB->setStyleSheet("background: rgb(139,137,137)");

    QPixmap myPix(":/main/1.png");
    ui->Imagelabel->setPixmap(myPix);
    ui->Imagelabel->setScaledContents(true);

    QPixmap greenoff(":/light/light/greenoff.jpg");
    ui->waterrunlight->setPixmap(greenoff);
    ui->waterrunlight->setFixedSize(60,60);
    ui->waterrunlight->setScaledContents(true);
    ui->MBrunlight->setPixmap(greenoff);
    ui->MBrunlight->setFixedSize(60,60);
    ui->MBrunlight->setScaledContents(true);
    ui->waterpreparedlight->setPixmap(greenoff);
    ui->waterpreparedlight->setFixedSize(60,60);
    ui->waterpreparedlight->setScaledContents(true);
    ui->MBpreparedlight->setPixmap(greenoff);
    ui->MBpreparedlight->setFixedSize(60,60);
    ui->MBpreparedlight->setScaledContents(true);
    QPixmap redoff(":/light/light/redoff.jpg");
    ui->waterwronglight->setPixmap(redoff);
    ui->waterwronglight->setFixedSize(60,60);
    ui->waterwronglight->setScaledContents(true);
    ui->MBwronglight->setPixmap(redoff);
    ui->MBwronglight->setFixedSize(60,60);
    ui->MBwronglight->setScaledContents(true);


    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    ui->top->setAutoFillBackground(true);
    ui->top->setPalette(pal);
    QPalette pl;
    pl.setColor(QPalette::Background, Qt::white);
    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(pl);
    ui->output->setReadOnly(true);

    QPalette label_palette;
//    label_palette.setColor(QPalette::Background,Qt::black);
    label_palette.setColor(QPalette::Background, QColor("white"));
    QFont ft2;
    ft2.setPointSize(18);
    ft2.setBold(75);
    QFont ft3;
    ft3.setPointSize(14);
//    ft3.setBold(75);
    ui->LPNum->setAutoFillBackground(true);
    ui->LPNum->setPalette(label_palette);
    ui->LPNum->setStyleSheet("QLabel{border:1px solid rgb(0, 0, 0);}");
    ui->LPNum->setFixedSize(400,60);
    ui->LPNum->setFont(ft2);
    ui->materials->setAutoFillBackground(true);
    ui->materials->setPalette(label_palette);
    ui->materials->setFixedSize(400,60);
    ui->materials->setFont(ft2);
    ui->materials->setStyleSheet("QLabel{border:1px solid rgb(0, 0, 0);}");
    ui->name->setAutoFillBackground(true);
    ui->name->setPalette(label_palette);
    ui->name->setFixedSize(400,60);
    ui->name->setFont(ft2);
    ui->name->setStyleSheet("QLabel{border:1px solid rgb(0, 0, 0);}");
    ui->sampleNumber->setAutoFillBackground(true);
    ui->sampleNumber->setPalette(label_palette);
    ui->sampleNumber->setFixedSize(400,60);
    ui->sampleNumber->setStyleSheet("QLabel{border:1px solid rgb(0, 0, 0);}");
    ui->sampleNumber->setFont(ft2);
    ui->carIDconfirm->setFont(ft3);
    ui->carIDconfirm->setFixedSize(160,60);

    //读卡
//    connect(udpReiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
//    modbus初始化
    my_test_bus=new my_modbus();
    connect(my_test_bus,SIGNAL(get_coil_state(int,quint16)),this,SLOT(reciece_coil_state(int,quint16)));
    connect(my_test_bus,SIGNAL(get_register_state(int,quint16)),this,SLOT(reciece_register_state(int,quint16)));
    connect(my_test_bus,SIGNAL(send_fail(QString)),this,SLOT(fail_send(QString)));
    my_test_bus->init();
    my_test_bus->connect_bus();
//    connect(my_test_bus,SIGNAL(send_fail(QString)),this,SLOT(fail_send(QString)));

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
//    set = new Setting(this);
//    set->resize(300,200);
//    set->setModal(true);
//    set->setAttribute(Qt::WA_DeleteOnClose);
//    dialog = new Dialog(this);
//    dialog->setModal(true);
//    dialog->resize(300,200);
//    dialog->setAttribute(Qt::WA_DeleteOnClose);

    B_camera = new BaslerCamer();
    connect(B_camera, SIGNAL(ShowImageSignal(QImage)), this, SLOT(ShowImage(QImage)));
    connect(B_camera, SIGNAL(camera_abnormal(QString)), this, SLOT(fail_send(QString)));
    B_camera->CamInit();//相机初始化

//    connect(B_camera, SIGNAL(ShowImageSignal(QImage)), this, SLOT(ShowImage(QImage)));
//    connect(B_camera, SIGNAL(camera_abnormal(QString)), this, SLOT(fail_send(QString)));
////    m_nTimerId = startTimer(100);
//    qDebug()<<"1";

    QSettings settings("MySoft","jgwl");
    settings.setValue("editor/IP","192.168.0.73");
    settings.setValue("editor/Port",502);
    settings.setValue("editor/serveraddress",255);



    MB_status_last = false;
    MB_status_cur = false;
    waterfinished = false;
    click_MB_time =0;

 }

MainWindow::~MainWindow()
{
//    B_camera->CamDestroy();//退出时关闭相机

    if(B_camera->camera.IsGrabbing())
    {
        B_camera->CamStop();
    }
B_camera->CamStop();
     B_camera->CamDestroy();

    delete ui;
}
void MainWindow::fail_send(QString msg)
{
    onStatusInfo(msg);
}

void MainWindow::timer_5s()
{
    click_MB_time = 0;
}
void MainWindow::fail2find()
{
    QString s=QString::fromLocal8Bit("未查找到该车牌号相关信息");
    onStatusInfo(s);
}


void MainWindow::on_setting_clicked()
{
//    dialog = new Dialog(this);
//    dialog->setModal(true);
//    dialog->resize(300,200);
    dialog = new Dialog(this);
    dialog->setModal(true);
    dialog->resize(300,200);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
        if (dialog->exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
        {
            set = new Setting(this);
            set->resize(300,200);
            set->setModal(true);
            set->setAttribute(Qt::WA_DeleteOnClose);
            set->show();

            }
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
}


void MainWindow::on_carIDconfirm_clicked()
{
    QString carID = ui->LPNum->text();
    qDebug()<<carID;
    sqlread->ReadDatathroughcarID(carID);
}
void MainWindow::on_CameraStart_clicked()
{
//    Init();

}
void MainWindow::on_MB_clicked()
{


    if(Flag_MB_1==true)
    {
        con = new confirm(this);
        con->resize(300,200);
        con->setModal(true);
        con->setAttribute(Qt::WA_DeleteOnClose);
         con->show();
         if (con->exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
         {
             QPixmap greenoff(":/light/light/greenoff.jpg");
             ui->MBpreparedlight->setPixmap(greenoff);

             QPixmap greenon(":/light/light/greenon.jpg");
             ui->MBrunlight->setPixmap(greenon);

             my_test_bus->set_discrete_input(0,true);
             QString s=QString::fromLocal8Bit("启动MB值快速判定");
             onStatusInfo(s);

             }
    }
    else{
            QString s2=QString::fromLocal8Bit("系统未备妥");
            onStatusInfo(s2);
        }
}

void MainWindow::on_pushButton_clicked()
{
    sqlread->Writetest1();
}


void MainWindow::on_waterTest_clicked()
{
//    sqlread->ReadData("123");

//    sqlread->WriteTest();

    if(Flag_water)
    {
        water = new waterdi(this);
        water->resize(400,300);
        water->setModal(true);
        water->setAttribute(Qt::WA_DeleteOnClose);
         water->show();
         if (water->exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
         {
             QPixmap greenon(":/light/light/greenon.jpg");
             ui->waterpreparedlight->setPixmap(greenon);
        my_test_bus->set_discrete_input(40,true);
        QString s =QString::fromLocal8Bit("启动含水及颗粒级配判定");
        onStatusInfo(s);
        }
    }
    else{
            QString s2=QString::fromLocal8Bit("系统未备妥");
            onStatusInfo(s2);
        }

}
//停止取图
void MainWindow::on_CameraStop_clicked()
{
    if(B_camera->camera.IsGrabbing())
    {
        B_camera->CamStop();
    }
    B_camera->CamStop();
     B_camera->CamDestroy();
    onStatusInfo(QString::fromLocal8Bit("关闭相机"));
}

void MainWindow::camStop()
{
    if(m_nTimerId != 0)
    {
        killTimer(m_nTimerId);
    }

    B_camera->CamStop();
    B_camera->CamDestroy();
//    onStatusInfo("停止工作");
}



void MainWindow::MBTEST(Mat Image,int i)
{
//    Mat Image;
//    Image = QImageToMat(image);
//    QString w =QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
//    w = w + ".bmp";
//    QByteArray cdata = w.toLocal8Bit();

//    cv::imwrite("C:/Users/JGWL/Desktop/pic_raw/"+string(cdata),Image);

    Rect rect((Image.cols)/4,0,(Image.cols)/2,Image.rows);
    Mat img_crop= Image(rect);


    Mat ycrcb;

    std::vector<cv::Mat> channels;
    Mat img_crop_1 = img_crop.clone();
    color_transfer_with_spilt(img_crop_1, channels);

    cv::Mat clahe_img;
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    // 直方图的柱子高度大于计算后的ClipLimit的部分被裁剪掉，然后将其平均分配给整张直方图
    // 从而提升整个图像
    clahe->setClipLimit(2.);    // (int)(4.*(8*8)/256)
    clahe->setTilesGridSize(Size(8, 8)); // 将图像分为8*8块
    clahe->apply(channels[0], clahe_img);
    channels[0].release();
    clahe_img.copyTo(channels[0]);
    color_retransfer_with_merge(ycrcb, channels);
//    imshow("img1",ycrcb);
    Mat ycrcb_blur;
    blur(ycrcb, ycrcb_blur,Size(2, 2));
    Mat mask(ycrcb.size(),CV_8UC1,Scalar(0));
    Mat mask_erode;
      qDebug()<<img_crop.cols;
      qDebug()<<img_crop.rows;

    for(int i = 0;i < img_crop.cols;i++)
    {
        for(int j = 0;j <img_crop.rows;j++)
        {// get the (i,j) pixel value
            int B = ycrcb_blur.at<Vec3b>(j, i)[0];

            int R = ycrcb_blur.at<Vec3b>(j, i)[1];

            int G = ycrcb_blur.at<Vec3b>(j, i)[2];

            int mean = (B+R+G)/3;
//              if(i==477  && j==435)
//              {
//                   qDebug()<<B;
//                   qDebug()<<R;
//                   qDebug()<<G;
//                   qDebug()<<"######";
////                  img_crop.at<Vec3b>(j, i)[0] = 255;
////                  img_crop.at<Vec3b>(j, i)[1] = 255;
////                  img_crop.at<Vec3b>(j, i)[2] = 255;

//              }
            if((B>R && B>G &&mean<103) || (R>253&&G>253&&B>253) )
            {
                mask.at<uchar>(j, i)=255;
            }
        }
    }
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(mask,mask_erode,element);

    vector<vector<Point> > contours1;
    vector<Vec4i> hierarchy1;
    findContours(mask_erode,contours1, hierarchy1, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    double maxarea1=0;
    int maxAreaIdx1 = 0;
//    imshow("img",mask_erode);
    Mat mask1(mask.size(),CV_8UC1,Scalar(0));

    for (int k = 0; k < contours1.size(); k++)
    {
       double tmparea1 = fabs(contourArea(contours1[k]));
        if (tmparea1>maxarea1 )
        {

            maxarea1 = tmparea1;
            maxAreaIdx1 = k;//记录最大轮廓的索引号*/

        }
    }
    qDebug()<<maxarea1;
    drawContours(mask1,contours1,maxAreaIdx1,Scalar(255,255,255),FILLED);

    drawContours(img_crop,contours1,maxAreaIdx1,Scalar(255,255,255),FILLED);
 //有光晕

    Mat ycrcb_blur_2;
    blur(ycrcb, ycrcb_blur,Size(2, 2));
    Mat maskrgb(ycrcb.size(),CV_8UC1,Scalar(0));
 //     Mat mask_erode;
 //     qDebug()<<img_crop.cols;
 //     qDebug()<<img_crop.rows;

    for(int i = 0;i < img_crop.cols;i++)
    {
        for(int j = 0;j <img_crop.rows;j++)
        {// get the (i,j) pixel value
            int B = ycrcb_blur.at<Vec3b>(j, i)[0];

            int R = ycrcb_blur.at<Vec3b>(j, i)[1];

            int G = ycrcb_blur.at<Vec3b>(j, i)[2];

            int mean = (B+R+G)/3;

            if((B>R && B>G) || (R>253&&G>253&&B>253) )
            {
                maskrgb.at<uchar>(j, i)=255;
            }
        }
    }



    Mat mask22;
    Mat element1 = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(maskrgb,mask22,element1);



     vector<vector<Point> > contours2;
     vector<Vec4i> hierarchy2;
     findContours(mask22,contours2, hierarchy2, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
     double maxarea2=0;
     int maxAreaIdx2 = 0;

     Mat mask2(mask.size(),CV_8UC1,Scalar(0));

     for (int q = 0; q < contours2.size(); q++)
     {
         double tmparea2 = fabs(contourArea(contours2[q]));
         if (tmparea2>maxarea2)
         {

             maxarea2 = tmparea2;
             maxAreaIdx2 = q;//记录最大轮廓的索引号*/
         }

     }
 //    qDebug()<<contours1[];
     qDebug()<<maxarea2;
     drawContours(mask2,contours2,maxAreaIdx2,Scalar(255,255,255),FILLED);
     drawContours(img_crop,contours2,maxAreaIdx2,Scalar(255,255,255),2);

     Mat mask_and,mask_or,mask1_,mask2_;
 //    threshold(mask1, mask1_, 0, 255, THRESH_BINARY_INV);
 //    threshold(mask2, mask2_, 0, 255, THRESH_BINARY_INV);
     bitwise_and(mask1,mask2,mask_and);
     bitwise_or(mask1,mask2,mask_or);

     double res = (double)bSums(mask_and)/bSums(mask_or);
    Mat img5;
    img5 = Image(Range(0,Image.rows),Range((Image.cols)/3,(Image.cols)/3*2));//选取img3中从(100,100)开始与img2同样大小的ROI区域
    img_crop.copyTo(img5);
    qDebug()<<res;
    if (maxarea1<1000)
    {
//        QString s = QString::fromLocal8Bit("无检测样本");
//        onStatusInfo(s);
//        MB_not_ok();
        MB_outputs[i] = 2;
    }
    else{

    if (res<0.82 && res>0.2)
    {
//        MB_ok();
        MB_outputs[i] = 1;
    }
    else if(res<0.1){
//        QString s = QString::fromLocal8Bit("无检测样本");
//        onStatusInfo(s);
//        MB_not_ok();
        MB_outputs[i] = 2;
    }
    else if (res>=0.82 && res<1){
//        MB_not_ok();
//        QString s = QString::fromLocal8Bit("MB值判定不合格");
//        onStatusInfo(s);
        MB_outputs[i] = 0;
    }
    else{
        MB_outputs[i] = 3;

    }
    }
    QString b =QDateTime::currentDateTime().toString("yyyy-MM-dd-hhmmss");
    b = b + ".bmp";
    QByteArray bdata = b.toLocal8Bit();

    cv::imwrite("C:/Users/JGWL/Desktop/pic_raw/"+string(bdata),Image);

    QImage qimg = Mat2QImage(Image);

//    B_camera->CamStop();
//    cv::imwrite("C:/pic/color_g.bmp",Image);
    if(i==2)
    {
        finish_MB_test_once(qimg);
    }
//    finish_MB_test_once(qimg);
//    ShowImage(qimg);
//    cv::waitKey(100000);
//    QPixmap myPix(":/main/1.png");
//    ui->Imagelabel->setPixmap(myPix.scaled(ui->Imagelabel->width(),
//                                           ui->Imagelabel->height(),
//                                           Qt::KeepAspectRatioByExpanding));
//    QImage qimg;
//    MB_result = true;
//            MB_ok();


//    finish_MB_test_once(qimg);

}

void MainWindow::ShowImage(QImage img)
{
    QImage img0=img.copy();

    ui->Imagelabel->setPixmap(QPixmap::fromImage(img0).scaled(ui->Imagelabel->width(),
                                                             ui->Imagelabel->height(),
                                                             Qt::KeepAspectRatioByExpanding));
}
//触发定时器事件
void MainWindow::timerEvent(QTimerEvent *event)
{
   click_MB_time = 0;
}

void MainWindow::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd HH:mm:ss dddd");
    ui->timeUpdate->setText(str);
}

void MainWindow::onStatusInfo(QString msg)
{
    QString text;
//    QTextCharFormat chfmt;

    //在标签之后附加状态信息
    text.append(" "+msg);
    //将插入位置设置到QTextEdit最后一行
    QTextCursor cur = ui->output->textCursor();
    cur.movePosition(QTextCursor::End);

    QTextTableFormat tableformate;
    tableformate.setBorder(0);
    QTextCharFormat charFormat;

    //宋体，12号，加粗，倾斜
    charFormat.setFont(QFont(QString("宋体"),16,QFont::Bold));
//    charFormat.setFontUnderline(true);


    //插入table，用于显示状态信息
    QTextTable *table = cur.insertTable(1,1,tableformate);
//    cur.insertText(text,charFormat);
    table->cellAt(0,0).firstCursorPosition().insertText("["+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"]:"+text);
    //table->cellAt(1,0).firstCursorPosition().insertText(text);
    cur.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor,1);
    cur.select(QTextCursor::BlockUnderCursor);
    cur.mergeCharFormat(charFormat);
    cur.clearSelection();
    cur.setCharFormat(charFormat);
    QScrollBar *bar = ui->output->verticalScrollBar();
    bar->setValue(bar->maximum());
    //状态信息条数+1
    m_status_count ++;
    //如果信息数>50，则删除最早的一条记录
    if(m_status_count >50)
    {
        //将选择光标移至第一个字符
        cur.setPosition(1,QTextCursor::MoveAnchor);
        //选择最早含有最早状态信息的table
        cur.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor,1);
        cur.select(QTextCursor::BlockUnderCursor);
        //删除该信息
        cur.removeSelectedText();
        //光标移至QTextEdit末行
        cur.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);
        m_status_count --;
    }
}

void MainWindow::showIDmsg(QString msg,QString cardNum)
{
//    qDebug()<<"1";
    QStringList message = msg.split(",");
    QString carNum = message[0];
    ui->LPNum->setText(carNum);
    QString sample = message[1];
    ui->sampleNumber->setText(sample);
    QString provider = message[2];
    ui->name->setText(provider);
    QString material = message[3];
    ui->materials->setText(material);
    ID = message[4];
//    qDebug()<<"2";

    QString s = QString::fromLocal8Bit("刷卡成功 %1, 车牌 %2").arg(cardNum).arg(carNum);
    onStatusInfo(s);

}

void MainWindow::finish_MB_test_once(QImage img)
{
    QPixmap greenoff(":/light/light/greenoff.jpg");
    ui->MBrunlight->setPixmap(greenoff);
//    MB_status_cur = false;
//    MB_status_last = false;

    ShowImage(img);

    int MB_end_suc = 0;
    int MB_end_vac = 0;
    for (int i=0;i<3;++i){
        if (MB_outputs[i]==1)
        {
            MB_end_suc = MB_end_suc+1;
        }
        if (MB_outputs[i]==2)
                {
                    MB_end_vac = MB_end_vac+1;
                }
    }
    if (MB_end_suc>=2){
        MB_ok();
    }
    else if (MB_end_vac>=2){
        MB_not_ok();
        QString s = QString::fromLocal8Bit("无检测样本");
                onStatusInfo(s);
    }
    else{
        MB_not_ok();
        QString s = QString::fromLocal8Bit("MB值判定不合格");
                onStatusInfo(s);
    }
//    my_test_bus->set_discrete_input(3,true);
//    cv::waitKey(2000);
//    my_test_bus->set_discrete_input(3,false);

    qDebug()<<"finish detect send signal"<<endl;
    cv::waitKey(10000);
    QPixmap myPix(":/main/1.png");
    ui->Imagelabel->setPixmap(myPix.scaled(ui->Imagelabel->width(),
                                           ui->Imagelabel->height(),
                                           Qt::KeepAspectRatioByExpanding));

    sqlread->WriteData(ID,MB_result,IMG,img);
    my_test_bus->set_discrete_input(3,true);
    cv::waitKey(2000);
    my_test_bus->set_discrete_input(3,false);
}


void MainWindow::MB_ok()
{
    my_test_bus->set_discrete_input(4,true);
    cv::waitKey(2000);
    my_test_bus->set_discrete_input(4,false);
    MB_result = true;
    QString s = QString::fromLocal8Bit("MB值判定合格");
    onStatusInfo(s);
    qDebug()<<"MB ok"<<endl;
}

void MainWindow::MB_not_ok()
{
    my_test_bus->set_discrete_input(5,true);
    cv::waitKey(2000);
    my_test_bus->set_discrete_input(5,false);
    MB_result = false;
//    QString s = QString::fromLocal8Bit("MB值判定不合格");
//    onStatusInfo(s);

    qDebug()<<"MB not ok"<<endl;
}

void MainWindow::reciece_register_state(int address,quint16 value)
{
//    qDebug()<<"address "<<QString::number(address)<<"main HoldingRegister value "<<QString::number(value)<<endl;
    sha[address]=QString::number(value);
    if(address==11)
    {
//decode_sha();
    }
}

void MainWindow::reciece_coil_state(int address, quint16 value)
{
    if (address==4)
    {
        //qDebug()<<"address "<<QString::number(address)<<"main coil value "<<QString::number(value)<<endl;
    }

    if(address==4&&value==1)                //MB启动视觉识别
    {
        qDebug()<<"MB visual receive";
//        MB_status_last = MB_status_cur;
//        MB_status_cur = true;
//        if (MB_status_cur==true && MB_status_last==false)
            if (!MB_status_cur)
        {
//            decode_sha();
            qDebug()<<"start detect"<<endl;
            MB_status_cur = true;



//            cv::waitKey(60000);
            detect_process();
        }
    }
    else if(address==4&&value==0)
    {
        MB_status_cur=false;

    }

    else if(address==3&&value==1) //MB系统备妥
    {
        Flag_MB_1 =true;
        QPixmap greenon(":/light/light/greenon.jpg");
        ui->MBpreparedlight->setPixmap(greenon);
    }
    else if(address==3&&value==0) //MB系统备妥
    {
        Flag_MB_1 =false;
        QPixmap greenoff(":/light/light/greenoff.jpg");
        ui->MBpreparedlight->setPixmap(greenoff);
    }
    else if(address==5&&value==1) //MB系统备妥
    {
//        Flag_MB_2 =true;
//        Flag_MB = true;
//        my_test_bus->set_discrete_input(0,true);
    }
    else if(address==0&&value==1)  //MB启动反馈
    {
        my_test_bus->set_discrete_input(0,false);
        Flag_MB_1 = false;
//        Flag_MB_2 = false;
    }
    else if(address==43&&value==1) //机制砂系统备妥
    {
        Flag_water = true;
        QPixmap greenon(":/light/light/greenon.jpg");
        ui->waterpreparedlight->setPixmap(greenon);
//        my_test_bus->set_discrete_input(24,true);
    }
    else if(address==43&&value==0) //机制砂系统备妥
    {
        Flag_water = true;
        QPixmap greenoff(":/light/light/greenoff.jpg");
        ui->waterpreparedlight->setPixmap(greenoff);
//        my_test_bus->set_discrete_input(24,true);
    }
    else if(address==40&&value==1)  //机制砂启动反馈
    {
        my_test_bus->set_discrete_input(40,false);
        Flag_water = false;
        QPixmap greenoff(":/light/light/greenoff.jpg");
        ui->waterpreparedlight->setPixmap(greenoff);
        QPixmap greenon(":/light/light/greenon.jpg");
        ui->waterrunlight->setPixmap(greenon);

//        onStatusInfo(QString::fromLocal8Bit("启动含水及颗粒级配检测"));
    }
    else if(address==47&&value==1)  //机制砂结束
    {
        my_test_bus->set_discrete_input(43,true);
//        Flag_water = false;
        QPixmap greenoff(":/light/light/greenoff.jpg");
//        waterfinished = true;

        ui->waterrunlight->setPixmap(greenoff);
//        onStatusInfo(QString::fromLocal8Bit("启动含水及颗粒级配检测"));
        if(!waterfinished)
        {
        decode_sha();
        waterfinished = true;
        }
    }
    else if(address==47&&value==0)
    {
        waterfinished = false;
    }


}

void MainWindow::detect_process()
{
    for(int i=0;i<3;++i){
        try{
            const char Filename[] = "acA1920-25gc_22983551_2.pfs";
//            B_camera->camera.Open();
            B_camera->camera.StartGrabbing();
            CFeaturePersistence::Load(Filename,&B_camera->camera.GetNodeMap(),true);

            if ( B_camera->camera.IsGrabbing())
            {
        //        // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
            B_camera->camera.RetrieveResult( 5000, B_camera->ptrGrabResult, TimeoutHandling_ThrowException);
            }
        //        // Image grabbed successfully?
                if (B_camera->ptrGrabResult->GrabSucceeded())
                {

                    cv::Mat openCvImage,img ;

                    uchar* buff = (uchar*)B_camera->ptrGrabResult->GetBuffer();
                    int nHeight =B_camera-> ptrGrabResult->GetHeight();
                    int nWidth = B_camera->ptrGrabResult->GetWidth();
                    Mat dst(nHeight, nWidth, CV_8UC2, buff);
                    cv::cvtColor( dst,openCvImage, COLOR_YUV2RGB_UYVY);
                    cvtColor( openCvImage,img, COLOR_BGR2RGB);
                    QString w =QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
                    w = w + ".bmp";
                    QByteArray cdata = w.toLocal8Bit();

                    cv::imwrite("C:/Users/JGWL/Desktop/pic_raw/"+string(cdata),img);

                    if (i==0){

                    Mat img1;
                    img1 = img.clone();


                    Rect rect((img.cols)/4,0,(img.cols)/2,img.rows);
                      cv::rectangle(img1, rect, Scalar(255,255, 255),4, LINE_8,0);
                     QImage IMG1 = Mat2QImage(img1);
    //               IMG =  Mat2QImage(img);

                   emit B_camera->ShowImageSignal(IMG1);
                    }
                    IMG =  Mat2QImage(img);
                   B_camera->camera.StopGrabbing();
                     MBTEST(img,i);
//                     B_camera->camera.Close();

                }
                else
                {
                    qDebug()<<"catch pic wrong";
                }
        }
        catch (const GenericException &e)
        {
            cout << e.what() << endl;
            onStatusInfo(QString::fromLocal8Bit("无法打开相机，请检查相机连接以及被占用情况,并重启"));
            MB_not_ok();
            my_test_bus->set_discrete_input(3,true);
            cv::waitKey(2000);
            my_test_bus->set_discrete_input(3,false);

            break;
        }

        cv::waitKey(1000);
    }

}

void MainWindow::detect_once(int i)
{
//    cv::waitKey(60000);
//    try{
//        B_camera->camera.StartGrabbing();

//        if ( B_camera->camera.IsGrabbing())
//        {
//    //        // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
//        B_camera->camera.RetrieveResult( 5000, B_camera->ptrGrabResult, TimeoutHandling_ThrowException);
//        }
//    //        // Image grabbed successfully?
//            if (B_camera->ptrGrabResult->GrabSucceeded())
//            {

//                cv::Mat openCvImage,img ;

//                uchar* buff = (uchar*)B_camera->ptrGrabResult->GetBuffer();
//                int nHeight =B_camera-> ptrGrabResult->GetHeight();
//                int nWidth = B_camera->ptrGrabResult->GetWidth();
//                Mat dst(nHeight, nWidth, CV_8UC2, buff);
//                cv::cvtColor( dst,openCvImage, COLOR_YUV2RGB_UYVY);
//                cvtColor( openCvImage,img, COLOR_BGR2RGB);
//                QString w =QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
//                w = w + ".bmp";
//                QByteArray cdata = w.toLocal8Bit();

//                cv::imwrite("C:/Users/JGWL/Desktop/pic_raw/"+string(cdata),img);

//                if (i==0){

//                Mat img1;
//                img1 = img.clone();


//                Rect rect((img.cols)/4,0,(img.cols)/2,img.rows);
//                  cv::rectangle(img1, rect, Scalar(255,255, 255),4, LINE_8,0);
//                 QImage IMG1 = Mat2QImage(img1);
////               IMG =  Mat2QImage(img);

//               emit B_camera->ShowImageSignal(IMG1);
//                }
//                IMG =  Mat2QImage(img);
//               B_camera->camera.StopGrabbing();
//                 MBTEST(img,i);

//            }
//            else
//            {
//                qDebug()<<"catch pic wrong";
//            }
//    }
//    catch (exception& e)
//    {
//        onStatusInfo(QString::fromLocal8Bit("无法打开相机，请检查相机连接以及被占用情况"));

//        break;
//    }


}

void MainWindow::decode_sha()
{
    QString wet = sha[0];
    QString dry = sha[1];
    QString sha1 = sha[2];
    QString sha2 = sha[3];
    QString sha3 = sha[4];
    QString sha4 = sha[5];
    QString sha5 = sha[6];
    QString sha6 = sha[7];
    QString sha7 = sha[8];
    QString sha8 = sha[9];
//    QString sha9 = sha[10];

    QString s1 = QString::fromLocal8Bit("含水检测完成 湿料 %1g 干料 %2g").arg(wet).arg(dry);
    onStatusInfo(s1);
    QString s2 = QString::fromLocal8Bit("颗粒级配检测完成 砂1 %1g 砂2 %2g 砂3 %3g 砂4 %4g 砂5 %5g 砂6 %6g 砂7 %7g 砂8 %8g ").arg(sha1).arg(sha2).arg(sha3).arg(sha4).arg(sha5).arg(sha6).arg(sha7).arg(sha8);
    onStatusInfo(s2);

    sqlread->WriteTest(ID,wet,dry,sha1,sha2,sha3,sha4,sha5,sha6,sha7,sha8);
//    waterfinished = false;

}



cv::Mat MainWindow::QImageToMat(QImage image)
{
    cv::Mat mat;
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, COLOR_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}

int MainWindow::bSums(Mat src)
{
    int counter = 0;	//迭代器访问像素点
    Mat_<uchar>::iterator it = src.begin<uchar>();
    Mat_<uchar>::iterator itend = src.end<uchar>();
    for (; it!=itend; ++it)
    {
        if((*it)>0) counter+=1;//二值化后，像素点是0或者255
    }
    return counter;
}


QImage MainWindow::Mat2QImage(Mat mtx)
{
    switch (mtx.type())
    {
    case CV_8UC1:
        {
            QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols, QImage::Format_Grayscale8);
            return img;
        }
        break;
    case CV_8UC3:
        {
            QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 3, QImage::Format_RGB888);
            return img.rgbSwapped();
        }
            break;
    case CV_8UC4:
        {
         QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 4, QImage::Format_ARGB32);
            return img;
        }
        break;
    default:
        {
            QImage img;
            return img;
        }
        break;
}
}


void  MainWindow::color_transfer_with_spilt( cv::Mat &input, std::vector<cv::Mat> &chls )
{
    cv::cvtColor( input, input, cv::COLOR_BGR2YCrCb);
    cv::split( input, chls );
}

void  MainWindow::color_retransfer_with_merge( cv::Mat &output, std::vector<cv::Mat> &chls )
{
    cv::merge( chls, output );
    cv::cvtColor( output, output, cv::COLOR_YCrCb2BGR );
}




