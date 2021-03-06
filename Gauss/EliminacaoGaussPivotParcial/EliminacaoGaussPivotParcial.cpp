// EliminacaoGaussPivotParcial.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

const int LINHA = 3, COLUNA = 4;

double calcularMultiplicador(double pivo, double valorLinha) {
	return valorLinha / pivo;
}

double calcularValor(double multiplicador, double valorBase, double valorLinhaPivo) {
	return valorBase - (multiplicador*(valorLinhaPivo));
}

double calcularX(double valorDiagonalPrincipal, double valorResposta) {
	return valorResposta / valorDiagonalPrincipal;
}

void exibirMatriz(double matriz[LINHA][COLUNA]) {
	cout << "######################################################\n";
	for (int i = 0; i < LINHA; i++)
	{
		for (int k = 0; k < COLUNA; k++)
		{
			cout
				<< setprecision(6) << scientific << matriz[i][k] << "\t\t";
		}
		cout << "\n";
	}
	cout << "######################################################\n";
}

void trocarLinha(double matriz[LINHA][COLUNA], int linhaTroca1, int linhaTroca2) {
	double aux;

	for (int coluna = 0; coluna < COLUNA; coluna++)
	{
		aux = matriz[linhaTroca1][coluna];
		matriz[linhaTroca1][coluna] = matriz[linhaTroca2][coluna];
		matriz[linhaTroca2][coluna] = aux;
	}
}

int main()
{

	double matriz[LINHA][COLUNA] = { { 3, 3, 1, 7 },{ 2, 2, -1, 3 },{ 1, -1, 5, 5 } };

	int linhaColunaPivo = 0;
	double pivo = matriz[linhaColunaPivo][linhaColunaPivo];
	bool voltar = false;

	exibirMatriz(matriz);

	//Quantidade de vezes que ele vai realizar a ordenação da matriz
	for (int i = 0; i < (LINHA + LINHA) - 2; i++)
	{

		if (linhaColunaPivo + 1 == LINHA) {
			voltar = true;
		}
		
		//TrocarLinhaCasoEncontreMaior
		if (!voltar) {
			double maior = fabs(matriz[linhaColunaPivo][linhaColunaPivo]);
			int linhaParaTroca = linhaColunaPivo;
			for (int linha = linhaColunaPivo; linha < LINHA; linha++)
			{
				double valorAtual = fabs(matriz[linha][linhaColunaPivo]);
				if (maior < valorAtual) {
					linhaParaTroca = linha;
					maior = valorAtual;
				}
			}
			if (maior != fabs(matriz[linhaColunaPivo][linhaColunaPivo])) {
				trocarLinha(matriz, linhaColunaPivo, linhaParaTroca);
				pivo = matriz[linhaColunaPivo][linhaColunaPivo];
			}
		}
		

		if (voltar) {
			//Quantidade de linhas após a linha do pivo
			for (int linha = linhaColunaPivo - 1; linha >= 0; linha--)
			{
				double multiplicador = calcularMultiplicador(pivo, matriz[linha][linhaColunaPivo]);

				for (int coluna = 0; coluna < COLUNA; coluna++)
				{
					double valorPosicao = matriz[linha][coluna];
					double valorLinhaPivo = matriz[linhaColunaPivo][coluna];
					matriz[linha][coluna] = calcularValor(multiplicador, valorPosicao, valorLinhaPivo);
				}
			}

			exibirMatriz(matriz);
			linhaColunaPivo--;
		}
		else {
			//Quantidade de linhas após a linha do pivo
			for (int linha = linhaColunaPivo + 1; linha < LINHA; linha++)
			{
				double multiplicador = calcularMultiplicador(pivo, matriz[linha][linhaColunaPivo]);

				for (int coluna = 0; coluna < COLUNA; coluna++)
				{
					double valorPosicao = matriz[linha][coluna];
					double valorLinhaPivo = matriz[linhaColunaPivo][coluna];
					matriz[linha][coluna] = calcularValor(multiplicador, valorPosicao, valorLinhaPivo);
				}
			}

			linhaColunaPivo++;
			exibirMatriz(matriz);
		}

		pivo = matriz[linhaColunaPivo][linhaColunaPivo];
	}

	for (int linha = 0; linha < LINHA; linha++)
	{
		double valorDiagonalPrincipal = matriz[linha][linha];
		double valorResposta = matriz[linha][COLUNA - 1];
		double X = calcularX(valorDiagonalPrincipal, valorResposta);

		cout << "\nX" << linha + 1 << ": " << setprecision(6) << scientific << X;
	}

}

