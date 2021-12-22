#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// Считывание параметров столбов
void Column(ifstream &input_file, vector<double> &X, vector<double> &H) 
{
	double x, h;
	input_file >> x >> h;
	X.push_back(x);
	H.push_back(h);
}


//Вычисления
void Math2(double x0, double h0, double vx, double vy, vector<double> &X, vector<double> &H, int &zone,
	int dir)
{
	double y, t;

	for (int i = zone; (i > -1 && i < X.size()); i = i + dir) {
		if (i == -1)
		{
			break;
		}
		t = (X[i + dir] - x0) / (dir*vx);
		y = h0 + vy * t - 9.81 / 2 * pow(t, 2);
		if (H[i + dir] < y)
		{
			zone += dir;
		}
		else if ((y < 0) || (zone == 0))
		{

		}
		else
		{
			double vyt = vy - 9.81*t;
			dir = dir * -1;
			Math2(X[i], y, vx, vyt, X, H, zone, dir);
			return;
		}
	}
}

void Math1(ifstream &input_file, double &h0, double &vx, double &vy, vector<double> &X, vector<double> &H,
	int &zone)
{
	string line;
	double t, y;

	while (getline(input_file, line))
	{
		Column(input_file, X, H);
		t = (X.back() - 0) / (vx);
		y = h0 + vy * t - 9.81 / 2 * pow(t, 2);
		if (H.back() < y)
		{
			zone++;
		}
		else if ((y < 0) || (zone == 0))
		{
			return;
		}
		else
		{
			double vyt = vy - 9.81*t;
			Math2(X.back(), y, vx, vyt, X, H, zone, -1);
			return; 
		}
	}
}


int main(int argc, char** argv)
{
	string input_name;

	if (argc == 2)
	{
		input_name = argv[1];
	}
	else {
		input_name = "input.txt";
	}
	ifstream input_file(input_name);

	double h0, vx, vy;

	int zone = 0, i = 0;

	string line;

	// Координаты и высоты столбов
	vector<double> X;
	vector<double> H;

	// Получение начальных значений
	input_file >> h0;
	input_file >> vx >> vy;

	Math1(input_file, h0, vx, vy, X, H, zone);

	cout << zone << endl;
	return 0;
}
