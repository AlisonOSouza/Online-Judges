/*
	@problem:	Freckles - 10034
	@site:		UVa
	@author:	Alison Souza

	Basta gerar o grafo completo (n*n arestas), e calcular a AGM.
*/

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef struct point
{
	double x;
	double y;
} t_Point;

typedef struct edge
{
	double cost;
	int orig;
	int dest;
} t_Edge;

// Necessaria sobrecarga de operador para poder utilizar priority_queue.
bool operator <(const t_Edge e, const t_Edge f)
{
	// Peso maior deve ser pior que peso menor.
	return e.cost > f.cost;
}

double distPitagoras(t_Point p, t_Point q)
{
	double x, y;
	x = p.x - q.x;
	y = p.y - q.y;

	return sqrt((x * x) + (y * y));
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int cases, n, i, j, m;
	double AGMLength;
	
	std::cin >> cases;
	while(cases--)
	{
		std::cin >> n;
		t_Point p[n];
		double dist[n][n];

		// Leio os pontos.
		for(i = 0; i < n; i++)
			std::cin >> p[i].x >> p[i].y;

		// Calculo a distancia entre todos os pontos.
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				dist[i][j] = distPitagoras(p[i], p[j]);
			}
		}

		// AGM com priority queue.
		priority_queue<t_Edge> pq;
		std::vector<bool> flags(n, false);

		AGMLength = 0;
		m = 0;

		for(i = 1; i < n; i++)
		{
			flags[m] = true;
			for(j = 1; j < n; j++)
			{
				t_Edge e;
				e.cost = dist[m][j];
				e.dest = j;
				e.orig = m;
				pq.push(e);
			}

			if(!pq.empty())
			{
				t_Edge min = pq.top();
				while(flags[min.dest])
				{
					pq.pop();
					min = pq.top();
				}
				m = min.dest;
				AGMLength += min.cost;
			}
		}
		std::cout.precision(2);
		std::cout << std::fixed << AGMLength << endl;
		if(cases > 0) std::cout << endl;
	}
	return 0;
}