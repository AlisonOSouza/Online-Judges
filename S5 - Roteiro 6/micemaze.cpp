/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 6
PROBLEMA:	#8 MICEMAZE - Mice and Maze

SOLUÇÃO PROPOSTA:
Neste problema, temos uma busca pelo menor caminho em um grafo direcionado
e ponderado. Para resolver esse problema, escolhi usar o algoritmo de 
Dijkstra que busca o menor caminho. Uso um grafo por lista de adjacência,
e após preencher o grafo com as arestas e seus respectivos pesos, chamo
a função dijkstra. Para auxiliar essa função, uso um vetor de distâncias
entre a origem (que é a célula de saída 'e', passada como parâmetro) e 
cada vértice do grafo. Também uso uma fila (nesse caso fila de prioridades)
que ajudará a escolher a ordem de análise dos vértices. Começo inserindo
a origem na fila, e para cada vizinho 'i' da origem, verifico o custo da
aresta entre origem e 'i' e checo se a distância conhecida até 'i'
(inicialmente infinito) é maior que a distância até a origem (zero) mais
o custo da origem até 'i'. Caso seja maior, atualizo a distância até 'i'
como a distância da origem mais o custo da origem até 'i' e insiro 'i'
na fila. Após isso, removo a origem da fila e faço o mesmo procedimento
para o próximo da fila, até que não falte mais nenhum vértice. Ao final
das iterações, verifico quantos vértices tem menor ou igual distância que
o timer 't' e retorno essa quantidade de vértices. Após isso, imprimo
esse número de vértices que alcançam o vértice de saída em menos tempo 
que 't'.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define max 99999999

typedef vector< vector< pair<int, int> > > grafo_t;

int dijkstra (grafo_t g, int e, int t)
{
	int i, ret;
	std::vector<int> dist;
	priority_queue< pair<int, int> > fila;
	pair<int, int> atual, prox;

	dist.resize(g.size(), max);

	atual = make_pair(0, e);
	fila.push(atual);

	dist[atual.second] = 0;

	while(!fila.empty())
	{
		atual = fila.top();
		fila.pop();

		for(i = 0; i < g[atual.second].size(); i++)
		{
			prox = g[atual.second][i];

			if(dist[prox.second] > dist[atual.second] + prox.first)
			{
				dist[prox.second] = dist[atual.second] + prox.first;
				fila.push(prox);
			}
		}
	}
	ret = 0;
	dist[e] = max;
	for(i = 0; i < dist.size(); i++)
	{
		if(dist[i] <= t || i == e)
			ret++;
	}
	return ret;
}

int main()
{
	int n, e, t, m, a, b, u, res;
	grafo_t grafo;

	std::cin >> n >> e >> t >> m;

	grafo.resize(n);

	while(m > 0)
	{
		std::cin >> a >> b >> u;
		grafo[b-1].push_back(make_pair(u, a-1));
		m--;
	}

	res = dijkstra(grafo, e-1, t);
	std::cout << res << endl;

	return 0;
}