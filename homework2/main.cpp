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

    vector <Wall> Walls;
    double h;
    Skorost V{};
    Wall B;

    ifstream file(file_name);
    file >> h;
    file >> V.x >> V.y;

    while (file >> B.x >> B.h) {
        Walls.push_back(B);
    }
    int l = Walls.size();
    file.close();


    const double g = 9.81;
    Tochka Tochka{};
    Tochka.x = 0;
    Tochka.y = h;
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

        double x = Walls[m].x;
        double bar = Walls[m].h;
        double t = abs((x - Tochka.x)) / abs(V.x);
        double fall_time = (V.y + sqrt(V.y*V.y+2*g*Tochka.y))/g;


        if (fall_time < t) {
            if (direction == 1) cout << m;
            else cout << m + 1;
            return 0;

        }
        double y = Tochka.y + V.y * t - (g * t * t) / 2;

        V.y = V.y-g*t;
        Tochka.x = x;
        Tochka.y = y;
        cur_bar = m;

        if (y < bar) {
            V.x = -V.x;
            direction = V.x/abs(V.x);
        }
    }
}
