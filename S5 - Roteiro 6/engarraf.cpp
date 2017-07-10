/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 6
PROBLEMA:	#2 ENGARRAF - Engarrafamento

SOLUÇÃO PROPOSTA:
Neste problema, temos uma busca pelo menor caminho em um grafo direcionado
e ponderado. Para resolver esse problema, escolhi usar o algoritmo de 
Dijkstra que busca o menor caminho. Uso um grafo por lista de adjacência,
e após preencher o grafo com as arestas e seus respectivos pesos, chamo
a função dijkstra. Para auxiliar essa função, uso um vetor de distâncias
entre a origem (passada como parâmetro) e cada vértice do grafo. Também
uso uma fila (nesse caso fila de prioridades) que ajudará a escolher a 
ordem de análise dos vértices. Começo inserindo a origem na fila, e para
cada vizinho 'i' da origem, verifico o custo da aresta entre origem e 'i'
e checo se a distância conhecida até 'i' (inicialmente infinito) é maior
que a distância até a origem (zero) mais o custo da origem até 'i'. Caso
seja maior, atualizo a distância até 'i' como a distância da origem mais
o custo da origem até 'i' e insiro 'i' na fila. Após isso, removo a origem
da fila e faço o mesmo procedimento para o próximo da fila, até que não
falte mais nenhum vértice. Ao final das iterações, retorno o valor da
distância do vértice de destino, e se ele for menor que infinito (max)
imprimo essa distância. Caso contrário, imprimo -1.
\*******************************************************************/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define max 99999

typedef vector< vector< pair<int, int> > > grafo_t;

int dijkstra (grafo_t g, int orig, int dest)
{
	int u, v, elemento, custo;
	std::vector<int> dist;
	priority_queue< pair<int, int> > fila;

	dist.resize(g.size(), max);

	dist[orig] = 0;

	fila.push(make_pair(dist[orig], orig));
	
	while(!fila.empty())
	{
		u = fila.top().second;
		fila.pop();

		for(v = 0; v < g[u].size(); v++)
		{
			custo = g[u][v].first;
			elemento = g[u][v].second;

			if(dist[elemento] > dist[u] + custo)
			{
				dist[elemento] = dist[u] + custo;
				fila.push(make_pair(dist[elemento], elemento));
			}
		}
	}
	return dist[dest];
}

int main()
{
	int n, m, i, j, t, s, d, cont, res;
	grafo_t g;

	while(true)
	{
		std::cin >> n >> m;
		if(n <= 0 && m <= 0) break;
		
		g.clear();
		g.resize(n);

		while(m > 0)
		{
			std::cin >> i >> j >> t;
			g[i-1].push_back(make_pair(t, j-1));
			m--;
		}
		
		std::cin >> s >> d;

		res = dijkstra(g, s-1, d-1);

		if(res >= max)
			std::cout << -1 << endl;
		else
			std::cout << res << endl;
	}

	return 0;
}