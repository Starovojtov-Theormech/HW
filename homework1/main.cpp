#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	string input_name;

	if (argc == 2)
	{
		input_name = argv[1];
	}
	else {
		input_name = "in.txt";
	}
	ifstream input_file(input_name);

	int x, y, x0, y0, xl = 0, yl = 0, xr = 0, yr = 0;

	double cosr = 1, cosl = 1, cos;

	input_file >> x0 >> y0;

	while (input_file >> x >> y)
	{
		cos = (x0*x + y0 * y) / (sqrt(x*x + y * y)*sqrt(x0*x0 + y0 * y0));
		cos = round(cos * 1000.0) / 1000.0;
		if (cos <= cosl && (y0*x < x0*y))
		{
			cosl = cos;
			xl = x; yl = y;
		}
		if (cos <= cosr && (y0*x >= x0 * y))
		{
			cosr = cos;
			xr = x; yr = y;
		}
	}

	cout << "Leftmost: " << xl << " " << yl << endl;
	cout << "Rightmost: " << xr << " " << yr << endl;
}
