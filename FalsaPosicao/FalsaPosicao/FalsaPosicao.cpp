// FalsaPosicao.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

double funcao(double x) {
	return (x*(log10(x)))-1;
}

double calcularX(double a, double b, double Fa, double Fb) {
	return ((a*Fb) - (b * Fa)) / (Fb - Fa);
}

bool valorNegativo(double Fa, double Fx) {
	return (Fa * Fx) < 0;
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

void exibirProgresso(int i, double a, double b, double X, double Fa, double Fb, double Fx, double E) {
	if (i == 0) {
		cout << "i\t\t" << "a\t\t" << "b\t\t" << "x\t\t" << "Fa\t\t" << "Fb\t\t"  << "Fx\t\t" << "E\n";
	}
	cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << X << "\t\t" << Fa << "\t\t" << Fb << "\t\t" << Fx << "\t\t" << E << "\n";
}

int main()
{
	double
		X, Xa,
		a, b,
		Fa, Fx, Fb,
		E, parar;

	a = 2;
	b = 3;
	parar = pow(10, -5);
	E = NULL;
	X = NULL;
	Xa = NULL;

	int i = 0;
	while (!parada(E, parar)) {
		Fa = funcao(a);
		Fb = funcao(b);
		X = calcularX(a, b, Fa, Fb);
		Fx = funcao(X);
		E = calcularE(X, Xa);
		exibirProgresso(i, a, b, X, Fa,Fb, Fx, E);
		if (valorNegativo(Fa, Fx)) {
			b = X;
		}
		else {
			a = X;
		}
		Xa = X;
		i++;
	}

}

