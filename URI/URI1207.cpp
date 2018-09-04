/*
	@problem:   Os Benefícios da Vodka - 1207
	@site:      URI Online Judge
	@author:    Alison Souza
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 605;
const int MAXM = 405;
const int INF = 0x3f3f3f3f;

typedef struct edge
{
	int x, y, c, f;
	edge *next, *back;
	edge() {}
	edge(int x, int y, int c, edge* next) : 
		x(x), y(y), c(c), f(0), next(next), back(0) {}
} t_Edge;

t_Edge *E[MAXN * MAXM + 5];
t_Edge *pool = new t_Edge[MAXN * MAXM + 5], *data;

void bfs(int* D, int length, int &source, int &sink)
{
	int head, tail, i, j;
	int Q[MAXN * MAXM + 5];
	t_Edge* e;

	memset(D, -1, length);
	head = 0;
	tail = 0;
	Q[tail++] = source;
	D[source] = 0;

	while(head != tail)
	{
		i = Q[head++];
		for(e = E[i]; e != NULL; e = e->next)
		{
			if(e->c == 0)
				continue;
			j = e->y;
			if(D[j] == -1)
			{
				D[j] = D[i] + 1;
				Q[tail++] = j;
				if(j == sink)
					return;
			}
		}
	}
}

int maxFlow(int &source, int &sink)
{
	int res, path_n, i, mink, delta, k, length;
	length = MAXN * MAXM + 5;
	int D[length];
	t_Edge* e;
	t_Edge* cur[length];
	t_Edge* path[length];

	res = 0;
	while(1)
	{
		bfs(D, length, source, sink);
		if(D[sink] == -1)
			break;

		memcpy(cur, E, sizeof(E));
		
		path_n = 0;
		i = source;

		while(1)
		{
			if(i == sink)
			{
				mink = 0;
				delta = INF;
				for(k = 0; k < path_n; k++)
				{
					if(path[k]->c < delta)
					{
						delta = path[k]->c;
						mink = k;
					}
				}
				for(k = 0; k < path_n; k++)
				{
					path[k]->c -= delta;
					path[k]->back->c += delta;
				}
				path_n = mink;
				i = path[path_n]->x;
				res += delta;
			}

			for(e = cur[i]; e != NULL; e = e->next)
			{
				if(e->c == 0)
					continue;
				if(D[i] + 1 == D[e->y])
					break;
			}
			cur[i] = e;
			if(e != NULL)
			{
				path[path_n++] = e;
				i = e->y;
			}
			else
			{
				D[i] = -1;
				if(path_n == 0)
					break;
				path_n--;
				i = path[path_n]->x;
			}
		}
	}
	return res;
}

void insertEdge(int x, int y, int w)
{
	E[x] = new edge(x, y, w, E[x]);
	E[y] = new edge(y, x, 0, E[y]);
	E[x]->back = E[y];
	E[y]->back = E[x];
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, M, s, curr, i, j, ans, source, sink;

	while(std::cin >> N >> M)
	{
		int C[N], B[M], cnt[M];

		s = 0;
		memset(E, 0, sizeof(E));
		data = pool;
		source = 0;
		sink = N + M + 2;

		for(i = 1; i <= N; i++)
		{
			std::cin >> C[i];
			insertEdge(source, i, C[i]);
		}

		for(i = 1; i <= M; i++)
			std::cin >> cnt[i];

		for(i = 1; i <= M; i++)
		{
			std::cin >> B[i];
			s += B[i];
			insertEdge(N + i, sink, B[i]);

			for(j = 0; j < cnt[i]; j++)
			{
				std::cin >> curr;
				insertEdge(curr, N + i, INF);
			}
		}

		ans = s - maxFlow(source, sink);
		std::cout << ans << endl;
	}
	return 0;
}
