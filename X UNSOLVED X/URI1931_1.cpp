/*
	@problem:	Mania de Par (Even Obsession) - 1931
	@site:		URI Online Judge
	@author:	Alison Souza


	TÁ DANDO WRONG ANSWER 100%
*/

#include <iostream>
#include <vector>
#include <cstdio>

#define INFINITO 1000000

using namespace std;

int main(int argc, char* argv[])
{
	//ios_base::sync_with_stdio(false);

	int c, v, c1, c2, g, i, j, k;

	// Lê o número de cidades e de estradas.
	//std::cin >> c >> v;
	scanf("%d %d", &c, &v);

	// Gera a matriz do grafo.
	std::vector< vector<int> > grafo(c, vector<int>(c));
	// Gera a matriz do grafo auxiliar.
	std::vector< vector<int> > grafo_aux(c, vector<int>(c));

	while(v--)
	{
		// Lê a origem e destino da estrada, além do valor do pedágio.
		//std::cin >> c1 >> c2 >> g;
		scanf("%d %d %d", &c1, &c2, &g);
		c1--; c2--;
		// Preenche o grafo.
		grafo[c1][c2] = g;
		grafo[c2][c1] = g;
	}

	// Dado o grafo original, irei gerar um grafo auxiliar que terá arestas
	// entre 'i' e 'k' se, e somente se, houver um vértice 'j' tal que
	// existe aresta de 'i' para 'j' e existe aresta de 'j' para 'k'.
	for(i = 0; i < c; i++)
	{
		for(j = 0; j < c; j++)
		{
			for(k = i; k < c; k++) // Acho que deve ser 0 aqui...
			{
				if(grafo[i][j] > 0 && grafo[j][k] > 0 && i != k)
				{
					if(grafo_aux[i][k] == 0 || grafo_aux[i][k] >  grafo[i][j] + grafo[j][k])
					{
						grafo_aux[i][k] = grafo[i][j] + grafo[j][k];
						grafo_aux[k][i] = grafo[i][j] + grafo[j][k];
					}
				}
			}
		}
	}
	
	// Agora irei usar Dijkstra para procurar o menor caminho no grafo
	// auxiliar. Dessa forma, todos os caminhos encontrados usarão um 
	// número par de estradas (e pedágios).
	
	/***************** DIJKSTRA ALGORITHM *****************/
	int dist[c];				// Distância de cada vertice.
	int prev[c];				// Vértice anterior (pai).
	// Seta valores padrões de distância e vértice pai.
	for(i = 0; i < c; i++)
	{
		dist[i] = INFINITO;
		prev[i] = -1;
	}

	// Distância da origem = 0;
	dist[0] = 0;

	// Percorre o grafo calculando as distâncias da origem.
	for(i = 0; i < c; i++)
	{
		// Se a distância do vertice atual for menor que INFINITO.
		if(dist[i] < INFINITO)
		{
			// Percorre a lista de vizinhos do vértice atual.
			for(j = i; j < c; j++)
			{
				// Se tem aresta (se é vizinho).
				if(grafo_aux[i][j] > 0)
				{
					// Seta a nova distância se ela for menor que a atual.
					if(dist[j] > dist[i] + grafo_aux[i][j])
					{
						dist[j] = dist[i] + grafo_aux[i][j];
						prev[j] = i;
					}
				}
			}	
		}
	}
	/*************** FIM DIJKSTRA ALGORITHM ***************/

	if(dist[c-1] < INFINITO)
		//std::cout << dist[c-1] << endl;
		printf("%d\n", dist[c-1]);
	else
		//std::cout << "-1" << endl;
		printf("-1\n");

//-----------------------------------------------------//
	// PRINT GRAFO:
	for(i = 0; i < c; i++)
	{
		for(j = 0; j < c; j++)
			std::cout << grafo[i][j] << " ";
		std::cout << endl;
	}

	std::cout << endl;

	// PRINT GRAFO AUX:
	for(i = 0; i < c; i++)
	{
		for(j = 0; j < c; j++)
			std::cout << grafo_aux[i][j] << " ";
		std::cout << endl;
	}

	return 0;
}