#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap("movie.wmv");

	if(!cap.isOpened())
		return -1;

	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);

	cv::Mat frame;
	while(1)
	{
		cap >> frame;

		if (frame.empty())
			break;
		cv::imshow("image", frame);
		if(cv::waitKey(30) >= 0)
			break;
	}
	return 0;
}
