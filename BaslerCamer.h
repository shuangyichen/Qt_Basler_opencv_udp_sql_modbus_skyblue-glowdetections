#pragma once

#include <QThread>
#include <QImage>

//#include "SampleImageEventHandler.h" //�ص���ͷ�ļ�
#include <pylon/PylonIncludes.h> //Pylonͷ�ļ�


#ifdef PYLON_WIN_BUILD
//#include <pylon/PylonGUI.h>
#endif



using namespace Pylon;//pylon���ƿռ�

using namespace GenApi;//pylon SDKͨ����д�����ƿռ�

class BaslerCamer :public QObject
{
    Q_OBJECT
public:
	BaslerCamer(void);
	~BaslerCamer(void);

public:
	CInstantCamera camera;//ʵ�����������
	
	INodeMap *nodemap;//������Խڵ�

	CDeviceInfo di;//�豸��Ϣ������UserID��SN�Ŵ������


public:
//	SampleImageEventHandler* CData;

	void CamInit();//�����ʼ��
    void Cam_Start();//��ʼȡͼ
    void CamStop();//ֹͣȡͼ
	void CamDestroy();//�˳�ʱ�ر����

//	Cstring CamName();//��ȡ�����
//	CString CamSerialNum();//��ȡ���SN��
//	CString CamFormat();//��ȡ���ͼ���ʽ
//	double CamFrameRate();//��ȡ���֡��
//	int CamWidth();//�ֱ��ʿ�
//	int CamHeight();//�ֱ��ʸ�

//	double GetExpMin();//��ȡ�ع���Сֵ
//	double GetExpMax();//��ȡ�ع����ֵ
//	double GetExpCur();//��ȡ��ǰ�ع�ֵ
//	void SetExp(double ExpTime);//�����ع�ֵ

//	int GetGainMin();//��ȡ������Сֵ
//	int GetGainMax();//��ȡ�������ֵ
//	int GetGainCur();//��ȡ��ǰ����ֵ
//	void SetGain(int GainValue);//��������ֵ

//    void SoftTrigEnableOn();//��������ʹ��
//    void SoftTrigEnableOff();//�ر�����ʹ��
//    void ExecuteSoftTrig();//ִ������
//    void ExtTrigEnableOn();//�����ⴥ��ʹ��
//    void ExtTrigEnableOff();//�ر��ⴥ��ʹ��

    CGrabResultPtr ptrGrabResult;
    QImage OutImage;
    uchar* buff ;
    int nHeight ;
    int nWidth ;

signals:
    void ShowImageSignal(QImage);
    void camera_abnormal(QString);

};
