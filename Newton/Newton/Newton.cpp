// Newton.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define NUM_E 2.71828182845904523536

double funcao(double x) {
	return 4 * cos(x) - pow(NUM_E,x);
}

double derivada(double x) {
	return -4 * sin(x) - pow(NUM_E, x);
}

double calcularX(double Xa, double Fx, double DFx) {
	return Xa - (Fx / DFx);
}

bool parada(double E, double parar) {
	if (E == NULL) {
		return false;
	}
	return E < parar;
}

double calcularE(double X, double Xa) {
	if (Xa == NULL) {
		return 1;
	}
	return fabs((X - Xa) / X);
}

void exibirProgresso(int i, double X, double Fx,double DFx, double E) {
	if (i == 0) {
		cout << "i\t\t" 
			<< "X\t\t\t" 
			<< "Fx\t\t\t" 
			<< "DFx\t\t\t" 
			<< "E\n";
	}
	cout << setprecision(6)
		<< scientific
		<< i << "\t\t" 
		<< X << "\t\t" 
		<< Fx << "\t\t" 
		<< DFx << "\t\t" 
		<< E << "\n";
}

int main()
{
	double
		X, Xa,
		Fx, DFx,
		E, parar;

	X = 0.5;
	parar = pow(10, -5);
	E = NULL;
	Xa = NULL;

	int i = 0;
	while (!parada(E, parar)) {
		Fx = funcao(X);
		DFx = derivada(X);

		E = calcularE(X, Xa);
		exibirProgresso(i, X, Fx, DFx, E);

		Xa = X;
		X = calcularX(Xa, Fx, DFx);

		i++;
	}
}

