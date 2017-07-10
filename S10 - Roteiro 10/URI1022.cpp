/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 10
PROBLEMA:	#11 URI1022 - TDA Racional

SOLUÇÃO PROPOSTA:
Neste problema, leio as operações de entrada e utilizo um switch para
alterar o fluxo de execução de acordo com a operação desejada. Após isso,
realizo as operações conforme orientado no problema, calculo o MDC
(utilizando a função euclideanMDC()) entre numerador e denominador e
imprimo a saída normal e simplificada.
Para o cálculo do MDC, foi utilizado o Algoritmo de Euclides, visto aqui:
https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides
\*******************************************************************/

#include <iostream>

using namespace std;

int euclideanMDC(int a, int b)
{
	if(b == 0)
		return a;
	else
		return euclideanMDC(b, a % b);
}

int main()
{
	int n, n1, d1, n2, d2, numerador, denominador, mdc;
	char op, c;

	std::cin >> n;
	while(n--)
	{
		std::cin >> n1 >> c >> d1 >> op >> n2 >> c >> d2;

		switch(op)
		{
			case '+':
				numerador = (n1 * d2 + n2 * d1);
				denominador = d1 * d2;
				std::cout << numerador << "/" << denominador << " = ";
				mdc = euclideanMDC(numerador, denominador);
				if(mdc < 0) mdc = -mdc;
				std::cout << numerador/mdc << "/" << denominador/mdc << endl;
				break;
			case '-':
				numerador = (n1 * d2 - n2 * d1);
				denominador = d1 * d2;
				std::cout << numerador << "/" << denominador << " = ";
				mdc = euclideanMDC(numerador, denominador);
				if(mdc < 0) mdc = -mdc;
				std::cout << numerador/mdc << "/" << denominador/mdc << endl;
				break;
			case '*':
				numerador = n1 * n2;
				denominador = d1 * d2;
				std::cout << numerador << "/" << denominador << " = ";
				mdc = euclideanMDC(numerador, denominador);
				if(mdc < 0) mdc = -mdc;
				std::cout << numerador/mdc << "/" << denominador/mdc << endl;
				break;
			case '/':
				numerador = n1 * d2;
				denominador = n2 * d1;
				std::cout << numerador << "/" << denominador << " = ";
				mdc = euclideanMDC(numerador, denominador);
				if(mdc < 0) mdc = -mdc;
				std::cout << numerador/mdc << "/" << denominador/mdc << endl;
				break;
		}
	}

	return 0;
}