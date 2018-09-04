/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 10
PROBLEMA:	#12 URI1028 - Figurinhas

SOLUÇÃO PROPOSTA:
Neste problema, para encontrar o maior tamanho da pilha de figurinhas
para ambos os amigos, basta calcular o MDC entre a quantidade total de
figurinhas dos dois amigos.
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
	int n, f1, f2;

	std::cin >> n;
	while(n--)
	{
		std::cin >> f1 >> f2;
		std::cout << euclideanMDC(f1, f2) << endl;
	}

	return 0;
}