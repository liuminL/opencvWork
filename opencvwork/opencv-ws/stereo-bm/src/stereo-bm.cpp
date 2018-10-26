#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <time.h>
//#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std; 
using namespace cv; 
//g++ `pkg-config opencv --cflags` stereo-bm.cpp -o opencv `pkg-config opencv --libs`

int main() 
{ 
//IplImage * img1 = cvLoadImage("left.png",0); 
//IplImage * img2 = cvLoadImage("right.png",0); 
//IplImage * img1 = cvLoadImage("tsukuba_l.png",0); 
//IplImage * img2 = cvLoadImage("tsukuba_r.png",0); 
    IplImage * img1 = cvLoadImage("../Art/view1.png",0); 
    IplImage * img2 = cvLoadImage("../Art/view5.png",0); 
    CvStereoBMState* BMState=cvCreateStereoBMState(); 
    assert(BMState); 
    BMState->preFilterSize=9; 
    BMState->preFilterCap=31; 
    BMState->SADWindowSize=15; 
    BMState->minDisparity=200; 
    BMState->numberOfDisparities=144; 
    BMState->textureThreshold=10; 
    BMState->uniquenessRatio=5; 
    BMState->speckleWindowSize=100; 
    BMState->speckleRange=32; 
    BMState->disp12MaxDiff=-1; 
    CvMat* disp=cvCreateMat(img1->height,img1->width,CV_16S); 
    CvMat* vdisp=cvCreateMat(img1->height,img1->width,CV_8U); 
    int64 t=getTickCount(); 
    cvFindStereoCorrespondenceBM(img1,img2,disp,BMState); 
    t=getTickCount()-t; 
    cout<<"Time elapsed:"<<t*1000/getTickFrequency()<<endl; 
    cvSave("disp.xml",disp); 
    cvNormalize(disp,vdisp,0,255,CV_MINMAX); 
    namedWindow("left", 1); 
    cvShowImage("left", img1); 
    namedWindow("right", 1); 
    cvShowImage("right", img2); 
    //cvNamedWindow("BM_disparity",0); 
    namedWindow("BM_disparity", 1); 
    cvShowImage("BM_disparity",vdisp); 
    cvWaitKey(0); 
    //cvSaveImage("cones\\BM_disparity.png",vdisp); 
    cvReleaseMat(&disp); 
    cvReleaseMat(&vdisp); 
    cvDestroyWindow("BM_disparity"); 
    return 0; 
} 
