// 5_4.cpp : �������̨Ӧ�ó������ڵ㡣
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
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
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
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			Sobel(frame, dx, CV_16SC1, 1, 0, 5);
			Sobel(frame, dy, CV_16SC1, 0, 1, 5);
			cv::imshow("ԭͼ", frame);
			cv::imshow("x�����ϵı�Ե��ȡ", dx);
			cv::imshow("y�����ϵı�Ե��ȡ", dy);
		}
		waitKey(30);
	}
	return 0;
}