
#include "SampleImageEventHandler.h"

SampleImageEventHandler::SampleImageEventHandler(void)
{
    CWidth = 0;
    CHeight = 0;
}

SampleImageEventHandler::~SampleImageEventHandler(void)
{
}

//�ص�����
void SampleImageEventHandler::OnImageGrabbed( CInstantCamera& camera, const CGrabResultPtr& grabResult )
{
    //this;
    CWidth = grabResult->GetWidth();//ͼ�����ݿ�
    CHeight = grabResult->GetHeight();//ͼ�����ݸ�
    m_pBuffer = (unsigned char*)grabResult->GetBuffer();//ͼ������


	//����ͼƬ
//    CImagePersistence::Save( ImageFileFormat_Bmp, "D:\\GrabbedImage.bmp", grabResult);//ImageFileFormat_Png


    //Pylon::DisplayImage(1,grabResult);//������ʾͼ��
}
