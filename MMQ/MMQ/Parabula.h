#pragma once

#include "Eliminacao_Gauss_PivotParcial.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const int LINHA_MATRIZ_PARABOLA = 3;
const int COLUNA_MATRIZ_PARABOLA = LINHA_MATRIZ_PARABOLA + 1;


struct Parabola
{
	vector<vector<double>> ux;
	vector<vector<double>> matriz;
	const int QTD_LINHAS_VETORES_PARABOLA = 4;
	int tamanho;

	Parabola(double x[], double y[], int tamanho) {
		this->tamanho = tamanho;

		inicializarUX();
		inicializarMatriz();

		ux[0].assign(tamanho, 1);
		for (int i = 0; i < tamanho; i++)
		{
			ux[1][i] = x[i];
			ux[2][i] = pow(x[i], 2);
			ux[3][i] = y[i];
		}
	}
	void inicializarUX() {
		ux.resize(QTD_LINHAS_VETORES_PARABOLA);
		for (int i = 0; i < QTD_LINHAS_VETORES_PARABOLA; i++)
		{
			ux[i].resize(tamanho);
		}
	}
	void inicializarMatriz() {
		matriz.resize(LINHA_MATRIZ_PARABOLA);
		for (int i = 0; i < LINHA_MATRIZ_PARABOLA; i++)
		{
			matriz[i].resize(COLUNA_MATRIZ_PARABOLA);
		}
	}
};

/*Calcular os valores de cada posição da matriz*/
double PARABOLA_calcularValorMatriz(vector<double> a1, vector<double> a2, int tamanho) {
	double somador = 0;
	for (int i = 0; i < tamanho; i++)
	{
		somador += a1[i] * a2[i];
	}
	return somador;
}

void PARABOLA_gerarMatriz(Parabola &reta) {
	for (int linha = 0; linha < LINHA_MATRIZ_PARABOLA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA_MATRIZ_PARABOLA; coluna++)
		{
			reta.matriz[linha][coluna] = PARABOLA_calcularValorMatriz(reta.ux[linha], reta.ux[coluna], reta.tamanho);
		}
	}
}

void PARABOLA_calcularMMQ(double x[], double y[], int tamanho) {
	Parabola parabola(x, y, tamanho);
	PARABOLA_gerarMatriz(parabola);
	eliminacaoGaussPivotParcial(parabola.matriz, LINHA_MATRIZ_PARABOLA, COLUNA_MATRIZ_PARABOLA);
}