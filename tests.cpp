#include "server.cpp"
#include <gtest/gtest.h>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>


 
TEST(ServerTest, images) { 
    cv::Mat image;

    image = cv::imread("./sample.jpeg", cv::IMREAD_COLOR);

    cv::Mat greyImg;

    greyImg = cv::imread("./grey.jpeg", cv::IMREAD_COLOR);

    cv::Mat gaussianImg;

    gaussianImg = cv::imread("./gaussian.jpeg", cv::IMREAD_COLOR);

    cv::Mat BrightImg;

    BrightImg = cv::imread("./Bright.jpeg", cv::IMREAD_COLOR);

    cv::Mat GammaImg;

    GammaImg = cv::imread("./Gamma.jpeg", cv::IMREAD_COLOR);




    ASSERT_EQ((greyImg,550,550), GreyFilter(image));

    ASSERT_EQ((gaussianImg,550,550), GaussianFilter(image,45));

    ASSERT_EQ((BrightImg,550,550), BrightFilter(image,100));

    ASSERT_EQ((GammaImg,550,550), GammaFilter(image,5));

}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}