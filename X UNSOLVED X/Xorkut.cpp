#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef vector< vector<int> > grafo_t;

void imprime(grafo_t g)
{
	int i, j;
	for(i = 0; i < g.size(); i++)
	{
		for(j = 0; j < g.size(); j++)
			std::cout << g[i][j] << " ";
		std::cout << endl;
	}
}

void dfs(grafo_t g, int start, vector<bool> visitado, vector<int> resultado)
{
	int i;

	if(!visitado[start])
	{
		visitado[start] = true;
		for(i = 0; i < g.size(); i++)
		{
			if(g[start][i] == 1)
			{
				dfs(g, i, visitado, resultado);
			}
		}
		resultado.push_back(start);
	}
}

int main()
{
	int n, r, i, j, k, start;
	string s, t;
	grafo_t grafo;
	std::map<string, int>::iterator it;
	std::map<string, int> mapa;
	std::vector<bool> visitado;
	std::vector<int> resultado;

	std::cin >> n;

	k = 1;
	while(n > 0)
	{
		grafo.clear();
		grafo.resize(n);
		for(i = 0; i < n; i++)
			grafo[i].resize(n, 0);
		mapa.clear();
		visitado.clear();
		visitado.resize(n, false);
		resultado.clear();
		resultado.resize(1, 0);

		for(i = 0; i < n; i++)
		{
			std::cin >> s;
			mapa.insert(std::pair<string, int>(s, i));
		}

		for(i = 0; i < n; i++)
		{
			std::cin >> s >> r;
			for(j = 0; j < r; j++)
			{
				cin >> t;
				grafo[mapa.find(s)->second][mapa.find(t)->second] = 1;
			}
			if(r == 0)
			{
				start = mapa.find(s)->second;
			}
		}

		
		std::cout << "Teste " << k << endl;
		dfs(grafo, start, visitado, resultado);
		if(resultado.size() == 0)
		{
			std::cout << "impossivel" << endl;
		}
		else
		{
			for(i = 0; i < resultado.size(); i++)
			{
				/*for(it = mapa.begin(); it != mapa.end(); it++)
				{	
					if(it->second == resultado[i])
					{
						std::cout << it->first << endl;
						//break;
					}
				}*/
			}
		}

		//imprime(grafo);

		k++;
		std::cin >> n;
		if(n > 0) std::cout << endl;
	}

	/*std::map<string, int>::iterator it;
	for (it=mapa.begin(); it!=mapa.end(); ++it)
    	std::cout << it->first << " => " << it->second << endl;*/


	return 0;
}