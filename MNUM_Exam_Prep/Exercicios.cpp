// ConsoleApplication6.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//EX1
double temperatura(double t, double T) {
	return -0.25*(T - 37.0);
}

void ex1() {
	double T = 3.0, t = 5.0;
	double h = 0.4;

	for (unsigned int i = 0; i < 3; i++) {
		cout << T << endl;
		T += h*temperatura(t, T);
		t += h;
	}
}

//EX4

double fun(double x) {
	return 2*log(2*x);
}

void ex4() {
	double x = 1.1;
	for (unsigned int i = 0; i < 2; i++) {
		cout << x << endl;
		x = fun(x);
	}
}

//EX5

double func(double x) {
	return sqrt(1 + pow(2.5*exp(2.5*x), 2));
}

void ex5T() {
	double a = 0.0, b = 1.0;
	double h1 = 0.125;
	int n = (b - a) / h1;
	double somatorio = func(a) + func(b);
	double x = a + h1;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * func(x);
		x += h1;
	}
	double res1 = somatorio *(h1 / 2);
	cout << "h1 = " << h1 << "\tL1 = " << res1 << endl;

	a = 0.0, b = 1.0;
	double h2 = h1/2;
	n = (b - a) / h2;
	somatorio = func(a) + func(b);
	x = a + h2;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * func(x);
		x += h2;
	}
	double res2 = somatorio *(h2 / 2);
	cout << "h2 = " << h2 << "\tL2 = " << res2 << endl;

	a = 0.0, b = 1.0;
	double h3 = h2 / 2;;
	n = (b - a) / h3;
	somatorio = func(a) + func(b);
	x = a + h3;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * func(x);
		x += h3;
	}
	double res3 = somatorio *(h3 / 2);
	cout << "h3 = " << h3 << "\tL3 = " << res3 << endl;

	double QC = (res2 - res1) / (res3 - res2);
	double Error = (res3 - res2) / 3;

	cout << QC << "\t\t" << Error << endl;

}

void ex5S() {
	double a = 0.0, b = 1.0;
	double h1 = 0.125;
	int n = (b - a) / h1;
	double somatorio = func(a) + func(b);
	double x = a + h1;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * func(x);
		}
		else {
			somatorio += 4 * func(x);
		}
		x += h1;
	}
	double res1 = somatorio *(h1 / 3);
	cout << "h1 = " << h1 << "\tL1 = " << res1 << endl;

	a = 0.0, b = 1.0;
	double h2 = h1/2;
	n = (b - a) / h2;
	somatorio = func(a) + func(b);
	x = a + h2;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * func(x);
		}
		else {
			somatorio += 4 * func(x);
		}
		x += h2;
	}
	double res2 = somatorio *(h2 / 3);
	cout << "h2 = " << h2 << "\tL2 = " << res2 << endl;

	a = 0.0, b = 1.0;
	double h3 = h2 / 2;
	n = (b - a) / h3;
	somatorio = func(a) + func(b);
	x = a + h3;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * func(x);
		}
		else {
			somatorio += 4 * func(x);
		}
		x += h3;
	}
	double res3 = somatorio *(h3 / 3);
	cout << "h3 = " << h3 << "\tL3 = " << res3 << endl;

	double QC = (res2 - res1) / (res3 - res2);
	double Error = (res3 - res2) / 15;
	cout << QC << "\t\t " << Error << endl;
}

//EX7

double fun7(double x) {
	return x*x*x - 10 * sin(x) + 2.8;
}

double m(double a, double b) {
	return (a + b) / 2;
}

void ex7() {
	double a = 1.5, b = 4.2;
	for (unsigned int i = 0; i < 3; i++) {
		cout << m(a, b) << endl;
		if (fun7(a)*fun7(m(a, b)) < 0) {
			b = m(a, b);
		}
		else {
			a = m(a, b);
		}
	}
}


//AUREA

double fa(double x) {
	return 5 * cos(x) - sin(x);
}

