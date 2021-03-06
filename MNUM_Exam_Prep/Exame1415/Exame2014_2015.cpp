// Exame2014_2015.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//EX 1

double fun1(double t, double T) {
	return -0.25*(T - 37);
}

void ex1() {
	double T = 3.0, t = 5.0;
	double h = 0.4;

	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(2) << T << endl;
		T += h*fun1(t, T);
		t += h;
	}
}

//EX 4

double fun2(double x) {
	return 2 * log(2 * x);
}

void ex4() {
	double x = 1.1;
	for (unsigned int i = 0; i < 2; i++) {
		cout << fixed << setprecision(5) << x << endl;
		x = fun2(x);
	}
	//Calcula resíduo: iteração numero dois menos a iteraçao numero 1;
}

//EX 5

double fun3(double x) {
	return sqrt(1 + pow((2.5*exp(2.5*x)), 2));
}

void ex5T() {
	float a = 0.0, b = 1.0;
	float h = 0.125;
	float somatorio = fun3(a) + fun3(b);
	float x = a + h;

	int n = (b - a) / h;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun3(x);
		x += h;
	}
	float resultado = (h / 2)*somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tL = " << resultado << endl;

	float h1 = h / 2;
	somatorio = fun3(a) + fun3(b);
	x = a + h1;
	n = (b - a) / h1;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun3(x);
		x += h1;
	}
	float resultado1 = (h1 / 2)*somatorio;
	cout << fixed << setprecision(5) << "h1 = " << h1 << "\tL1 = " << resultado1 << endl;

	float h2 = h1 / 2;
	somatorio = fun3(a) + fun3(b);
	x = a + h2;
	n = (b - a) / h2;
	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun3(x);
		x += h2;
	}
	float resultado2 = (h2 / 2)*somatorio;
	cout << fixed << setprecision(5) << "h2 = " << h2 << "\tL1 = " << resultado2 << endl;

	float QC = (resultado1 - resultado) / (resultado2 - resultado1);
	cout << fixed << setprecision(5) << "QC =" << QC << endl;

	float Error = (resultado2 - resultado1) / 3;
	cout << fixed << setprecision(5) << "Error = " << abs(Error) << endl;

}

void ex5S() {
	double a = 0.0, b = 1.0;
	double h = 0.125;
	double somatorio = fun3(a) + fun3(b);
	double x = a + h;

	int n = (b - a) / h;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * fun3(x);
		}
		else {
			somatorio += 4 * fun3(x);
		}
		x += h;
	}
	double resultado = (h / 3)*somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tL = " << resultado << endl;

	double h1 = h / 2;
	somatorio = fun3(a) + fun3(b);
	x = a + h1;
	n = (b - a) / h1;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * fun3(x);
		}
		else {
			somatorio += 4 * fun3(x);
		}
		x += h1;
	}
	double resultado1 = (h1 / 3)*somatorio;
	cout << fixed << setprecision(5) << "h1 = " << h1 << "\tL1 = " << resultado1 << endl;

	double h2 = h1 / 2;
	somatorio = fun3(a) + fun3(b);
	x = a + h2;
	n = (b - a) / h2;
	for (unsigned int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			somatorio += 2 * fun3(x);
		}
		else {
			somatorio += 4 * fun3(x);
		}
		x += h2;
	}
	double resultado2 = (h2 / 3)*somatorio;
	cout << fixed << setprecision(5) << "h2 = " << h2 << "\tL1 = " << resultado2 << endl;

	double QC = (resultado1 - resultado) / (resultado2 - resultado1);
	cout << fixed << "QC =" << QC << endl;

	double Error = (resultado2 - resultado1) / 15;
	cout << fixed << "Error = " << abs(Error) << endl;
}

//EX 7

double fun4(double x) {
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

double m(double a, double b) {
	return (a + b) / 2;
}

void ex7() {
	double a = 1.5, b = 4.2;
	for (unsigned int i = 0; i < 2; i++) {
		cout << fixed << setprecision(4) << "\t" << m(a, b) << endl;
		if (fun4(a)*fun4(b) < 0) {
			b = m(a, b);
		}
		else {
			a = m(a, b);
		}
	}
}


int main()
{
	//ex1();
	//ex4();
	//ex5T();
	//ex5S();
	//ex7();
    return 0;
}

