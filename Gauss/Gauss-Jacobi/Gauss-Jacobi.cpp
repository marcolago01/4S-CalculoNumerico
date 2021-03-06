// Gauss-Jacobi.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
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

void exibirCriterio(array<double, LINHA> vetor,string nome, string criterio, double maior) {
	cout << "---------------------------" << endl;
	cout << criterio << endl;
	cout << endl
		<< nome << "\tValor" << endl;
	for (int i = 0; i < LINHA; i++)
	{
		cout << i+1 << "\t" << setprecision(6) << vetor[i]<<endl;
	}
	cout << endl
		<< "Maior: " << maior << endl;

	if (maior < 1) {
		cout << "Passou no criterio!" << endl;
	}
	else {
		cout << "Nao passou no criterio!" << endl;
	}
	cout << "---------------------------" << endl;
}
bool criterioLinha(double matriz[LINHA][COLUNA]) {
	array<double, LINHA> alfas;
	alfas.fill(0);

	double somador, diagonalPrincipal,b,max;
	for (int linha = 0; linha < LINHA; linha++)
	{
		diagonalPrincipal = fabs(matriz[linha][linha]);
		b = matriz[linha][COLUNA - 1];
		somador = 0;
		for (int coluna = 0; coluna < COLUNA - 1; coluna++)
		{
			if (linha != coluna) {
				somador += fabs(matriz[linha][coluna]);
			}
		}
		alfas[linha] = somador / diagonalPrincipal;
		if (alfas[linha] >= 1) {
			max = MaiorValorEmModulo(alfas);
			exibirCriterio(alfas, "Alfa", "CRITERIO DAS LINHAS", max);
			return false;
		}
	}
	max = MaiorValorEmModulo(alfas);
	exibirCriterio(alfas,"Alfa", "CRITERIO DAS LINHAS",max);
	return max < 1;
	
}

void exibir(array<double, LINHA> X, int interacao, double erro,array<double,LINHA> distancia) {
	cout << "Interacao: " << interacao << endl << endl;
	cout << "X"
		<< "\t Valor"
		<< endl;

	for (int i = 0; i < LINHA; i++)
	{
		cout<< "X" << i+1
			<<setprecision(6)
			<< "\t" << X[i]
			<< endl;
	}

	cout << endl
		<<"  Vetor Distancia" 
		<< endl;

	for (int i = 0; i < LINHA; i++)
	{
		cout <<setprecision(6)<< distancia[i] << endl;
	}
	cout << "Erro: " << setprecision(6) << erro;
	cout << endl<<"________________________"<<endl;
}

int main()
{
	array<double, LINHA> XNovo;
	array<double, LINHA> XAntigo;
	array<double, LINHA> distancia;

	//double MATRIZ[LINHA][COLUNA] = { { 10, 2, 1, 7 },{ 1, 5, 1, -8},{ 2, 3, 10, 6} };
	double MATRIZ[LINHA][COLUNA] = { { 5, 1, 1, 5 },{ 3, 4, 1, 6 },{ 3, 3, 6, 0 } };

	double erro, parada;
	int interacao = 1;

	parada = pow(10, -2);
	erro = 1;
	distancia.fill(0);

	if (criterioLinha(MATRIZ)) {
		//valores de X iniciais (X = 0);
		for (int i = 0; i < LINHA; i++)
		{
			double diagonalPrincipal = MATRIZ[i][i];
			double valorB = MATRIZ[i][COLUNA - 1];
			XAntigo[i] = valorB / diagonalPrincipal;
		}

		exibir(XAntigo, 0, erro, distancia);

		while (parada < erro) {
			calcularX(XNovo, XAntigo, MATRIZ);
			calcularDistancia(distancia, XNovo, XAntigo);
			erro = calcularErro(distancia, XNovo);
			exibir(XNovo, interacao, erro, distancia);
			XAntigo.swap(XNovo);
			interacao++;
		}
	}
	
}

