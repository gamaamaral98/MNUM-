// Chapter3.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

double funC(double C, double T) {
	return -exp(-0.1 / (T + 273))*C;
}

double funT(double C, double T) {
	return 15.0*exp(-0.1 / (T + 273))*C - 0.1*(T - 20);
}

//------------------METODO DE EULER

void euler() {
	double t = 0.5;
	double C = 2.0;
	double T = 20.0;
	double h = 0.25;

	for (unsigned int i = 0; i < 2; i++) {

		//cout << fixed << setprecision(4) << "iter = " << i << "\tt = " << t << "\tC = " << C << "\tT = " << T << endl;

		double oldC = C;
		C += h*funC(C, T);
		T += h*funT(oldC, T);
		t += h;
	}
	double C0 = C;
	cout << fixed << setprecision(4) << "h = " << h << "\tC = " << C0 << endl;

	//////////////////

	t = 0.5;
	C = 2.0;
	T = 20.0;
	double h1 = h/2;

	for (unsigned int i = 0; i < 4; i++) {

		//cout << fixed << setprecision(4) << "iter = " << i << "\tt = " << t << "\tC = " << C << "\tT = " << T << endl;

		double oldC = C;
		C += h1*funC(C, T);
		T += h1*funT(oldC, T);
		t += h1;
	}
	double C1 = C;
	cout << fixed << setprecision(4) << "h1 = " << h1 << "\tC1 = " << C1 << endl;

	//////////////////

	t = 0.5;
	C = 2.0;
	T = 20.0;
	double h2 = h1/2;

	for (unsigned int i = 0; i < 8; i++) {

		//cout << fixed << setprecision(4) << "iter = " << i << "\tt = " << t << "\tC = " << C << "\tT = " << T << endl;

		double oldC = C;
		C += h2*funC(C, T);
		T += h2*funT(oldC, T);
		t += h2;
	}
	double C2 = C;
	cout << fixed << setprecision(4) << "h2 = " << h2 << "\tC2 = " << C2 << endl;

	double QC = (C1 - C0) / (C2 - C1);
	double Erro = (C2 - C1);
	cout << fixed << setprecision(4) << "QC = " << QC << "\tErro = " << Erro << endl;
}

//------------------METODO RUNGE-KUTTA

void rungeKutta() {
	double t = 0.5, C = 2.0, T = 20.0, h = 0.25;
	double c1, c2, c3, c4, t1, t2, t3, t4;

	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(4) << "iter = " << i << "\tt = " << t << "\tC = " << C << "\tT = " << T << endl;
		
		c1 = h*funC(C, T);
		t1 = h*funT(C, T);

		c2 = h*funC(C + (c1 / 2.0), T + (t1 / 2.0));
		t2 = h*funT(C + (c1 / 2.0), T + (t1 / 2.0));

		c3 = h*funC(C + (c2 / 2.0), T + (t2 / 2.0));
		t3 = h*funT(C + (c2 / 2.0), T + (t2 / 2.0));

		c4 = h*funC(C + c3, T + t3);
		t4 = h*funT(C + c3, T + t3);

		C += (c1 / 6.0) + (c2 / 3.0) + (c3 / 3.0) + (c4 / 6.0);
		T += (t1 / 6.0) + (t2 / 3.0) + (t3 / 3.0) + (t4 / 6.0);

		t += h;
	}
}

//------------------METODO DE EULER

double fun(double T) {
	return -0.25*(T - 64);
}

void euler2() {
	double T = 0.0;
	double t = 4;
	double h = 0.5;
	for (unsigned int i = 0; i < 3; i++) {

		cout << T << endl;
		T += h*fun(T);
		t += h;
	
	}
}

//---------------EULER E RUNGE COM EQUAÇAO DIFERENCIAL DE 2 ORDEM

double funZ(double t, double z) {
	return 0.5 + pow(t, 2) + t*z;
}

double funY(double z) {
	return z;
}

//EULER
void euler3() {
	double t = 0.0, y = 0.0, z = 1.0;
	double h = 0.25;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << "t = " << t << "\ty = " << y << endl;
		double oldZ = z;
		z += h*funZ(t, z);
		y += h*funY(oldZ);
		t += h;
	}
}

//RUNGE-KUTTA
void rungeKutta2() {
	double t = 0.0, y = 0.0, z = 1.0;
	double h = 0.25;
	double z1, z2, z3, z4, y1, y2, y3, y4;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << "t = " << t << "\ty = " << y << endl;

		z1 = h*funZ(t, z);
		y1 = h*funY(z);

		z2 = h*funZ(t + h / 2.0, z + z1 / 2.0);
		y2 = h*funY(z + z1 / 2.0);

		z3 = h*funZ(t + h / 2.0, z + z2 / 2.0);
		y3 = h*funY(z + z2 / 2.0);

		z4 = h*funZ(t + h, z + z3);
		y4 = h*funY(z + z3);

		y += y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6;
		z += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;
		t += h;
	}
}

int main()
{
	//euler();
	//rungeKutta();
	//euler2();
	euler3();
	//rungeKutta2();
    return 0;
}

