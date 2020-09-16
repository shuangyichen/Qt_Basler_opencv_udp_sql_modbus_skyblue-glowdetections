#include "opencv2/opencv.hpp"
#include "BaslerCamer.h"
#include <QDebug>
static const uint32_t c_countOfImagesToGrab = 100;
BaslerCamer::BaslerCamer(void)
{
}

BaslerCamer::~BaslerCamer(void)
{
}
//�����ʼ��
void BaslerCamer::CamInit()
{
    qDebug() << "camera init-----------";
//    static const uint32_t c_countOfImagesToGrab = 100;
    // The exit code of the sample application.
    int exitCode = 0;
    const char Filename[] = "acA1920-25gc_22983551_2.pfs";
    // Before using any pylon methods, the pylon runtime must be initialized.
    PylonInitialize();

    try
    {
        // Create an instant camera object with the camera device found first.
        camera.Attach( CTlFactory::GetInstance().CreateFirstDevice());
        camera.Open();
        CFeaturePersistence::Load( Filename, &camera.GetNodeMap(), true );
        // Print the model name of the camera.
        qDebug() << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
        emit camera_abnormal(QString::fromLocal8Bit("������ӳɹ�"));

        // The parameter MaxNumBuffer can be used to control the count of buffers
        // allocated for grabbing. The default value of this parameter is 10.
        camera.MaxNumBuffer = 5;
        camera.Close();
    }
    catch (const GenericException &e)
    {
        // Error handling.
        qDebug() << "An exception occurred." << endl
        << e.GetDescription() << endl;
        exitCode = 1;
//        emit camera_abnormal(QString("dis"));
        emit camera_abnormal(QString::fromLocal8Bit("�������ʧ�ܣ�����������Ӽ���ռ��������������"));
//        emit camera_abnormal(QString("dis"));
        qDebug() << "An exception occurred.####" << endl;
    }
}
//��ʼȡͼ
void BaslerCamer::Cam_Start()
{

//    camera.StartGrabbing();

//    // This smart pointer will receive the grab result data.
//    CGrabResultPtr ptrGrabResult;

//    // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
//    // when c_countOfImagesToGrab images have been retrieved.
//    if ( camera.IsGrabbing())
//    {
////        // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
//    camera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);

////        // Image grabbed successfully?
//        if (ptrGrabResult->GrabSucceeded())
//        {
////            // Access the image data.
////            qDebug() << "SizeX: " << ptrGrabResult->GetWidth() << endl;
////            qDebug() << "SizeY: " << ptrGrabResult->GetHeight() << endl;
////            const uint8_t *pImageBuffer = (uint8_t *) ptrGrabResult->GetBuffer();
////            qDebug() << "Gray value of first pixel: " << (uint32_t) pImageBuffer[0] << endl << endl;
//            cv::Mat openCvImage = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t *) ptrGrabResult->GetBuffer());


            uchar* buff = (uchar*)ptrGrabResult->GetBuffer();
            int nHeight = ptrGrabResult->GetHeight();
            int nWidth = ptrGrabResult->GetWidth();
////            if(m_size != QSize(nWidth, nHeight)) {
////                m_size = QSize(nWidth, nHeight);
////                emit sigSizeChange(m_size);
////            }
//            QImage imgBuff(buff, nWidth, nHeight, QImage::Format_Indexed8);
//            OutImage = imgBuff;
//            if(pInBuffer->GetPixelType() == PixelType_Mono8) {
//                uchar* pCursor = OutImage.bits();
//                if ( OutImage.bytesPerLine() != nWidth ) {
//                    for ( int y=0; y<nHeight; ++y ) {
//                        pCursor = OutImage.scanLine( y );
//                        for ( int x=0; x<nWidth; ++x ) {
//                            *pCursor =* buff;
//                            ++pCursor;
//                            ++buff;
//                        }
//                    }
//                } else {
//            emit ShowImageSignal(OutImage);
//                    memcpy( OutImage.bits(), buff, nWidth * nHeight );
//                }

#ifdef PYLON_WIN_BUILD
            // Display the grabbed image.
//                Pylon::DisplayImage(1, ptrGrabResult);
//                Displ
#endif
//        }
//        else
//        {
//            qDebug() << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
//        }

//    }
}

//ֹͣȡͼ
void BaslerCamer::CamStop()
{

    camera.StopGrabbing();

}

//�˳�ʱ�ر����
void BaslerCamer::CamDestroy()
{
	camera.StopGrabbing();
	camera.DestroyDevice();
	Pylon::PylonTerminate();
}


