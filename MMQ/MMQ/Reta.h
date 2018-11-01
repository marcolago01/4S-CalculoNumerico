#pragma once

#include "Eliminacao_Gauss_PivotParcial.h"

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

const int LINHA_MATRIZ_RETA = 2;
const int COLUNA_MATRIZ_RETA = LINHA_MATRIZ_RETA + 1;


struct Reta
{	
	vector<vector<double>> ux;
	vector<vector<double>> matriz;
	const int QTD_LINHAS_VETORES_RETA = 3;
	int tamanho;

	Reta(double x[], double y[], int tamanho) {
		this->tamanho = tamanho;

		inicializarUX();
		inicializarMatriz();

		ux[0].assign(tamanho, 1);
		for (int i = 0; i < tamanho; i++)
		{
			ux[1][i] = x[i];
			ux[2][i] = y[i];
		}
	}
	void inicializarUX() {
		ux.resize(QTD_LINHAS_VETORES_RETA);
		for (int i = 0; i < QTD_LINHAS_VETORES_RETA; i++)
		{
			ux[i].resize(tamanho);
		}
	}
	void inicializarMatriz() {
		matriz.resize(LINHA_MATRIZ_RETA);
		for (int i = 0; i < LINHA_MATRIZ_RETA; i++)
		{
			matriz[i].resize(COLUNA_MATRIZ_RETA);
		}
	}
};

/*Calcular os valores de cada posição da matriz*/
double RETA_calcularValorMatriz(vector<double> a1, vector<double> a2, int tamanho) {
	double somador = 0;
	for (int i = 0; i < tamanho; i++)
	{
		somador += a1[i] * a2[i];
	}
	return somador;
}

void RETA_gerarMatriz(Reta &reta) {
	for (int linha = 0; linha < LINHA_MATRIZ_RETA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA_MATRIZ_RETA; coluna++)
		{
			reta.matriz[linha][coluna] = RETA_calcularValorMatriz(reta.ux[linha], reta.ux[coluna], reta.tamanho);
		}
	}
}

void RETA_calcularMMQ(double x[], double y[], int tamanho) {
	Reta reta(x, y, tamanho);
	RETA_gerarMatriz(reta);
	eliminacaoGaussPivotParcial(reta.matriz, LINHA_MATRIZ_RETA, COLUNA_MATRIZ_RETA);
}

