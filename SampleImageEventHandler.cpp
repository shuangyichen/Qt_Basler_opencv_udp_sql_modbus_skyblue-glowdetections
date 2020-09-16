
#include "SampleImageEventHandler.h"

SampleImageEventHandler::SampleImageEventHandler(void)
{
    CWidth = 0;
    CHeight = 0;
}

SampleImageEventHandler::~SampleImageEventHandler(void)
{
}

//回调函数
void SampleImageEventHandler::OnImageGrabbed( CInstantCamera& camera, const CGrabResultPtr& grabResult )
{
    //this;
    CWidth = grabResult->GetWidth();//图像数据宽
    CHeight = grabResult->GetHeight();//图像数据高
    m_pBuffer = (unsigned char*)grabResult->GetBuffer();//图像数据


	//保存图片
//    CImagePersistence::Save( ImageFileFormat_Bmp, "D:\\GrabbedImage.bmp", grabResult);//ImageFileFormat_Png


    //Pylon::DisplayImage(1,grabResult);//窗口显示图像
}
