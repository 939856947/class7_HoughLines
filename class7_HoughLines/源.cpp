#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{

	//����ԭʼͼ
	Mat srcImage = imread("D:\\18.jpg");
	Mat midImage, dstImage;

	//canny����Եת��Ϊ�Ҷ�ͼ
	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);

	//���л���任
	std::vector<cv::Vec2f> lines;
	HoughLines(midImage, lines, 4, CV_PI / 180,150, 0, 0);

	//һ����ͼ�л��Ƴ�ÿ���߶�
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
	

	//��Ե���֮���ͼ
	imshow("����Ե�����ͼ��", midImage);
	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��", srcImage);
	waitKey(0);
	return 0;
}