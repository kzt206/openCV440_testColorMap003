#include <opencv2/opencv.hpp>

using namespace cv;

void testRect1() {

	// image object
	// full color
	Mat image(500, 500, CV_8UC3);


	// fill with white
	image = Scalar(255, 255, 255);

	// draw rectangles 1
	Point p1(10, 10), p2(190, 90);
	rectangle(image, p1, p2, Scalar(255, 0, 0), 1, LINE_4);

	// draw rectangles 2
	Rect rect(210, 10, 180, 80);
	rectangle(image, rect, Scalar(0, 0, 255), 1, LINE_4);


	// draw rectangles 3
	for (int i = 0; i < 13; i++) {
		Rect rect(i * 30 + 10, 100, 20, 80);
		rectangle(image, rect, Scalar(255 - i * 20, 0, i * 20 + 15), -1, LINE_4);
	}

	// draw rectangles 4
	for (int i = 0; i < 10; i++) {
		Rect rect( 0 + 10 * i, 0, 10, 10);
		rectangle(image, rect, Scalar(255 - i * 20, 0, 0), -1, LINE_4);
	}

	imshow("Map", image);
	waitKey();

}