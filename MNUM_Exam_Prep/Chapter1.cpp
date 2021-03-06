// Chapter1.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

//----------------BISSECÇAO

float fun1(float x) {
	return pow(x, 3) - 10 * sin(x) + 4.4;
}

float m(float a, float b) {
	return (a + b) / 2;
}

void bissecao() {
	float a = 1.5, b = 7.0;
	for (unsigned int i = 0; i < 6; i++) {

		cout << fixed << setprecision(4) << "a = " << a << "\tf(a) = " << fun1(a) << "\tb = " << b << "\tf(b) = " << fun1(b) << "\tm(a,b) = " << m(a, b) << "\tf(m(a,b)) = " << fun1(m(a, b)) << endl;

		if (fun1(a)*fun1(m(a, b)) < 0)
			b = m(a, b);
		else
			a = m(a, b);
	}
}

//-----------------NEWTON

float fun2(float x) {
	return (x - 2.6) + pow((cos(x + 1.1)), 3);
}

float fun2d(float x) {
	return 1 - 3*pow(cos(x + 1.1), 3 - 1)*sin(x + 1.1);
}

void newton1() {
	
	float x = 1.8;
	for (unsigned int i = 0; i < 2; i++) {
		cout << "x = " << x << endl;
		x = x - fun2(x) / fun2d(x);
	}
}

float fun3(float x) {
	return -x + 40.0 * cos(sqrt(x)) + 3.0;
}

float fun3d(float x) {
	return -(20 * sin(sqrt(x)) / sqrt(x)) - 1;
}

void newton2() {
	float x = 1.7000;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(4) << "x = " << x << "\tg(x) = " << fun3(x) << endl;
		x = x - fun3(x) / fun3d(x);
	}
}

//-----------------METODO ITERAÇÕES SISTEMAS

float fun4(float x, float y) {
	return pow(x, 2.0) - y - 2.0;
}

float fun4dx(float x, float y) {
	return 2 * x;
}

float fun4dy(float x, float y) {
	return -1;
}

float fun5(float x, float y) {
	return -x + pow(y, 2.0) - 2.0;
}

float fun5dx(float x, float y) {
	return -1;
}

float fun5dy(float x, float y) {
	return 2 * y;
}

void newtonIteracao() {
	float x = 1.5;
	float y = 0.8;
	float oldx;
	float oldy;

	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(4) << "x = " << x << "\ty = " << y << endl;
		oldx = x;
		
		x = x - (fun4(x, y) * fun5dy(x, y) - fun5(x, y) * fun4dy(x, y)) / (fun4dx(x, y) * fun5dy(x, y) - fun5dx(x, y) * fun4dy(x, y));
		y = y - (fun5(oldx,y) * fun4dx(oldx,y) - fun4(oldx,y) * fun5dx(oldx,y)) / (fun4dx(oldx, y) * fun5dy(oldx, y) - fun5dx(oldx, y) * fun4dy(oldx, y));
	}
}

//------------------METODO PICARD-PEANO, ver exercicios teóricos

float fun6(float x) {
	return 2 * log(2 * x);
}

void picardPeano1() {
	float x = 1.1;
	for (unsigned int i = 0; i < 2; i++) {
		cout << fixed << setprecision(5) << "x = " << x << endl;
		x = fun6(x);
	}
}

float fun7(float x) {
	return pow(4.0*pow(x, 3.0) - x + 3.0, 1.0 / 4.0);
}

void picardPeano2() {
	float x = 3.5;
	for (unsigned int i = 0; i < 3; i++) {
		cout << fixed << setprecision(5) << "x = " << x << endl;
		x = fun7(x);
	}
}

//-----------------METODO DA CORDA

float fun8(float x) {
	return pow(x, 4) + 2 * pow(x, 3) - x - 1;
}

float w(float a, float b) {
	return (a * fun8(b) - b*fun8(a)) / (fun8(b) - fun8(a));
}

void corda() {
	float x = 0.5;
	float a = 0.0, b = 1.0;

	for (unsigned int i = 0; i < 12; i++) {
		cout << fixed << setprecision(5) << "a = " << a << "\tf(a) = " << fun8(a) << "\tb = " << b << "\tf(b) = " << fun8(b) << "\tx = " << x << endl;

		if (fun8(a)*fun8(w(a, b)) < 0) {
			b = w(a,b);
		}
		else {
			a = w(a, b);
		}
	}
}

int main()
{
	//bissecao();
	//newton1();
	//newton2();
	//newtonIteracao();
	//picardPeano1();
	//picardPeano2();
	//corda();
    return 0;
}

