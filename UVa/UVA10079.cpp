/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 10
PROBLEMA:	#5 UVa 10079 - Pizza Cutting

SOLUÇÃO PROPOSTA:
Neste problema, percebe-se necessário o uso de uma fórmula matemática, já
que os valores de entrada podem ser muito grandes para se tentar resolver
por força bruta. Assim, verificamos que a fórmula matemática que
corresponde a esse problema é ((n² + n)/2) + 1. Portanto, leio os valores
de entrada e aplico a fórmula explicitada anteriormente.
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	long long n;

	std::cin >> n;
	while(n >= 0)
	{
		std::cout << (((n * n) + n) / 2) + 1 << endl;
		std::cin >> n;
	}
	return 0;
}