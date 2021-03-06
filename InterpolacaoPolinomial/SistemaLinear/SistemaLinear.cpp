// SistemaLinear.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include "GaussPivotParcial.h"
using namespace std;

double calcularPolinomio(array<double, PONTOS> X,double x) {
	double somador=0;
	for (int i = 0; i < PONTOS; i++)
	{
		somador += X[i]*pow(x, i);
	}
	return somador;
}

void calcularMatriz(array<double,PONTOS> X, array<double, PONTOS> Fx, double matriz[LINHA][COLUNA]){
	int indice = 0;

	for (int linha = 0; linha < LINHA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA; coluna++)
		{
			if (coluna == COLUNA-1) {
				matriz[linha][coluna] = Fx[indice];
			}
			else {
				matriz[linha][coluna] = pow(X[indice], coluna);
			}
		}
		indice++;
	}
}

int main()
{
	array<double, PONTOS> X = { -1,0,3 };
	array<double, PONTOS> Fx = { 15,8,-1 };
	array<double, PONTOS> XObtidoMatriz;
	double matriz[LINHA][COLUNA];
	double x = -0.5;
	double polinomio;

	calcularMatriz(X, Fx, matriz);

	XObtidoMatriz.fill(0);
	executarGauss(matriz, XObtidoMatriz);

	polinomio = calcularPolinomio(XObtidoMatriz,x);

	cout << fixed << polinomio;
}

