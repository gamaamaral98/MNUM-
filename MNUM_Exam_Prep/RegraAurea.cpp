// RegraAurea.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
	return 5 * cos(x) - sin(x);
}

void aurea() {
	double x1 = 2.0, x2 = 4.0;
	double x3, x4;

	double B = (sqrt(5) - 1) / 2, A = pow(B, 2);

	for (unsigned int i = 0; i < 3; i++) {

		x3 = x1 + A*(x2 - x1);
		x4 = x1 + B*(x2 - x1);

		cout << "x1 = " << x1 << "\tx2 = " << x2 << "\tx3 = " << x3 << "\tx4 = " << x4 << "\tf(x1) = " << f(x1) << "\tf(x2) = " << f(x2) << "\tf(x3) = " << f(x3) << "\tf(x4) = " << f(x4) << endl;
		if (f(x3) < f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
	}
}

int main()
{
	cout << fixed;
	cout << setprecision(5);
	aurea();
    return 0;
}
