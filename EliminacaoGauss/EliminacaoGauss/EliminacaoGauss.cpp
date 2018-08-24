// EliminacaoGauss.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

double calcularMultiplicador(double pivo, double valorLinha){
	return valorLinha / pivo;
}

double calcularValor(double multiplicador, double valorBase, double valorLinhaPivo) {
	return valorBase - (multiplicador*(valorLinhaPivo));
}

void exibirMatriz(double matriz[3][4]) {
	cout << "######################################################\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout
				<< setprecision(6) << scientific << matriz[i][k] << "\t\t";
		}
		cout << "\n";
	}
	cout << "######################################################\n";
}

int main()
{
	double matriz[3][4] = { { 1,3,4,-5 },{3, 2, 1, 8},{2, 4, 3, 4} };

	double pivo, multiplicadores[2];
	int linha, coluna;

	linha = 0;
	coluna = 0;
	pivo = matriz[linha][coluna];

	multiplicadores[0] = calcularMultiplicador(pivo, matriz[linha + 1][coluna]);
	multiplicadores[1] = calcularMultiplicador(pivo, matriz[linha + 2][coluna]);

	for (int i = 1; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matriz[i][k] = calcularValor(multiplicadores[i-1], matriz[i][k], matriz[linha][k]);
		}
	}
	
	exibirMatriz(matriz);

	linha = 1;
	coluna = 1;
	pivo = matriz[linha][coluna];

	multiplicadores[0] = calcularMultiplicador(pivo, matriz[linha + 1][coluna]);

	for (int i = 2; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matriz[i][k] = calcularValor(multiplicadores[i - 2], matriz[i][k], matriz[linha][k]);
		}
	}

	exibirMatriz(matriz);


}

