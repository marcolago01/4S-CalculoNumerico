// MMQ.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Reta.h"
#include "Parabula.h"
using namespace std;

const int PONTOS = 4;


int main()
{
	double X[PONTOS] = { -1,0,1,2 };
	double Y[PONTOS] = { 0,-1,0,7 };

	RETA_calcularMMQ(X, Y, PONTOS);
	PARABOLA_calcularMMQ(X, Y, PONTOS);

}

