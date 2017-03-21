#include <iostream>
#include <cmath>
#include <opencv2\core\core.hpp>
#include <opencv2\imgcodecs\imgcodecs.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	Mat input_img;
	input_img = imread(argv[1], IMREAD_GRAYSCALE);
	if (input_img.empty())
	{
		cerr << "Couldn't open image................." << endl;
		return 1;
	}
	Mat output(input_img.rows, input_img.cols, CV_32F);
	for (int i{}; i < output.rows; i++)
		for (int j{}; j < output.cols; j++)
			output.at<float>(i, j) = input_img.at<uchar>(i, j);
	double minValue{}, maxValue{};
	minMaxLoc(output, &minValue, &maxValue);
	Mat output2;
	cout << minValue << " " << maxValue << endl;
	output.convertTo(output2, CV_8U, 255.0 / (maxValue - minValue + 1), -minValue / (255.0 / (maxValue - minValue + 1)));
	namedWindow(argv[1], WINDOW_AUTOSIZE);
	imshow(argv[1], input_img);
	namedWindow("23", WINDOW_AUTOSIZE);
	imshow("23", output2);
	waitKey();
	return 0;
}
/*Mat convertTo_CV_8U(Mat& input_img)
{
double minValue{}, maxValue{};
Point2i minLoc, maxLoc;
minMaxLoc(input_img, &minValue, &maxValue, &minLoc, &maxLoc);
Mat output;
input_img.convertTo(output, CV_8U, 256.0 / (maxValue - minValue + 1), -minValue / (256.0 / (maxValue - minValue + 1)));
for (int i{}; i < input_img.rows - 1; i++)
for (int j{}; j < input_img.cols - 1; j++)
{
cout << output.at<uchar>(i, j) << " ";
}
return output;
}*/