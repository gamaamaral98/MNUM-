// Exame1314.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//EX 2

double fun1(double x) {
	return -x + 40.0 * cos(sqrt(x)) + 3.0;
}

double fun1d(double x) {
	return -(20.0*sin(sqrt(x)) / sqrt(x)) - 1;
}

void ex2() {
	double x = 1.7;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(4) << x << "\t\tg(x) = " << fun1(x) << endl;
		x = x - fun1(x) / fun1d(x);
	}
}

//EX5 secçao aurea ainda não sei fazer.

//EX7

double fun2(double x) {
	return pow(4.0 * pow(x, 3.0) - x + 3.0, 1.0 / 4.0);
}

void ex7() {
	double x = 3.5;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(5) << "it = " << i << "\t x = " << x << endl;
		x = fun2(x);
	}
}

int main()
{
	//ex2();
	//ex7();
    return 0;
}

