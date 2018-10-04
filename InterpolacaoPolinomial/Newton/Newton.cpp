// Newton.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


const int PONTOS = 4;
const int LINHA = PONTOS*2;
const int COLUNA = PONTOS;

void gerarMatriz(array<double, PONTOS> X, array<double, PONTOS> Fx, double matriz[LINHA][COLUNA]) {
	for (int coluna = 0; coluna < COLUNA; coluna++)
	{
		int aux = 0;

		for (int linha = 0; linha < LINHA; linha++)
		{
			if (coluna == 0) {
				if (linha % 2 == 0) {
					int i = linha/2;
					matriz[linha][coluna] = Fx[i];
					i++;
				}
			}
			else {
				if (matriz[linha - 1][coluna - 1] != 0 || matriz[linha - 1][coluna - 1] != NULL) {
					double anterior, proximo, xInicial, xFinal;
					anterior = matriz[linha - 1][coluna - 1];
					proximo = matriz[linha + 1][coluna - 1];
					xInicial = X[aux];
					xFinal = X[coluna + aux];

					matriz[linha][coluna] = 
						(anterior - proximo) / 
						(xFinal - xInicial);
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
			matriz[linha][coluna] = -99999;
		}
	}
}

void exibirMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int k = 0; k < COLUNA; k++)
		{
			if (matriz[i][k] == -99999) {
				cout << "\t\t";
			}
			else {
				cout << matriz[i][k] << "\t\t";
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

int main()
{
	array<double, PONTOS> X = { -2,-1,1,2 };
	array<double, PONTOS> Fx = { 0,1,-1,0 };
	double matriz[LINHA][COLUNA];
	double x = 2;

	zerarMatriz(matriz);
	gerarMatriz(X, Fx, matriz);
	exibirMatriz(matriz);
}

