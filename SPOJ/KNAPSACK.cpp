/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 4
PROBLEMA:	#15 KNAPSACK - The Knapsack Problem

SOLUÇÃO PROPOSTA:
Como este é exatamente o problema da Mochila, simplesmente apliquei o
algoritmo de programação dinâmica para este problema que se encontra na
Wikipedia. Neste algoritmo, leio os tamanhos e valores de cada item e
salvo em um vetor de pares. Em seguida, calculo a matriz de valores
máximos que podem ser alcançados com peso menor ou igual que o limite 'w'
usando 'i' itens (onde 'w' é a coluna da matriz e 'i' é a linha). Depois
de calcular toda a matriz, imprimo o valor da matriz correspondente a 'n'
ítens e tamanho 's'.
\*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int s, n, i, j;
	int valor, tamanho;
	std::vector< pair<int, int> > itens;
	int m[2005][2005];

	std::cin >> s >> n;

	itens.resize(n+1);

	for(i = 1; i <= n; i++)
	{
		std::cin >> tamanho >> valor;
		itens[i].first = tamanho;
		itens[i].second = valor;
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= s; j++)
		{
			if(itens[i].first > j)
				m[i][j] = m[i-1][j];
			else
				m[i][j] = max(m[i-1][j], m[i-1][j-itens[i].first] + itens[i].second);
		}
	}

	std::cout << m[n][s] << endl;

	return 0;
}