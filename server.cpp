#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

#include <iostream>
using namespace std;



//Grey filter operations

int GreyFilter( cv::Mat image){

    cv::Mat greyImg;

    cv:: cvtColor(image,greyImg, cv::COLOR_RGB2GRAY);

    int heightNew = greyImg.size[0];

    int widhtNew = greyImg.size[1];

    //cv::imshow("Grey Filter", greyImg);


    return (greyImg,heightNew,widhtNew);

}

//gaussian blur filter operations

int GaussianFilter (cv::Mat image, int blurlvl){

    cv::Mat gaussianImg;

    cv:: GaussianBlur(image,gaussianImg,cv::Size(blurlvl,blurlvl),0);

    int heightNew = gaussianImg.size[0];

    int widhtNew = gaussianImg.size[1];

    //cv::imshow("Gaussian", gaussianImg);

    
    return (gaussianImg,heightNew,widhtNew);


}

//Bright filter operations

int BrightFilter (cv::Mat image, int brillolvl){

    cv::Mat BrightImg;

    image.convertTo(BrightImg,-1,2,brillolvl);

    int heightNew = BrightImg.size[0];

    int widhtNew = BrightImg.size[1];

    //cv::imshow("Bright", BrightImg);



    return (BrightImg,heightNew,widhtNew);

}

//gamma correction operations 

void gammaCorrection(const cv::Mat &src, cv::Mat &dst, const float gamma)
{
    float invGamma = 1 / gamma;

    cv::Mat table(1, 256, CV_8U);
    uchar *p = table.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = (uchar) (pow(i / 255.0, invGamma) * 255);
    }

    LUT(src, table, dst);

}

//Gamma filter operations 

int GammaFilter (cv::Mat image, int gammalvl){

    cv::Mat GammaImg;

    gammaCorrection(image, GammaImg, gammalvl);


    //cv::imshow("Gamma", GammaImg);

    int heightNew = GammaImg.size[0];

    int widhtNew = GammaImg.size[1];


    return (GammaImg,heightNew,widhtNew);


}


//Sockets
/*
int main(){

    int estado = 5;

    cv::Mat image;

    image = cv::imread("./sample.jpeg", cv::IMREAD_COLOR);

    int height = image.size[0];

    int widht = image.size[1];

    cout<<height<<endl;
    cout<<widht<<endl;


    estado = GreyFilter(height,widht);
    cout<<estado<<endl;

   

    estado = GaussianFilter(image,45,height,widht);
    cout<<estado<<endl;
   

    estado = BrightFilter(image,100,height,widht);
    cout<<estado<<endl;
  

    estado = GammaFilter(image,5,height,widht);
    cout<<estado<<endl;

    cout<<"test completed\n";


}*/