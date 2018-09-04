/*
	@problem:	Bicoloring - 10004
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	int nodes, edges, v1, v2, i;
	bool flag;

	while(std::cin >> nodes && nodes > 0)
	{
		// Gera o grafo (sem arestas), o vetor de cores (iniciado com -1
		// pra todos vertices) e a fila de vertices (para ordenar a DFS).
		std::vector<vector<int> > graph(nodes);
		std::vector<int> color(nodes, -1);
		std::queue<int> fila;
		
		// Le as arestas e adiciona no grafo
		std::cin >> edges;
		for(i = 0; i < edges; i++)
		{
			std::cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		// Escolho um vertice, coloro ele, e enfileiro para comecar a DFS.
		color[0] = 0;
		fila.push(0);
		flag = true;
		while(!fila.empty() && flag)
		{
			// Pego o primeiro elemento da fila.
			v1 = fila.front();
			fila.pop();
			// Percorro seus vizinhos.
			for(i = 0; i < graph[v1].size(); i++)
			{
				// Se a cor do vizinho, for a mesma do vertice que avalio. 
				v2 = graph[v1][i];
				if(color[v2] == color[v1])
				{
					// Marco a flag como falsa e saio do loop.
					flag = false;
					break;
				}
				// Se não for a mesma cor, marco como 'conhecido'  e
				// enfileiro o vizinho.
				else if(color[v2] == -1)
				{
					color[v2] = 1 - color[v1]; 
					fila.push(v2);
				}
			}
			// Se a flag for falsa, para o while.
			if(!flag) break;
		}
		// Verifica a flag e imprime a resposta.
		if(flag)
			std::cout << "BICOLORABLE." << endl;
		else
			std::cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}