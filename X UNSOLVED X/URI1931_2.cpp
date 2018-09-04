/*
	@problem:	Mania de Par (Even Obsession) - 1931
	@site:		URI Online Judge
	@author:	Alison Souza


	TÁ DANDO WRONG ANSWER 30%
*/

#include <iostream>
#include <vector>
#include <cstdio>

#define INFINITO 1000000

using namespace std;

typedef struct estrada
{
	int destino;
	int pedagio;
} t_Estrada;

int main(int argc, char* argv[])
{
	//ios_base::sync_with_stdio(false);

	int c, v, c1, c2, g, i, j, k, vizinho;
	t_Estrada est, est2;

	// Lê o número de cidades e de estradas.
	//std::cin >> c >> v;
	scanf("%d %d", &c, &v);

	// Gera a lista de estradas
	std::vector< vector <t_Estrada> > estradas(c+1);
	// Gera a matriz do grafo auxiliar.
	std::vector< vector<int> > estradas_aux(c+1, vector<int>(c+1));

	while(v--)
	{
		// Lê a origem e destino da estrada, além do valor do pedágio.
		//std::cin >> c1 >> c2 >> g;
		scanf("%d %d %d", &c1, &c2, &g);
		// Preenche a lista de estradas.
		est.destino = c2;
		est.pedagio = g;
		estradas[c1].push_back(est);
		est2.destino = c1;
		est2.pedagio = g;
		estradas[c2].push_back(est2);

	}

	// Dado a lista de estradas original, irei gerar uma lista auxiliar
	// que terá uma estrada entre as cidades 'a' e 'c' se, e somente se,
	// houver uma cidade 'b' tal que existe uma estrada de 'a' para 'b'
	// e existe uma estrada de 'b' para 'c'.
	for(i = 1; i < c+1; i++)
	{
		// Percorre os vizinhos da cidade atual.
		for(j = 0; j < estradas[i].size(); j++)
		{
			vizinho = estradas[i][j].destino;
			// Percorre os vizinhos do vizinho.
			for(k = 0; k < estradas[vizinho].size(); k++)
			{
				if(i != estradas[vizinho][k].destino)
				{
					if(estradas_aux[i][estradas[vizinho][k].destino] == 0 || estradas_aux[i][estradas[vizinho][k].destino] > estradas[i][j].pedagio + estradas[vizinho][k].pedagio)
					{
						estradas_aux[i][estradas[vizinho][k].destino] = estradas[i][j].pedagio + estradas[vizinho][k].pedagio;
						estradas_aux[estradas[vizinho][k].destino][i] = estradas[i][j].pedagio + estradas[vizinho][k].pedagio;
					}
				}
			}


		}
	}

	// // Dado o grafo original, irei gerar um grafo auxiliar que terá arestas
	// // entre 'i' e 'k' se, e somente se, houver um vértice 'j' tal que
	// // existe aresta de 'i' para 'j' e existe aresta de 'j' para 'k'.
	// for(i = 0; i < c; i++)
	// {
	// 	for(j = 0; j < c; j++)
	// 	{
	// 		for(k = i; k < c; k++) // Acho que deve ser 0 aqui...
	// 		{
	// 			if(grafo[i][j] > 0 && grafo[j][k] > 0 && i != k)
	// 			{
	// 				if(grafo_aux[i][k] == 0 || grafo_aux[i][k] >  grafo[i][j] + grafo[j][k])
	// 				{
	// 					grafo_aux[i][k] = grafo[i][j] + grafo[j][k];
	// 					grafo_aux[k][i] = grafo[i][j] + grafo[j][k];
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	
	// Agora irei usar Dijkstra para procurar o menor caminho no grafo
	// auxiliar. Dessa forma, todos os caminhos encontrados usarão um 
	// número par de estradas (e pedágios).
	
	/***************** DIJKSTRA ALGORITHM *****************/
	int dist[c+1];				// Distância de cada vertice.
	int prev[c+1];				// Vértice anterior (pai).
	// Seta valores padrões de distância e vértice pai.
	for(i = 0; i < c+1; i++)
	{
		dist[i] = INFINITO;
		prev[i] = -1;
	}

	// Distância da origem = 0;
	dist[1] = 0;

	// Percorre o grafo calculando as distâncias da origem.
	for(i = 1; i < c+1; i++)
	{
		// Se a distância do vertice atual for menor que INFINITO.
		if(dist[i] < INFINITO)
		{
			// Percorre a lista de vizinhos do vértice atual.
			for(j = i; j < c+1; j++)
			{
				// Se tem aresta (se é vizinho).
				if(estradas_aux[i][j] > 0)
				{
					// Seta a nova distância se ela for menor que a atual.
					if(dist[j] > dist[i] + estradas_aux[i][j])
					{
						dist[j] = dist[i] + estradas_aux[i][j];
						prev[j] = i;
					}
				}
			}	
		}
	}
	/*************** FIM DIJKSTRA ALGORITHM ***************/

	if(dist[c] < INFINITO)
		//std::cout << dist[c-1] << endl;
		printf("%d\n", dist[c]);
	else
		//std::cout << "-1" << endl;
		printf("-1\n");

// //-----------------------------------------------------//
	// PRINT LISTA:
	for(i = 1; i < c+1; i++)
	{
		printf("%d: ", i);
		for (j = 0; j < estradas[i].size(); j++)
			printf("%d (%d) ", estradas[i][j].destino, estradas[i][j].pedagio);
		printf("\n");
	}

	printf("--------------\n");

	// PRINT LISTA AUXILIAR:
	for(i = 1; i < c+1; i++)
	{
		for(j = 1; j < c+1; j++)
			printf("%2d ", estradas_aux[i][j]);
		printf("\n");
	}

	return 0;
}