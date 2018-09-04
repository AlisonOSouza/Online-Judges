/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 4
PROBLEMA:	#1 MARAT09 - Maratona

SOLUÇÃO PROPOSTA:
Para resolver este problema, basta verificar se a distância entre cada
posto de água, e a distância entre o último posto de água e o ponto final
da corrida é menor ou igual a distância intermediária máxima que um atleta
pode atingir. Para isso, leio os valores de cada posto de água e armazeno
em um vetor. Depois, calculo a distância entre os postos de água vizinhos.
Caso todas as distâncias sejam menores que a DIM, imprimo S, caso 
contrário, imprimo N.
\*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, i;
	std::vector<int> p;
	
	std::cin >> n >> m;

	p.resize(n);

	for(i = 0; i < n; i++)
	{
		std::cin >> p[i];
	}

	for(i = 0; i < n-1; i++)
	{
		if((p[i+1] - p[i]) > m)
		{
			std::cout << "N";
			return 0;
		}
	}

	if((42195 - p[n-1]) > m)
	{
		std::cout << "N";
		return 0;
	}

	std::cout << "S";
	return 0;
}