// Gauss-Jacobi.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int LINHA = 3, COLUNA = 4;

void calcularX(array<double, LINHA> &XNovo, array<double, LINHA> &XAntigo, double matriz[LINHA][COLUNA]) {
	double b, diagonalPrincipal, somador;
	for (int x = 0; x < LINHA; x++)
	{
		diagonalPrincipal = matriz[x][x];
		b = matriz[x][COLUNA - 1];
		somador = b;
		for (int i = 0; i < COLUNA-1; i++)
		{
			if (x != i) {
				somador = somador - matriz[x][i]*XAntigo[i];
			}
			
		}
		XNovo[x] = somador / diagonalPrincipal;
	}
}

void calcularDistancia(array<double, LINHA> &distancia, array<double, LINHA> XNovo, array<double, LINHA> XAntigo) {
	for (int i = 0; i < LINHA; i++)
	{
		distancia[i] = XNovo[i] - XAntigo[i];
	}
}

double MaiorValorEmModulo(array<double, LINHA> array) {
	double maior = fabs(array[0]);
	for (int i = 1; i < LINHA; i++)
	{
		if (maior < fabs(array[i])) {
			maior = fabs(array[i]);
		}
	}
	return maior;
}

double calcularErro(array<double, LINHA> distancia, array<double, LINHA> XNovo) {
	double maiorDistancia = MaiorValorEmModulo(distancia);
	double maiorXNovo = MaiorValorEmModulo(XNovo);

	return maiorDistancia / maiorXNovo;
}

void exibir(array<double, LINHA> X, int interacao) {
	cout << endl;
	cout << "I"
		<< "\t X"
		<< "\t Valor"
		<< endl;

	for (int i = 0; i < LINHA; i++)
	{
		cout<< interacao
			<< "\t" << "X" << i+1
			<<setprecision(6)
			<< "\t" << X[i]
			<< endl;
	}
	cout << endl;
}

int main()
{
	array<double, LINHA> XNovo;
	array<double, LINHA> XAntigo;
	array<double, LINHA> distancia;

	double MATRIZ[LINHA][COLUNA] = { { 10, 2, 1, 7 },{ 1, 5, 1, -8},{2, 3, 10, 6} };

	double erro, parada;

	parada = pow(10, -2);

	//valores de X iniciais (X = 0);
	for (int i = 0; i < LINHA; i++)
	{
		double diagonalPrincipal = MATRIZ[i][i];
		double valorB = MATRIZ[i][COLUNA - 1];
		XAntigo[i] = valorB / diagonalPrincipal;
	}

	exibir(XAntigo, 0);

	calcularX(XNovo, XAntigo, MATRIZ);
	exibir(XNovo, 1);
	calcularDistancia(distancia, XNovo, XAntigo);
	erro = calcularErro(distancia, XNovo);
	exibir(distancia, 99);
	cout << endl << endl << "erro: " << erro<<endl;
}

