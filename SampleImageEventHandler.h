#pragma once
#include <pylon/PylonIncludes.h> //���Pylonͷ�ļ�

#include <QThread>
#include <QImage>
#include <QDebug>

#ifdef PYLON_WIN_BUILD
#include <pylon/PylonGUI.h> //PylonGUI��ʾ
#endif

using namespace Pylon;//Pylon���ƿռ�

class SampleImageEventHandler :public CImageEventHandler
{


public:
	SampleImageEventHandler(void);
	~SampleImageEventHandler(void);
public:
    int CWidth;//ͼ�����ݿ�
    int CHeight;//ͼ�����ݸ�
    unsigned char *m_pBuffer;
    
public:
	virtual void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& grabResult);//�ص�����


};
