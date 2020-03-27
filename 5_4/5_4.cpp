// 5_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture cap;

	cap.open(0);

	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat dx;
		cv::Mat dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			Sobel(frame, dx, CV_16SC1, 1, 0, 5);
			Sobel(frame, dy, CV_16SC1, 0, 1, 5);
			cv::imshow("原图", frame);
			cv::imshow("x方向上的边缘提取", dx);
			cv::imshow("y方向上的边缘提取", dy);
		}
		waitKey(30);
	}
	return 0;
}