// Newton.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


const int PONTOS = 4;
const int LINHA = (PONTOS * 2)-1;
const int COLUNA = PONTOS;

void gerarMatriz(array<double, PONTOS> X, array<double, PONTOS> Fx, double matriz[LINHA][COLUNA]) {
	for (int coluna = 0; coluna < COLUNA; coluna++)
	{
		int aux = 0;

		for (int linha = 0; linha < LINHA; linha++)
		{
			if (coluna == 0) {
				if (linha % 2 == 0) {
					int i = linha / 2;
					matriz[linha][coluna] = Fx[i];
					i++;
				}
			}
			else {
				if (linha-(aux*2) == coluna && aux+coluna < PONTOS) {
					double anterior, proximo, xInicial, xFinal;
					anterior = matriz[linha - 1][coluna - 1];
					proximo = matriz[linha + 1][coluna - 1];
					xInicial = X[aux];
					xFinal = X[coluna + aux];

					matriz[linha][coluna] =
						(proximo - anterior) /
						(xFinal - xInicial);
					aux++;
				}
			}
		}
	}
}

void zerarMatriz(double matriz[LINHA][COLUNA]) {
	for (int linha = 0; linha < LINHA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA; coluna++)
		{
			matriz[linha][coluna] = 69696924;
		}
	}
}

void exibirMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int k = 0; k < COLUNA; k++)
		{
			if (matriz[i][k] == 69696924) {
				cout << "\t";
			}
			else {
				cout << matriz[i][k] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void exibirXFx(array<double, PONTOS> X, array<double, PONTOS> Fx) {
	cout << "Indice" << "\t" << "X" << "\t" << "Fx" << endl;
	for (int i = 0; i < PONTOS; i++)
	{
		cout << i << "\t" << setprecision(6) << X[i] << "\t" << Fx[i] << endl;
	}
}

double polinomio(array<double, PONTOS> X, double matriz[LINHA][COLUNA], double x) {
	double valor = matriz[COLUNA-1][COLUNA-1];
	for (int i = COLUNA-2; i >= 0; i--)
	{
		valor = (valor * (x - X[i])) + matriz[i][i];
	}
	return valor;
}

int main()
{
	array<double, PONTOS> X = { -2,-1,1,2 };
	array<double, PONTOS> Fx = { 0,1,-1,0 };
	double matriz[LINHA][COLUNA];
	double x = 0.5;
	

	zerarMatriz(matriz);
	gerarMatriz(X, Fx, matriz);
	exibirMatriz(matriz);

	double resultado = polinomio(X, matriz, x);
	cout << endl<<"P"<<PONTOS-1<<" ("<<x<<"): " << resultado<<endl;
}

