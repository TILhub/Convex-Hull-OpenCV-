#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cstdlib>
using namespace cv;
using namespace std;
int main() {
	string image_path = "E:/image.jpg";
	Mat src, gray, blur_image, threshold_output;
	src = imread(image_path, 1); //read image
	cvtColor(src, gray, COLOR_BGR2GRAY); //grayscale conversion
	blur(gray, blur_image, Size(3, 3));	//blur to remove noise
	threshold(gray, threshold_output, 200, 255, THRESH_OTSU);	//convert to binary
    /*
	namedWindow("Source", WINDOW_AUTOSIZE);
	imshow("Source", src);*/
	/*CONVEX HULL IMPLEMENTATION*/
	Mat src_copy = src.clone();
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(threshold_output, contours, hierarchy, RETR_TREE,CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point>> hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
		convexHull(Mat(contours[i]), hull[i], false);
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++) {
		Scalar color_contours = Scalar(0, 255, 0); // color for contours : blue
		Scalar color = Scalar(255, 255, 255); // color for convex hull : white
		drawContours(drawing, contours, i, color_contours, 2, 8, vector<Vec4i>(), 0, Point());
		drawContours(drawing, hull, i, color, 2, 8, vector<Vec4i>(), 0, Point());
	}
	namedWindow("Output", WINDOW_AUTOSIZE);
	imshow("Output", drawing);
	waitKey(0);
	return 0;
}