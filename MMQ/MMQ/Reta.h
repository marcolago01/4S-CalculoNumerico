#pragma once

#include <array>
#include <math.h>
using namespace std;

const int LINHA_MATRIZ_RETA = 2;
const int COLUNA_MATRIZ_RETA = LINHA_MATRIZ_RETA + 1;

struct Reta
{	
	double **vetores;
	Reta(int elementos, int pontos) {
		*vetores = new double[elementos];
		for (int i = 0; i < elementos; i++)
		{
			vetores[i] = new double[pontos];
		}
	}
};

/*Calcular os valores de cada posição da matriz*/
double RETA_calcularValorMatriz(double a1[], double a2[], int tamanho) {
	double somador = 0;
	for (int i = 0; i < tamanho; i++)
	{
		somador += a1[i] * a2[i];
	}
	return somador;
}

void RETA_gerarMatriz(double matriz[LINHA_MATRIZ_RETA][COLUNA_MATRIZ_RETA]) {
	for (int linha = 0; linha < LINHA_MATRIZ_RETA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA_MATRIZ_RETA; coluna++)
		{

		}
	}
}

