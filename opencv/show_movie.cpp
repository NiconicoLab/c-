#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char* argv[])
{
	cv::VideoCapture video("movie.wmv");

	if(!video.isOpened())
		return -1;

	cv::namedWindow("hoge");
	while(1)
	{
		cv::Mat frame;
		video >> frame;
		if(frame.empty() || cv::waitKey(30) >= 0 || video.get(cv::CAP_PROP_POS_AVI_RATIO) == 1)
		{
			break;
		}
		cv::imshow("hoge", frame); 
	}



	return 0;
}
