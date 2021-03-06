﻿// Exame2012_2013.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

//EX4

double fun1(double x) {
	return exp(1.5*x);
}

void simpson() {
	double a = 1.0, b = 1.5;
	double h = 0.125;
	int n = (b - a) / h;
	double somatorio = fun1(a) + fun1(b);
	double x = a + h;

	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2.0 * fun1(x);
			
		}
		else {
			somatorio += 4.0 * fun1(x);
		}

		x += h;
	}
	double resultado = (h / 3.0)*somatorio;
	cout << h << "\t\t" << resultado << endl;

	a = 1.0, b = 1.5;
	double h1 = h/2;
	n = (b - a) / h1;
	somatorio = fun1(a) + fun1(b);
	x = a + h1;

	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2.0 * fun1(x);

		}
		else {
			somatorio += 4.0 * fun1(x);
		}

		x += h1;
	}
	double resultado1 = (h1 / 3.0)*somatorio;
	cout << h1 << "\t\t" << resultado1 << endl;

	a = 1.0, b = 1.5;
	double h2 = h1/2;
	n = (b - a) / h2;
	somatorio = fun1(a) + fun1(b);
	x = a + h2;

	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2.0 * fun1(x);

		}
		else {
			somatorio += 4.0 * fun1(x);
		}

		x += h2;
	}
	double resultado2 = (h2 / 3.0)*somatorio;
	cout << h2 << "\t\t" << resultado2 << endl;

	double QC = (resultado1 - resultado) / (resultado2 - resultado1);
	double Erro = (resultado2 - resultado1)/15;

	cout << fixed << setprecision(5) << QC << "\t\t" << Erro << endl;
}

//EX5

double fun2(double x) {
	return (x - 3.7) + pow((cos(x + 1.2)), 3);
}
double fun2d(double x) {
	return 1 - 3 * pow(cos(x + 1.2), 2)*sin(x + 1.2);
}

void newton() {
	double x = 3.8;
	for (unsigned int i = 0; i < 2; i++) {
		cout << x << endl;
		x = x - fun2(x) / fun2d(x);
	}
}

//EX2

double fung(double x, double y) {
	return 3 * pow(x, 2) - x*y + 11 * y + pow(y, 2) - 8 * x;
}

double fungx(double x, double y) {
	return -y + 6 * x - 8;
}

double fungy(double x, double y) {
	return 2 * y - x + 11;
}

void gradient() {
	double x = 2.0, y = 2.0;
	double h = 0.5;
	double oldx = x, oldy = y;

	for (unsigned int i = 0; i < 2; i++) {
		cout << fixed << setprecision(6) << "i = " << i << "\tX = " << x << "\tY = " << y << "\tfung(x,y) = " << fung(x, y) << "\tfungx(x,y) = " << fungx(x, y) << "\tfungy(x,y) = " << fungy(x, y) << endl;
		x = x - h*fungx(x, y);
		y = y - h*fungy(oldx, y);

		if (fung(x, y) >= fung(oldx, oldy)) {
			h = h / 2;
		}
		else {
			h = h * 2;
		}
	}
}

int main()
{
	//simpson();
	//newton();
	//gradient();
    return 0;
}