void aurea() {
	double x1 = 2.0, x2 = 4.0, x3, x4;
	double B = (sqrt(5) - 1) / 2;
	double A = B*B;

	for (unsigned int i = 0; i < 3; i++) {
		x3 = x1 + A*(x2 - x1);
		x4 = x1 + B*(x2 - x1);
		cout << x1 << "\t\t" << x2 << "\t\t" << x3 << "\t\t" << x4 << "\t\t" << fa(x1) << "\t\t" << fa(x2) << "\t\t" << fa(x3) << "\t\t" << fa(x4) << endl;
		if (fa(x3) < fa(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
	}

}

//GRADIENTE

double Z(double x, double y) {
	return 6 * x*x - x*y + 12 * y + y*y - 8 * x;
}

double Zdx(double x, double y) {
	return -y + 12 * x - 8;
}

double Zdy(double x, double y) {
	return 2 * y - x + 12;
}

void gradiente() {
	double x = 0, y = 0;
	double h = 0.25;
	for (unsigned int i = 0; i < 2; i++) {
		cout << "x = " << x << "\ty = " << y << "\tZ(x,y) = " << Z(x, y) << "\tGradiente = " << Zdx(x, y) << "\t//\t" << Zdy(x, y) << "\t\tLambda = " << h << endl;
		double oldx = x;
		double oldy = y;
		x = x - h*Zdx(x, y);
		y = y - h*Zdy(oldx, y);

		if (Z(x, y) < Z(oldx, oldy)) {
			h = 2 * h;
		}
		else {
			h = h / 2;
		}
	}
}

//GRADIENTE2

double W(double x, double y) {
	return -1.7*x*y + 12 * y + 7 * x*x - 8 * x;
}

double Wdx(double x, double y) {
	return -1.7*y + 14 * x - 8;
}

double Wdy(double x, double y) {
	return 12 - 1.7*x;
}

void gradiente2() {
	double x0 = 2.4, y0 = 4.3;
	double h = 0.1;
	double x, y;

	x = x0 - h*Wdx(x0, y0);
	y = y0 - h*Wdy(x0, y0);

	cout << W(x, y) << endl;
}

//EULER e RUNGE KUTTA

double Z1(double t, double z) {
	return 1.0 + t*t + t*z;
}

double Y(double z) {
	return z;
}

void euler() {
	double h = 0.5, t = 0.0, y = 1.0, z = 2.0;
	for (unsigned int i = 0; i < 3; i++) {
		cout << "n = " << i << "\tt = " << t << "\ty = " << y << endl;

		y += h*Y(z);
		z += h*Z1(t, z);

		t += h;
	}
}

void RungeKutta() {
	double h = 0.5, t = 0.0, y = 1.0, z = 2.0;
	double z1, z2, z3, z4, y1, y2, y3, y4;
	for (unsigned int i = 0; i < 3; i++) {
		cout << "n = " << i << "\tt = " << t << "\ty = " << y << endl;

		z1 = h*Z1(t, z);
		y1 = h*Y(z);

		z2 = h*Z1(t + (h / 2.0), z + (z1 / 2.0));
		y2 = h*Y(z + (z1 / 2.0));
		
		z3 = h*Z1(t + (h / 2.0), z + (z2 / 2.0));
		y3 = h*Y(z + (z2 / 2.0));

		z4 = h*Z1(t + h, z + z3);
		y4 = h*Y(z + z3);

		y += (y1 / 6.0) + (y2 / 3.0) + (y3 / 3.0) + (y4 / 6.0);
		z += (z1 / 6.0) + (z2 / 3.0) + (z3 / 3.0) + (z4 / 6.0);

		t += h;
	}
}


int main()
{
	cout << fixed;
	cout << setprecision(5);
	//ex1();
	//ex4();
	//ex5T();
	//ex5S();
	//ex7();
	//aurea();
	//gradiente();
	gradiente2();
	//euler();
	//RungeKutta();
    return 0;
}

