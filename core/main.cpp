#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("die_on_chip.png");
	Mat dist;
	Mat dist1;
	Mat proc;
	Mat proc1;
	Mat labelmat;
	Mat statsmat;
	Mat centermat;
	Mat dstImage;
	cvtColor(src, dist1, CV_BGR2GRAY);
	threshold(dist1, dist, 150, 255, THRESH_BINARY);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dist, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rbox = minAreaRect(contours[i]);
		float width = rbox.size.width;
		float height = rbox.size.height;
		float test = width / height;
		//cout << test << endl;
		if (test>0.9&&test<1.1) {
			drawContours(src, contours, i, Scalar(255, 44, 33), 1, 8);
			Point2f vtx[4];
			rbox.points(vtx);
			cout << test << endl;
			for (int j = 0; j < 4; ++j) {
				line(src, vtx[j], vtx[j < 3 ? j + 1 : 0], Scalar(33, 44, 255), 2, CV_AA);
			}
		}
	}
	//¡¾7¡¿ÏÔÊ¾×îºóµÄÂÖÀªÍ¼
	imshow("ÂÖÀªÍ¼", src);

	waitKey(0);
}