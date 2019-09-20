#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
using namespace cv;
using namespace std;

double q = 63.999;

// double points[6][5] = {{0.0, 1.0, q, 4 * q, q},
// 					   {-sqrt(3) / 2, 0.5, 3 * q, 3 * q, 0},
// 					   {-sqrt(3) / 2, -0.5, 4 * q, q, q},
// 					   {0.0, -1.0, 3 * q, 0, 3 * q},
// 					   {sqrt(3) / 2, -0.5, q, q, 4 * q},
// 					   {sqrt(3) / 2, 0.5, 0, 3 * q, 3 * q}};

double points[6][5] = {{0.0, 1.0, 2 * q, 4 * q, 0},
					   {-sqrt(3) / 2, 0.5, 4 * q, 2 * q, 0},
					   {-sqrt(3) / 2, -0.5, 4 * q, 0, 2 * q},
					   {0.0, -1.0, 2 * q, 0, 4 * q},
					   {sqrt(3) / 2, -0.5, 0, 2 * q, 4 * q},
					   {sqrt(3) / 2, 0.5, 0, 4 * q, 2 * q}};

int main(int argc, char **argv) {
	srand(time(NULL));
	int w = 3840, h = 2160;
	Mat img(h, w, CV_8UC3, Scalar(0, 0, 0));

	double x = 0, y = 0;
	double cur[3] = {0, 0, 0};
	double s = 2.0 * h / 5;
	int yshift = 0;

	for (int i = 0; i < 100000000; i++) {
		int p = rand() % 6;
		x = (x - 2 * points[p][1]) / 3, y = (y + 2 * points[p][0]) / 3;
		for (int j = 0; j < 3; j++) {
			cur[j] = (cur[j] + 2 * points[(p+3)%6][j + 2]) / 3;
		}
		int realx = (int)(x * s) + w / 2, realy = h / 2 - (int)(y * s) + yshift;
		if (i > 100000) {
			Vec3b pixel = img.at<Vec3b>(Point(realx, realy));
			for (int j = 0; j < 3; j++) {
				pixel[j] = (int)cur[j];
			}
			img.at<Vec3b>(Point(realx, realy)) = pixel;
		}
	}

	namedWindow("Display window", WINDOW_NORMAL);
	imshow("Display window", img);
	waitKey(0);
	imwrite("Images/HexagonTopGBBRRG.png", img);
	return 0;
}