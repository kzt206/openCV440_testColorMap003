#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;

void axis(Point x0, Point x1, Point y0, Point y1, Mat& image);


int ColorScaleBCGYR(double in_value)
{
	// 0.0～1.0 の範囲の値をサーモグラフィみたいな色にする
	// 0.0                    1.0
	// 青    水    緑    黄    赤
	// 最小値以下 = 青
	// 最大値以上 = 赤
	int ret;
	int a = 255;    // alpha値
	int r, g, b;    // RGB値
	double  value = in_value;
	double  tmp_val = cos(4 * 3.1415 * value);
	int     col_val = (int)((-tmp_val / 2 + 0.5) * 255);
	if (value >= (4.0 / 4.0)) { r = 255;     g = 0;       b = 0; }   // 赤
	else if (value >= (3.0 / 4.0)) { r = 255;     g = col_val; b = 0; }   // 黄～赤
	else if (value >= (2.0 / 4.0)) { r = col_val; g = 255;     b = 0; }   // 緑～黄
	else if (value >= (1.0 / 4.0)) { r = 0;       g = 255;     b = col_val; }   // 水～緑
	else if (value >= (0.0 / 4.0)) { r = 0;       g = col_val; b = 255; }   // 青～水
	else { r = 0;       g = 0;       b = 255; }   // 青
	ret = (a & 0x000000FF) << 24
		| (r & 0x000000FF) << 16
		| (g & 0x000000FF) << 8
		| (b & 0x000000FF);
	return ret;
}


void ColorScaleBCGYR(int &r,int &g,int &b,int z)
{
	// 0.0～1.0 の範囲の値をサーモグラフィみたいな色にする
	// 0.0                    1.0
	// 青    水    緑    黄    赤
	// 最小値以下 = 青
	// 最大値以上 = 赤
	//int ret;
	int a = 255;    // alpha値
	//int r, g, b;    // RGB値
	double  value = z/255.;
	double  tmp_val = cos(4 * 3.1415 * value);
	int     col_val = (int)((-tmp_val / 2 + 0.5) * 255);
	if (value >= (4.0 / 4.0)) { r = 255;     g = 0;       b = 0; }   // 赤
	else if (value >= (3.0 / 4.0)) { r = 255;     g = col_val; b = 0; }   // 黄～赤
	else if (value >= (2.0 / 4.0)) { r = col_val; g = 255;     b = 0; }   // 緑～黄
	else if (value >= (1.0 / 4.0)) { r = 0;       g = 255;     b = col_val; }   // 水～緑
	else if (value >= (0.0 / 4.0)) { r = 0;       g = col_val; b = 255; }   // 青～水
	else { r = 0;       g = 0;       b = 255; }   // 青
	//ret = (a & 0x000000FF) << 24
	//	| (r & 0x000000FF) << 16
	//	| (g & 0x000000FF) << 8
	//	| (b & 0x000000FF);
	//return ret;
}

void testContour1() {

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
	const int dx = 5;
	const int dy = 5;


	Mat image(yMax, xMax, CV_8UC3);


	// fill with white
	image = Scalar(255, 255, 255);  // Blue,Green,Red


	// input data
	const int numberData = xLength / dx;
	const int numberData2 = numberData * numberData;
	int x[numberData2], y[numberData2], z[numberData2];
	double zd[numberData2];
	//int wave[numberData][numberData];
	int n = 0;
	double minZ = 10000;
	double maxZ = 0;
	for (int i = 0; i < numberData; i++) {
		for (int j = 0; j < numberData; j++) {
			int tmpx = i * dx;
			int tmpy = j * dy;
			double tmpz =  pow(tmpx-250,2) + pow(tmpy,2);
			if (maxZ < tmpz) maxZ = tmpz;
			if (minZ > tmpz) minZ = tmpz;
			x[n] = tmpx;
			y[n] = tmpy;
			zd[n] = tmpz;
			n++;
			
		}
	}
	std::cout << sizeof(x) / sizeof(*x);
	
	//normarize
	n = 0;
	for (int i = 0; i < numberData; i++) {
		for (int j = 0; j < numberData; j++) {
			z[n] = int((zd[n] - minZ) / maxZ * 255);
			n++;
		}
	}

	int halfZ = 256/2;
	// draw rectangles 4
	for (int i = 0; i < sizeof(x) / sizeof(*x); i++) {
		Rect rect(0 + x[i] + xShift, yMax - dy - y[i] - yShift, dx, dy);  // (x, y, width, height)
		int r, g, b;
		/*if (z[i] < halfZ) {
			r = 0;
			g = int(255. / (halfZ - 0) * (z[i] - 0));
			b = int(255. - 255 / (halfZ - 0) * (z[i] - 0));
		}
		else {
			r = int(255. / (255-halfZ) * (z[i] - halfZ));
			g = int(255. - 255 / (255- halfZ) * (z[i] - halfZ));
			b = 0;
		}*/

		ColorScaleBCGYR(r, g, b, z[i]);

		Scalar color(b,g,r);
		rectangle(image, rect, color, -1, LINE_4); // Scalar(Blue,Green,Red)  -1:fill
	}

	//axis
	Point x0(xShift, yMax - yShift);
	Point x1(xMax - xMaxShift, yMax - yShift);
	Point y0(xShift, yMax - yShift);
	Point y1(xShift, yMaxShift);
	axis(x0, x1, y0, y1, image);

	//Show image
	imshow("Map", image);
	imwrite("contour1.jpg", image);
	waitKey();



}