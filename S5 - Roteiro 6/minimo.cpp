/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 6
PROBLEMA:	#7 MINIMO - Final Mundial de 2008

SOLUÇÃO PROPOSTA:
Modelamos este problema como um grafo direcionado e ponderado, implementado
como uma matriz de adjacência (com três dimensões). Como o problema trata
de encontrar o caminho mais curto, pensei inicialmente em implementar o
algoritmo de Dijkstra, porém, tive dificuldades em implementar Dijkstra
para esse caso, e olhando as dicas do problema vi que Floyd-Warshall é
mais apropriado, portanto escolhi Floyd-Warshall.
Após ler as arestas do grafo, chamo a função Floyd-Warshall que itera em
todos os vértices 'i', verificando se o menor caminho entre dois vértices
passa pelo vértice 'i' ou não. Salvamos os valores dos menores caminhos
entre os vértices novamente no grafo, para realizar as buscas mais tarde.
Após calcular os custos com Floyd-Warshall, leio cada consulta e se houver
um caminho para essa consulta imprimo o custo desse caminho. Caso não
exista, imprimo -1.
\*******************************************************************/


#include <iostream>
#include <vector>

using namespace std;

#define max 99999

typedef vector< vector< vector<int> > > grafo_t;

void floyd_warshall(grafo_t &grafo, int n)
{
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				grafo[i][j][k] = min(grafo[i-1][j][k], grafo[i-1][j][i-1] + grafo[i-1][i-1][k]);
			}
		}
	}
}

int main()
{
	int n, m, u, v, w, c, o, d, t, i, j, k, teste;
	grafo_t grafo;

	teste = 1;
	while(std::cin >> n >> m)
	{
		grafo.resize(n+1);

		for(i = 0; i <= n; i++)
		{
			grafo[i].resize(n+1);
			for(j = 0; j <= n; j++)
			{
				grafo[i][j].resize(n+1);
				for(k = 0; k <= n; k++)
				{
					if(j == k)
						grafo[i][j][k] = 0;
					else
						grafo[i][j][k] = max;
				}
			}
		}

		while(m > 0)
		{
			std::cin >> u >> v >> w;
			grafo[0][u-1][v-1] = min(grafo[0][u-1][v-1], w);
			m--;
		}

		floyd_warshall(grafo, n);

		std::cin >> c;

		std::cout << "Instancia " << teste << endl;
		for(i = 0; i < c; i++)
		{
			std::cin >> o >> d >> t;

			if(grafo[t][o-1][d-1] == max)
				std::cout << -1 << endl;
			else
				std::cout << grafo[t][o-1][d-1] << endl;
		}
		teste++;
		std::cout << endl;
	}
	return 0;
}