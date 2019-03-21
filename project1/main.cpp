#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
ofstream fileOut("output.txt");

struct Triangle {
    double x;
    double y;
    double z;
};

void calculateBisectors(double x, double y, double z) {
    if((x > y+z) || (y > x+z) || (z > x+y)) {
        cout << "The triangle with such parties does not exist" << endl;
    } else {
        double bisector1 = sqrt(x*y*(x+y+z)*(x+y-z))/(x+y);
        double bisector2 = sqrt(y*z*(y+z+x)*(y+z-x))/(y+z);
        double bisector3 = sqrt(z*x*(z+x+y)*(z+x-y))/(z+x);

        cout << bisector1 << " " <<bisector2 << " " << bisector3 <<endl;
    }
};

void calculateBisectorsFile(double x, double y, double z) {
    if((x > y+z) || (y > x+z) || (z > x+y)) {
        cout << "0.0 0.0 0.0" << endl;
    } else {
        double bisector1 = sqrt(x*y*(x+y+z)*(x+y-z))/(x+y);
        double bisector2 = sqrt(y*z*(y+z+x)*(y+z-x))/(y+z);
        double bisector3 = sqrt(z*x*(z+x+y)*(z+x-y))/(z+x);

        fileOut << bisector1 << " " <<bisector2 << " " << bisector3 << endl;
    }
};

int main()
{
    double x = 2.0, y = 3.0, z = 4.0;
    calculateBisectors(x, y, z);

    int n = 0;
    ifstream fileIn;
    fileIn.open("input.txt");
    fileIn >> n;
    double sides[n][3];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            fileIn >> sides[i][j];
    fileIn.close();
    for(int i = 0; i < n; i++) {
        calculateBisectorsFile(sides[i][0], sides[i][1], sides[i][2]);
        //calculateBisectors(sides[i][0], sides[i][1], sides[i][2]);
    }
    fileOut.close();

    return 0;

    /*
    const int n = 5;
        Triangle *triangles = new Triangle[n];
        for(int i = 0; i < n; i++) {
            triangles[i].x = 3;
            triangles[i].y = 4;
            triangles[i].z = 5;
            calculateBisectors(triangles[i].x, triangles[i].y, triangles[i].z);
        }
     */

}
