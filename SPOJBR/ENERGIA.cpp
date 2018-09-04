/*
	@problem:	Transmissão de Energia - ENERGIA
	@site:		SPOJ BR
	@author:	Alison Souza

	Neste problema, leio o número de estações e de linhas de transmissão e crio
	um laço para ler cada linha. Gero um grafo bidirecionado, onde as estações
	são vértices e as linhas de transmissão são arestas. Após isso, faço uma
	busca em largura a partir de cada vértice, para saber se cada vértice
	consegue acessar todos os outros vértices do grafo. Caso não seja possível
	acessar todos os vértices, a busca retorna falso e imprimo falha. Caso
	seja possível, continuo executando a busca em cada vértice até acabar os
	vértices. Nesse ponto, imprimo normal.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > grafo_t;

bool bfs(grafo_t grafo, int start)
{
	int atual, prox, i;
	std::queue<int> fila;
	std::vector<int> visitado;

	visitado.resize(grafo.size(), 0);
	fila.push(start);

	while(!fila.empty())
	{
		atual = fila.front();
		fila.pop();

		for(i = 0; i < grafo[atual].size(); i++)
		{
			if(grafo[atual][i] == 1) 
				prox = i;
			else
				continue;
			if(visitado[prox] == 0)
			{
				visitado[prox] = 1;
				fila.push(prox);
			}
		}
	}

	for(i = 0; i < visitado.size(); i++)
	{
		if(visitado[i] == 0)
			return false;
	}
	return true;

}

int main()
{
	int v, e, v1, v2, i, j;
	grafo_t grafo;

	std::cin >> v >> e;
	j = 1;
	while(v > 0 && e > 0)
	{
		grafo.clear();
		grafo.resize(v);
		for(i = 0; i < v; i++)
			grafo[i].resize(v, 0);
	
		while(e > 0)
		{
			std::cin >> v1 >> v2;

			grafo[v1-1][v2-1] = 1;
			grafo[v2-1][v1-1] = 1;
			
			e--;
		}

		std::cout << "Teste " << j << endl;

		bool flag = true;
		for(i = 0; i < v; i++)
		{
			flag = bfs(grafo, i);
			if(!flag)
			{
				std::cout << "falha" << endl;
				break;
			}
		}
		if(flag) std::cout << "normal" << endl;

		j++;
		std::cin >> v >> e;
		if(v > 0 && e > 0) std::cout << endl;
	}

	return 0;
}