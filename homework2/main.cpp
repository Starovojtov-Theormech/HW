#include <fstream>
#include <iostream>
#include "functions.h"
#include <cmath>
#include <valarray>
#include <vector>


using namespace std;


int main(int argc, char** argv) {
    string file_name = "";

    if (argc == 2) {
        file_name = string(argv[1]);
    }

    vector <Barrier> Barriers;
    double h;
    Vector2D V{};
    Barrier B;

    ifstream file(file_name);
    file >> h;
    file >> V.x >> V.y;

    while (file >> B.x >> B.h) {
        Barriers.push_back(B);
    }
    int l = Barriers.size();
    file.close();


    const double g = 9.81;
    Point Point{};
    Point.x = 0;
    Point.y = h;
    int cur_bar = -1;
    int direction = 1;


    while (true) {

        int m = cur_bar + direction;
        if (m < 0) {
            cout << 0;
            return 0;
        }
        if (m > l-1) {
            cout << l;
            return 0;
        }

        double x = Barriers[m].x;
        double bar = Barriers[m].h;
        double t = abs((x - Point.x)) / abs(V.x);
        double fall_time = (V.y + sqrt(V.y*V.y+2*g*Point.y))/g;


        if (fall_time < t) {
            if (direction == 1) cout << m;
            else cout << m + 1;
            return 0;

        }
        double y = Point.y + V.y * t - (g * t * t) / 2;

        V.y = V.y-g*t;
        Point.x = x;
        Point.y = y;
        cur_bar = m;

        if (y < bar) {
            V.x = -V.x;
            direction = V.x/abs(V.x);
        }
    }
}
