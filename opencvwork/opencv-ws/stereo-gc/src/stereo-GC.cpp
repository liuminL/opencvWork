#include <highgui.h> 
#include <cv.h> 
#include <cxcore.h> 
#include <iostream> 
using namespace std; 
using namespace cv; 
#include </usr/local/opencv3.4.1/include/opencv2/opencv.hpp> 
#include </usr/local/opencv3.4.1/include/opencv2/imgproc/imgproc.hpp> 
#include </usr/local/opencv3.4.1/include/opencv2/core/core.hpp> 
#include </usr/local/opencv3.4.1/include/opencv2/highgui/highgui.hpp> 
#include </usr/local/opencv3.4.1/include/opencv2/calib3d/calib3d.hpp> 
#include </usr/local/opencv3.4.1/include/opencv2/features2d/features2d.hpp> 
//#include </usr/local/opencv3.4.1/include/opencv2/legacy/legacy.hpp>

void GC()
{
    IplImage* pImgleft = cvLoadImage("../Art/view1.png",0); 
    CvMat* LEFT=cvCreateMat(pImgleft->height,pImgleft->width,CV_8UC1); 
    cvConvert(pImgleft,LEFT); 

    IplImage* pImgright = cvLoadImage("../Art/view5.png",0); 
    CvMat* RTGHT=cvCreateMat(pImgright->height,pImgright->width,CV_8UC1); 
    cvConvert(pImgright,RTGHT);

    CvStereoGCState* state = cvCreateStereoGCState(16,2); 
    CvMat* left_disp_ = cvCreateMat(LEFT->height,LEFT->width,CV_16S); 
    CvMat* right_disp_ = cvCreateMat(RTGHT->height,RTGHT->width,CV_16S); 
    cvFindStereoCorrespondenceGC(LEFT,RTGHT,left_disp_,right_disp_,state,0); 
    cvReleaseStereoGCState(&state);

    CvMat* disparity_left = cvCreateMat(left_disp_->height,left_disp_->width, CV_8U ); 
    cvConvertScale( left_disp_, disparity_left,-16); 
    cvSaveImage( "disparity.bmp",disparity_left);
}
int main(int argc, char const *argv[])
{
    GC();
    return 0;
}