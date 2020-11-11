#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{

	//载入原始图
	Mat srcImage = imread("D:\\18.jpg");
	Mat midImage, dstImage;

	//canny检测边缘转化为灰度图
	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);

	//进行霍夫变换
	std::vector<cv::Vec2f> lines;
	HoughLines(midImage, lines, 4, CV_PI / 180,150, 0, 0);

	//一次在图中绘制出每条线段
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(srcImage, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA);

	}
	

	//边缘检测之后的图
	imshow("【边缘检测后的图】", midImage);
	//显示效果图
	imshow("【效果图】", srcImage);
	waitKey(0);
	return 0;
}