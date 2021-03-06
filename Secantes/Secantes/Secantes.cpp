// Secantes.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUM_E 2.71828182845904523536

double funcao(double x) {
	return sqrt(x) - (5 * pow(NUM_E, -x));
}

double calcularX(double X[2],double FX[2]) {
	return ((X[1] * FX[0]) - (X[0] * FX[1])) / (FX[0] - FX[1]);
}

double calcularE(double X[2]) {
	return fabs((X[0] - X[1]) / X[0]);
}

bool parada(double E, double parar) {
	if (E == NULL) {
		return false;
	}
	return E < parar;
}

void exibirProgresso(int i, double X[2], double Fx[2], double E) {
	if (i == 0) {
		cout << "i\t\t"
			<< "X\t\t\t"
			<< "Fx\t\t\t"
			<< "E\n";
		cout << setprecision(6)
			<< scientific
			<< 0 << "\t\t"
			<< X[1] << "\t\t"
			<< Fx[1] << "\t\t"
			<< 1 << "\n";
		cout << setprecision(6)
			<< scientific
			<< 1 << "\t\t"
			<< X[0] << "\t\t"
			<< Fx[0] << "\t\t"
			<< 1 << "\n";
		return;
	}
	cout << setprecision(6)
		<< scientific
		<< i << "\t\t"
		<< X[0] << "\t\t"
		<< Fx[0] << "\t\t"
		<< E << "\n";
}

int main()
{
	double E, parar;
	double X[2] = { 2,1 };
	double FX[2];

	FX[1] = funcao(X[1]);
	FX[0] = funcao(X[0]);

	parar = pow(10, -5);
	int i = 0;

	E = NULL;
	exibirProgresso(i, X, FX, E);

	i = 2;

	while (!parada(E, parar)) {
		double Xnovo = calcularX(X, FX);
		double FXnovo = funcao(Xnovo);

		FX[1] = FX[0];
		FX[0] = FXnovo;

		X[1] = X[0];
		X[0] = Xnovo;

		E = calcularE(X);

		exibirProgresso(i, X, FX, E);

		i++;
	}

	
}

