// Exame2009.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

//EX1

double f(double x) {
	return (x - 2.6) + pow(cos(x + 1.1), 3.0);
}

double flinha(double x) {
	return 1.0 - 3.0 * pow(cos(x + 1.1), 2.0)*sin(x + 1.1);
}

void ex1() {
	double x = 1.8;
	for (unsigned int i = 0; i < 2; i++) {
		cout << x << endl;

		x = x - f(x) / flinha(x);
	}
}

//EX4

double g(double x) {
	return 5 * cos(x) - sin(x);
}

void ex4() {
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x1 = 2.0, x2 = 4.0;
	double x3, x4;
	for (unsigned int i = 0; i < 3; i++) {
		x3 = x1 + A*(x2 - x1);
		x4 = x1 + B*(x2 - x1);

		cout << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << g(x1) << "\t" << g(x2) << "\t" << g(x3) << "\t" << g(x4) << endl;

		if (g(x3) < g(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
	}
}

//EX5

double fun(double t, double x) {
	return sin(1.0*x) + sin(2.0*t);
}

void ex5() {
	double h = 0.125;
	double t = 1.0, x = 1.0;
	double d1, d2, d3, d4;
	for (unsigned int i = 0; i < 5; i++) {

		cout << "t = " << t << "\tx = " << x << endl;

		d1 = h*fun(t, x);
		d2 = h*fun(t + (h / 2.0), x + (d1 / 2.0));
		d3 = h*fun(t + (h / 2.0), x + (d2 / 2.0));
		d4 = h*fun(t + h, x + d3);

		x += (d1 / 6.0) + (d2 / 3.0) + (d3 / 3.0) + (d4 / 6.0);
		t += h;
	}
}

int main()
{
	cout << fixed;
	//cout << setprecision(5);

	//ex1();
	//ex4();
	//ex5();
    return 0;
}

