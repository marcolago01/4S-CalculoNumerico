#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <vector>
using namespace std;

const int TAMANHO = 10000000;

void informarTempo(double inicio, double fim, int opcao) {
	double tempo = fim - inicio;

	switch (opcao)
	{
	case 1:
		printf("Tempo para inicializar foi de %f segundos\n", tempo);
		break;
	case 2:
		printf("Tempo para fazer o somatorio foi de %f segundos\n", tempo);
		break;
	default:
		break;
	}
}

void serial(vector<int> vetor) {
	printf("\n*******SEQUENCIAL**********\n");

	double tempoInicial, tempoFinal;

	//inicializar vetor
	tempoInicial = omp_get_wtime();

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = 1;
	}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, 1);

	//fim inicializar vetor

	//somatório vetor

	tempoInicial = omp_get_wtime();
	long int somatorio = 0;

	for (int i = 0; i < TAMANHO; i++)
	{
		somatorio += vetor[i];
	}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, 2);

	//fim somatorio vetor


}
void openmpVetor(vector<int> vetor) {
	printf("\n*******OMP**********\n");

	double tempoInicial, tempoFinal;
	
	//inicializar vetor

	tempoInicial = omp_get_wtime();

	#pragma omp parallel for
		for (int i = 0; i < TAMANHO; i++)
		{
			vetor[i] = 1;
		}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, 1);

	//fim inicializar vetor

	//somatório vetor
	tempoInicial = omp_get_wtime();
	long int somatorio = 0;

	#pragma omp parallel for reduction(+:somatorio)
		for (int i = 0; i < TAMANHO; i++)
		{
			somatorio += vetor[i];
		}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, 2);
	//fim somatorio vetor

	//multiplicacao vetor
	//fim multiplicacao vetor

	//copia vetor
	//fim copia vetor
}

void accVetor(int vetor[TAMANHO]) {

	
}

int main()
{
	vector<int> vetor;
	vetor.resize(TAMANHO);
	
	serial(vetor);
	openmpVetor(vetor);
}