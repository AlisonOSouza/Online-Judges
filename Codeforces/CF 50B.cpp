/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#0 CF50B - Choosing Symbol Pairs

SOLUÇÃO PROPOSTA:
Neste problema, crio um vetor de 256 posições e a cada ocorrência de uma
letra incremento a posição correspondente no vetor (correspondente a 
tabela ascii). Após isso, calculo a soma dos quadrados de cada posição
do vetor e imprimo na tela. 
\*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i;
	std::string s;
	std::vector<long long> counts(256,0);
	long long total = 0;

	std::cin >> s;
	for(i = 0; i < s.size(); i++)
	{
		counts[s[i]]++;
	}

	for(i = 0; i < 256; i++)
	{
		total += counts[i] * counts[i];
	}

	std::cout << total << endl;
	return 0;
}