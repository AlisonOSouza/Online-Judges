#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _aresta
{
	int orig;
	int dest;
	int peso;
} aresta_t;

typedef vector<aresta_t> grafo_t;

void imprime(grafo_t g)
{
	unsigned int i;
	for (i = 0; i < g.size(); i++)
	{
		std::cout << g[i].orig << '-' << g[i].dest << " -> " << g[i].peso << endl;
	}
}

bool sortAresta(aresta_t i, aresta_t j)
{
	return i.peso < j.peso;
}

grafo_t kruskal(grafo_t g, int numVertices)
{
	unsigned int i, j;
	std::vector<int> visitados; // Lista dos vértices que já foram visitados.
	grafo_t ret; // Grafo de retorno.

	visitados.resize(numVertices, 0); // Inicializa os visitados com 0.
	ret.resize(numVertices - 1);

	// Ordenando as arestas pelo peso (menores primeiro).
	std::sort(g.begin(), g.end(), sortAresta);

	j = 0;
	// Percorrendo as arestas, do menor peso para o maior peso.
	for(i = 0; i < g.size(); i++)
	{
		if(j >= numVertices-1) break;
		
		if(visitados[g[i].orig] < 2 && visitados[g[i].dest] < 2)
		{
/*			ret[j].orig = g[i].orig;
			ret[j].dest = g[i].dest;
			ret[j].peso = g[i].peso;

			visitados[g[i].orig]++;
			visitados[g[i].dest]++;
			j++;
*/		}
	}

	return ret;
}

int main()
{
	int m, n, x, y, z, i, j;
	grafo_t grafo, res;

	std::cin >> n >> m;

	i = 1;
	while(n > 0)
	{
		grafo.clear();
		grafo.resize(m);

		for(j = 0; j < m; j++)
		{
			std::cin >> x >> y >> z;

			if(x < y)
			{
				grafo[j].orig = x;
				grafo[j].dest = y;
				grafo[j].peso = z;
			}
			else
			{
				grafo[j].orig = y;
				grafo[j].dest = x;
				grafo[j].peso = z;
			}
		}

		imprime(grafo);

		res = kruskal(grafo, n);

		//std::cout << "Teste " << i << endl;
		std::cout << endl << "------------" << endl;
		imprime(res);

		std::cin >> n >> m;
	}

	return 0;
}