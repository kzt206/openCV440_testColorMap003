#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

void testRect3();
void testContour1();
void testContour2();
int testReadData(double *x, double *y, double *z);

int main()
{

	//testRect3();
	//testContour2();

	double x[10000], y[10000], z[10000];
	testReadData(x,y,z);

    for (int i = 0; i < 4;i++) {
        cout << x[i] << ',' << y[i] << ',' << z[i] << endl;
    }


	return 0;

}

int testReadData(double *x, double *y, double *z) {
    std::ifstream ifs("C:\\Users\\kzt20\\source\\repos\\openCV440_testColorMap003\\openCV440_testColorMap003\\testdata.txt");
    std::string str,s;

    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        return -1;
    }

    int i = 0;
    
    while (getline(ifs, str)) {
        std::cout  << str << std::endl;
        stringstream ss{ str };
        vector<string> v;
        while(getline(ss, s, ' ')) {
            v.push_back(s);
        }
        
        /*for (const string& s : v) {
            cout << s << endl;
        }*/

        x[i] = stod(v[0]);
        y[i] = stod(v[1]);
        z[i] = stod(v[2]);


        i++;
    }

    ifs.close();

}