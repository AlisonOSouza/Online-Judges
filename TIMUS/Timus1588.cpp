/*
	@problem:	Jamaica - 1588
	@site:		Timus Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <cmath> // sqrt()
#include <algorithm> // std::sort()

using namespace std;

typedef struct Point
{
	int x, y;
} t_Point;

// Pra usar std::sort()
bool operator <(const t_Point p, const t_Point q)
{
	if (p.x != q.x)
		return (p.x < q.x);
	else
		return (p.y < q.y);
}

double distancePitagoras(t_Point a, t_Point b)
{
	return (sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y))));
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, i, j, k, last;
	double ans, aux1, aux2, aux3;
	t_Point cities[305];
	bool visited[305][305];

	for(i = 0; i < 305; i++)
	{
		for(j = 0; j < 305; j++)
		{
			visited[i][j] = false;
		}
	}

	std::cin >> n;

	for(i = 0; i < n; i++)
		std::cin >> cities[i].x >> cities[i].y;

	std::sort(cities, cities + n);
	ans = 0;

	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++) 
			ans += distancePitagoras(cities[i], cities[j]);

	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			aux1 = aux2 = aux3 = 0;

			if(visited[i][j])
				continue;

			visited[i][j] = true;
			last = j;

			if(cities[j].x - cities[i].x > 0)
				aux1 = (double) (cities[j].y - cities[i].y) / (cities[j].x - cities[i].x);

			for(k = j + 1; k < n; k++)
			{
				if(cities[k].x - cities[i].x)
					aux2 = (double) (cities[k].y - cities[i].y) / (cities[k].x - cities[i].x);

				if(cities[k].x - cities[j].x)
					aux3 = (double) (cities[k].y - cities[j].y) / (cities[k].x - cities[j].x);

				if((aux1 != aux2) || (aux2 != aux3))
					continue;

				ans -= distancePitagoras(cities[last], cities[i]);
				last = k;
				visited[i][k] = true;
			}
			if(last != j)
				ans -= distancePitagoras(cities[j], cities[last]);
		}
	}
	std::cout << (int) floor(ans + 0.5) << endl;
	return 0;
}
