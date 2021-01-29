#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char **argv)
{
	cv::Mat image = cv::imread("pic.png");
	cv::namedWindow("hoge");
	imshow("hoge", image);
	cv::waitKey(0);

	return 0;
}
