// Lagrange.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int PONTOS = 3;
const int LINHA = PONTOS;
const int COLUNA = PONTOS + 2;

void gerarMatriz(array<double, PONTOS> X, array<double, PONTOS> Fx, double matriz[LINHA][COLUNA], double x) {
	for (int linha = 0; linha < LINHA; linha++)
	{
		{
			for (int coluna = 0; coluna < COLUNA; coluna++)
			{
				//valores diagonal principal
				if (linha == coluna) {
					matriz[linha][coluna] = x - X[linha];
				}

				//valores coluna Dk
				else if (coluna == COLUNA - 2) {
					double somador = 1;
					for (int i = 0; i < COLUNA-2; i++)
					{
						somador = somador * matriz[linha][i];
					}
					matriz[linha][coluna] = somador;
				}
				//valores Fx/DK
				else if (coluna == COLUNA - 1) {
					matriz[linha][coluna] = Fx[linha] / matriz[linha][coluna - 1];
				}

				else {
					//restante da matriz
					matriz[linha][coluna] = X[linha] - X[coluna];
				}
			}
		}
	}
}

double polinomio(double matriz[LINHA][COLUNA]) {
	double produtorio = 1;
	double somador = 0;

	for (int i = 0; i < LINHA; i++)
	{
		produtorio = produtorio * matriz[i][i];
		somador += matriz[i][COLUNA - 1];
	}

	return produtorio * somador;
}

void exibirXFx(array<double, PONTOS> X, array<double, PONTOS> Fx) {
	cout << "Indice" << "\t" << "X" << "\t" << "Fx" << endl;
	for (int i = 0; i < PONTOS; i++)
	{
		cout << i << "\t" << setprecision(6) << X[i] << "\t" << Fx[i] << endl;
	}
}

void exibirMatriz(double matriz[LINHA][COLUNA]) {
	cout << endl;
	for (int i = 0; i < COLUNA-2; i++)
	{
		cout << "C" << i << "\t\t";
	}

	cout << "Dk" << "\t\t" << "Fx/Dk" << endl;
	for (int i = 0; i < LINHA; i++)
	{
		for (int k = 0; k < COLUNA; k++)
		{
			cout << setprecision(6) << matriz[i][k] << "\t\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	array<double, PONTOS> X = { -1,0,3 };
	array<double, PONTOS> Fx = { 15,8,-1 };
	double matriz[LINHA][COLUNA];
	double x = 2;

	gerarMatriz(X, Fx, matriz, x);
	exibirXFx(X, Fx);
	exibirMatriz(matriz);

	cout << endl
		<< "P" << PONTOS - 1 << "(" << x << ") = " << polinomio(matriz)<<endl;
}

