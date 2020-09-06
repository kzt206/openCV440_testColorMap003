#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

void testRect3();
void testContour1();
void testContour2();
int testReadData(string infile,double *x, double *y, double *z);
void colorMap1(int numData,double x[],double y[],double z[]);

int main()
{

	//testRect3();
	//testContour2();

	double x[10000], y[10000], z[10000];
	string infile = "C:\\Users\\kzt20\\source\\repos\\openCV440_testColorMap003\\openCV440_testColorMap003\\testdata2.txt";
	int numData = testReadData(infile,x,y,z);

    for (int i = 0; i < numData;i++) {
        cout << x[i] << ',' << y[i] << ',' << z[i] << endl;
    }

	colorMap1(numData,x, y, z);

	return 0;

}