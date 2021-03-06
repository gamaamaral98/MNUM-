// Chapter2.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

//----------------------METODO DE SIMPSON

float fun1(float x) {
	return exp(1.5*x);
}

void simpson() {
	float a = 1.0, b = 1.5, h = 0.125;
	float somatorio = fun1(a) + fun1(b);
	int n = (b - a) / h;
	float x = a+h;
	for (unsigned int i = 1; i < n ; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun1(x);
		}
		else {
			somatorio += 4 * fun1(x);
		}
		x += h;
	}
	float resultado = (h / 3) * somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tS = " << resultado << endl;

	float h1 = h / 2;
	x = a;
	somatorio = fun1(a) + fun1(b);
	x += h1;
	n = (b - a) / h1;

	for (unsigned int i = 1; i < n; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun1(x);
		}
		else {
			somatorio += 4 * fun1(x);
		}
		x += h1;
	}
	float resultado1 = (h1 / 3) * somatorio;
	cout << fixed << setprecision(5) << "h1 = " << h1 << "\tS1 = " << resultado1 << endl;


	float h2 = h1 / 2;
	x = a;
	somatorio = fun1(a) + fun1(b);
	x += h2;
	n = (b - a) / h2;

	for (unsigned int i = 1; i < n; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun1(x);
		}
		else {
			somatorio += 4 * fun1(x);
		}
		x += h2;
	}
	float resultado2 = (h2 / 3) * somatorio;
	cout << fixed << setprecision(5) << "h2 = " << h2 << "\tS2 = " << resultado2 << endl;

	float QC = (resultado1 - resultado) / (resultado2 - resultado1);
	float Erro = (resultado2 - resultado1) / 15;

	cout << fixed << setprecision(5) << "QC = " << QC << endl;
	cout << fixed << setprecision(5) << "Erro = " << Erro << endl;
}

//----------------------METODO DOS TRAPEZIOS

float fun2(float x) {
	return sqrt(1 + pow(2 * (exp(2 * x)), 2));
}

void trapezio() {
	float a = 0.0, b = 1.0, h = 0.25;
	float x = a + h;
	int n = (b - a) / h;
	float somatorio = fun2(a) + fun2(b);

	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun2(x);
		x += h;
	}

	float resultado = (h / 2)*somatorio;
	cout << fixed << setprecision(6) << "L1 = " << resultado << endl;


	a = 0.0, b = 1.0; 
	float h1 = h/2;
	x = a + h1;
	n = (b - a) / h1;
	somatorio = fun2(a) + fun2(b);

	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun2(x);
		x += h1;
	}

	float resultado1 = (h1 / 2)*somatorio;
	cout << fixed << setprecision(6) << "L2 = " << resultado1 << endl;


	a = 0.0, b = 1.0;
	float h2 = h1/2;
	x = a + h2;
	n = (b - a) / h2;
	somatorio = fun2(a) + fun2(b);

	for (unsigned int i = 1; i < n; i++) {
		somatorio += 2 * fun2(x);
		x += h2;
	}

	float resultado2 = (h2 / 2)*somatorio;
	cout << fixed << setprecision(6) << "L3 = " << resultado2 << endl;

	float QC = (resultado1 - resultado) / (resultado2 - resultado1);
	float Erro = (resultado2 - resultado1) / 3;

	cout << fixed << setprecision(6) << "QC = " << QC << "\tError = " << Erro << endl;
	
}

//METODO DE SIMPSON

void simpson2() {
	float a = 0.0, b = 1.0, h = 0.25;
	float somatorio = fun2(a) + fun2(b);
	int n = (b - a) / h;
	float x = a + h;
	for (unsigned int i = 1; i < n; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun2(x);
		}
		else {
			somatorio += 4 * fun2(x);
		}
		x += h;
	}
	float resultado = (h / 3) * somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tS = " << resultado << endl;

	////////////////////////////////////////////////////////////////////////

	float h1 = h/2;
	somatorio = fun2(a) + fun2(b);
	n = (b - a) / h1;
	x = a + h1;
	for (unsigned int i = 1; i < n; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun2(x);
		}
		else {
			somatorio += 4 * fun2(x);
		}
		x += h1;
	}
	float resultado1 = (h1 / 3) * somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tS1 = " << resultado1 << endl;


	////////////////////////////////////////////////////////////////////////

	float h2 = h1/2;
	somatorio = fun2(a) + fun2(b);
	n = (b - a) / h2;
	x = a + h2;
	for (unsigned int i = 1; i < n; i++) {

		if (i % 2 == 0) {
			somatorio += 2 * fun2(x);
		}
		else {
			somatorio += 4 * fun2(x);
		}
		x += h2;
	}
	float resultado2 = (h2 / 3) * somatorio;
	cout << fixed << setprecision(5) << "h = " << h << "\tS2 = " << resultado2 << endl;
	
	float QC = (resultado1 - resultado) / (resultado2 - resultado1);
	float Error = (resultado2 - resultado1) / 15;

	cout << fixed << setprecision(5) << "QC = " << QC << "\tError = " << Error << endl;
	
}

//-------------------------CUBATURA SIMPSON E TRAPEZIO

void cubaturaSimpson() {
	float vertices = 6.3 + 1.2 + 2.6 + 1.1;
	float medios = 1.5 + 1.4 + 2.1 + 2.2;
	float centro = 4.9;
	float hx = (1.8 - 0) / 2;
	float hy = (1.8 - 0) / 2;

	float somatorio = ((hx*hy) / 9) * (vertices + 4 * medios + 16 * centro);
	cout << fixed << setprecision(2) << somatorio << endl;
}

void cubaturaTrapezio() {
	float vertices = 5.3 + 1.2 + 1.1 + 2.2;
	float medios = 1.5 + 1.4 + 2.2 + 2.1;
	float centro = 1.1;
	float hx = (2 - 0) / 2;
	float hy = (2 - 0) / 2;

	float somatorio = ((hx*hy) / 4) * (vertices + 2 * medios + 4 * centro);
	cout << fixed << setprecision(2) << somatorio << endl;
}


int main()
{
	//simpson();
	//trapezio();
	//simpson2();
	//cubaturaSimpson();
	//cubaturaTrapezio();
    return 0;
}

