#include <opencv2/opencv.hpp>

using namespace cv;

void axis(Point x0, Point x1, Point y0, Point y1, Mat& image);

void testRect3() {

	// image object
	// full color
	const int xShift = 20;
	const int yShift = 20;
	const int xLength = 500;
	const int yLength = 500;
	const int xMaxShift = 20;
	const int yMaxShift = 20;
	const int xMax = xShift + xLength + yMaxShift;
	const int yMax = yShift + yLength + yMaxShift;

	// point size
	const int dx = 20;
	const int dy = 20;


	Mat image(yMax, xMax, CV_8UC3);


	// fill with white
	image = Scalar(255, 255, 255);  // Blue,Green,Red


	// input data
	const int numberData = xLength / dx;
	const int numberData2 = numberData * numberData;
	int x[numberData2], y[numberData2], z[numberData2];
	int n = 0;
	for (int i = 0; i < numberData; i++) {
		for (int j = 0; j < numberData; j++) {
			x[n] = i * dx;
			y[n] = j * dy;
			z[n] = (i * i - j * j) / 4 + 128;
			n++;
		}
	}
	std::cout << sizeof(x) / sizeof(*x);

	// draw rectangles 4
	for (int i = 0; i < sizeof(x) / sizeof(*x); i++) {
		Rect rect(0 + x[i] + xShift, yMax - dy - y[i] - yShift, dx, dy);  // (x, y, width, height)
		rectangle(image, rect, Scalar(z[i], z[i], 255 - z[i]), -1, LINE_4); // Scalar(Blue,Green,Red)  -1:fill
	}

	//axis
	Point x0(xShift, yMax - yShift);
	Point x1(xMax - xMaxShift, yMax - yShift);
	Point y0(xShift, yMax - yShift);
	Point y1(xShift, yMaxShift);
	axis(x0, x1, y0, y1, image);

	//Show image
	imshow("Map", image);
	imwrite("Rect3b.jpg",image);
	waitKey();

}