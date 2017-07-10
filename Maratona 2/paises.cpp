#include <iostream>

using namespace std;

#define MAX 1000000

int matriz[501][501];

int dijkstra(int orig, int dest, int tam)
{
	int distMin, proxVert, i, j;
	int dist[tam];
	bool flag[tam];

	for(i = 1; i <= tam; i++)
	{
		dist[i] = MAX;
		flag[i] = false;
	}

	dist[orig] = 0;

	for(i = 1; i <= tam; i++)
	{
		distMin = MAX;

		if(flag[dest]) break;

		for(j = 1; j <= tam; j++)
		{
			if(dist[j] < distMin && !flag[j])
			{
				distMin = dist[j];
				proxVert = j;
			}
		}

		if(distMin == MAX) break;

		flag[proxVert] = true;

		for(j = 1; j <= tam; j++)
		{
			if(distMin + matriz[proxVert][j] < dist[j])
				dist[j] = distMin + matriz[proxVert][j];
		}
	}

	return dist[dest];
}

int main()
{
	int n, e, x, y, h, k, o, d, i, j, res;

	while((std::cin >> n >> e) && n)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				matriz[i][j] = MAX;
			}
		}

		while(e--)
		{
			std::cin >> x >> y >> h;
			matriz[x][y] = h;
			if(matriz[y][x] != MAX)
			{
				matriz[y][x] = 0;
				matriz[x][y] = 0;
			}
		}

		std::cin >> k;

		while(k--)
		{
			std::cin >> o >> d;
			res = dijkstra(o, d, n);
			if(res == MAX)
				std::cout << "Nao e possivel entregar a carta" << endl;
			else
				std::cout << res << endl;
		}

		std::cout << endl;
	}

	return 0;
}