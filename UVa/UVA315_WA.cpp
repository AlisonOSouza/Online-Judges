/*
	@problem:	Network - 315
	@site:		UVa Online Judge
	@author:	Alison Souza

	Técnica: Vértice de corte (ponto de articulação)
	https://pt.wikipedia.org/wiki/V%C3%A9rtice_de_corte_(teoria_dos_grafos)
	https://en.wikipedia.org/wiki/Biconnected_component

	Dá wrong answer...
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

std::vector< vector<int> > grafo;
std::vector<bool> visited;
std::vector<int> parent;
std::vector<int> depth;
std::vector<int> low;
std::vector<int> artVertex;
int childCount;

int Min(int a, int b)
{
	return (a < b) ? a : b;
}

// getArtVertex() recebe um vértice 'v', a profundidade d, e o tamanho do grafo 'n'.
void getArtVertex(int v, int d, int n)
{
	int i;
	bool isArticulation;

	visited[v] = true;
	depth[v] = d;
	low[v] = d;
	childCount = 0;
	isArticulation = false;

	// Percorre os vizinhos de 'v'.
	for(i = 0; i <= n; i++)
	{
		// Se 'i' é vizinho de 'v'.
		if(grafo[v][i] != 0)
		{
			// Se 'i' não foi visitado ainda.
			if(!visited[i])
			{
				// Marca que 'v' é o pai de 'i'.
				parent[i] = v;
				// Chama a busca no vértice 'i', como uma DFS.
				getArtVertex(i, d+1, n);

				if(v != 1) childCount++;

				if(low[i] >= depth[v])
					isArticulation = true;

				low[v] = Min(low[v], low[i]);
			}
			else if(i != parent[v])
				low[v] = Min(low[v], depth[i]);
		}
	}
	if((parent[v] != -1 && isArticulation) || (parent[v] == -1 && childCount > 1))
		artVertex.push_back(v);
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, a, b;
	string line;

	while(std::cin >> n && n != 0)
	{
		cin.ignore();
		// std::cout << n << endl;

		grafo.clear();
		grafo.resize(n+1, vector<int>(n+1));
		visited.clear();
		visited.resize(n+1, false);
		parent.clear();
		parent.resize(n+1, -1);
		depth.clear();
		depth.resize(n+1, -1);
		low.clear();
		low.resize(n+1, -1);
		artVertex.clear();
		
		while(std::getline(std::cin, line) && line[0] != '0')
		{
			stringstream input(line);
			input >> a;
			while(input >> b)
			{
				// std::cout << "(" << a << ", " << b << ")" << endl;
				grafo[a][b] = 1;
				grafo[b][a] = 1;
			}
		}
		
		getArtVertex(1, 0, n);
		std::cout << artVertex.size() << endl;

		for(int i = 0; i < artVertex.size(); i++)
			std::cout << artVertex[i] << endl;
		std::cout << "------------" << endl;

		// PRINT GRAFO
		for(a = 1; a < n+1; a++)
		{
			for(b = 1; b < n+1; b++)
				std::cout << grafo[a][b] << " ";
			std::cout << endl;
		}
		std::cout << "-----------" << endl;
	}

	return 0;
}