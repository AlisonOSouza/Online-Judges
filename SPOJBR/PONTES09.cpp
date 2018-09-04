/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 6
PROBLEMA:	#5 PONTES09 - Caminho das Pontes

SOLUÇÃO PROPOSTA:
Modelamos este problema em um grafo bidirecionado e ponderado, utilizando
uma lista de adjacências. Para resolver esse problema, escolhi usar o
algoritmo de Dijkstra que busca o menor caminho. Após preencher o grafo
com as arestas e seus respectivos pesos, chamo a função dijkstra. Para
auxiliar essa função, uso um vetor dist que marca a distância entre a
origem (passada como parâmetro) e cada vértice do grafo. Também uso uma
fila (nesse caso fila de prioridades) que ajudará a escolher a ordem de
análise dos vértices. Começo inserindo a origem na fila, e para cada
vizinho 'i' da origem, verifico o custo (buracos) da aresta entre origem
e 'i', e checo se a distância conhecida até 'i' (inicialmente infinito)
é maior que a distância até a origem (zero) mais o custo da origem até 'i'.
Caso seja maior, atualizo a distância até 'i' como a distância da origem
mais o custo da origem até 'i' e insiro 'i' na fila. Após isso, removo a
origem da fila e faço o mesmo procedimento para o próximo da fila, até
que não falte mais nenhum vértice. Ao final das iterações, retorno o
valor da distância do vértice de destino, e imprimo essa distância.
\*******************************************************************/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define max 99999

typedef vector< vector< pair<int, int> > > grafo_t;

int dijkstra (grafo_t g, int orig, int dest)
{
	int i, elemento, custo, atual;
	std::vector<int> dist;
	priority_queue<int> fila;
	
	dist.resize(g.size(), max);

	dist[orig] = 0;

	fila.push(orig);

	while(!fila.empty())
	{
		atual = fila.top();
		fila.pop();

		for(i = 0; i < g[atual].size(); i++)
		{
			elemento = g[atual][i].first;
			custo = g[atual][i].second;

			if(dist[elemento] > dist[atual] + custo)
			{
				dist[elemento] = dist[atual] + custo;
				fila.push(elemento);
			}
		}
	}
	return dist[dest];
}

int main()
{
	int n, m, s, t, b, res;
	grafo_t grafo;

	std::cin >> n >> m;

	grafo.resize(n+2);

	while(m > 0)
	{
		std::cin >> s >> t >> b;
		grafo[s].push_back(make_pair(t, b));
		grafo[t].push_back(make_pair(s, b));
		m--;
	}

	res = dijkstra(grafo, 0, n+1);
	std::cout << res;

	return 0;
}