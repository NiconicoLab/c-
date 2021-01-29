#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage : " << argv[0] << " <image files>" << std::endl;
		return 1;
	}
	cv::Mat frame = cv::imread(argv[1]);

	int fps = 7;
	int fourcc  = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
	cv::VideoWriter writer("capture.mov", fourcc, fps, frame.size());

	cv::Size size = frame.size();

	if (writer.isOpened())
	{
		std::cerr << "Open!\n";
	}
	else
	{
		std::cerr << "failed..\n";
		return -1;
	}

	cv::namedWindow("Capture", cv::WINDOW_AUTOSIZE | cv::WINDOW_FREERATIO);
	for (int i = 0; i < argc - 1; i++)
	{
		frame = cv::imread(argv[i + 1]);
		cv::resize(frame, frame, size);
		writer << frame;
		cv::imshow("Capture", frame);
		if (cv::waitKey(30) >= 0) break;
	}

	cv::waitKey(1000);

	return 0;
}
