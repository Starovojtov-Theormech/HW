#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    string file_name = "in.txt";

    double rightcos, leftcos;
    rightcos = leftcos = 1;

    int x0, y0;
    int x, y, Rightmost_x, Rightmost_y, Leftmost_x, Leftmost_y;

    std::ifstream infile(file_name);
    infile >> x0 >> y0;

        while (infile >> x >> y) {

            double coss = (x0 * x + y0 * y) / (sqrt(x * x + y * y) * sqrt(x0 * x0 + y0 * y0));
            coss = std::round(coss * 10000000000.0) / 10000000000.0;


            if (coss <= leftcos && (y0 * x < x0 * y)) {
                Leftmost_x = x;
                Leftmost_y = y;
                leftcos = coss;
            }

            if (coss <= rightcos && (y0 * x > x0 * y)) {
                Rightmost_x = x;
                Rightmost_y = y;
                rightcos = coss;

            }
        }

    cout << "Leftmost: " << Leftmost_x << " " << Leftmost_y << endl;
    cout << "Rightmost: " << Rightmost_x << " " << Rightmost_y << endl;
}
