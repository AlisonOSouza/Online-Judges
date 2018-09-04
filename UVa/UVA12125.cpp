/*
	@problem:   March of the Penguins - 12125
	@site:      UVa Online Judge
	@author:    Alison Souza

	Fluxo máximo...
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // hypot()

using namespace std;

const int MAXN = 205;
const int INF = 0x3F3F3F3F;

typedef struct Point
{
	int x, y, penguins, jump_times;
} t_Point;

int N;
std::vector<int> G[MAXN];
int C[MAXN][MAXN];
int v_prev[MAXN];

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int out(int node)
{
	return (node >= 2 * N) ? node : N + node;
}

double dist(t_Point p1, t_Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

void connect(int i, int j, int cap)
{
	G[out(i)].push_back(j);
	G[j].push_back(out(i));
	C[out(i)][j] += cap;
}

void merge(int i, int cap)
{
	G[i].push_back(out(i));
	G[out(i)].push_back(i);
	C[i][out(i)] += cap;
}

int maxflow(int s, int t, int nn)
{
	int i, j, flow, u, v, extra, end, start;
	int f[MAXN][MAXN];

	for(i = 0; i <= nn; i++)
	{
		for(j = 0; j <= nn; j++)
		{
			f[i][j] = 0;
		}
	}
	flow = 0;
	while(true)
	{
		for(i = 0; i <= nn; i++)
			v_prev[i] = -1;
		
		queue <int> q;
		q.push(s);
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			if(u == t)
				break;
			for(i = 0; i < G[u].size(); i++)
			{
				v = G[u][i];
				if(v_prev[v] == -1 && C[u][v] - f[u][v] > 0)
				{
					q.push(v);
					v_prev[v] = u;
				}
			}
		}
		if(v_prev[t] == -1)
			break;
		extra = INF;
		end = t;
		while(end != s)
		{
			start = v_prev[end];
			extra = min(extra, C[start][end] - f[start][end]);
			end = start;
		}
		end = t;
		while(end != s)
		{
			start = v_prev[end];
			f[start][end] += extra;
			f[end][start] = -f[start][end];
			end = start;
		}
		flow += extra;
	}
	return flow;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	
	int testCases, total_penguins, source, i, j;
	double D;
	bool printed;
	t_Point p;
	std::vector<t_Point> points;

	std::cin >> testCases;
	while(testCases--)
	{
		std::cin >> N >> D;
		
		for(i = 0; i <= 2 * N + 1; i++)
		{
			for(j = 0; j <= 2 * N + 1; ++j)
				C[i][j] = 0;
			G[i].clear();
		}
		points.clear();
		
		total_penguins = 0;
		source = 2 * N;
		for(i = 0; i < N; i++)
		{
			std::cin >> p.x >> p.y >> p.penguins >> p.jump_times;
			total_penguins += p.penguins;
			points.push_back(p);
			if(p.penguins > 0) connect(source, i, p.penguins);
			if(p.jump_times > 0) merge(i, p.jump_times);
		}
		for(i = 0; i < N; i++)
		{
			for(j = i + 1; j < N; ++j)
			{
				if(dist(points[i], points[j]) <= D)
				{
					connect(i, j, INF);
					connect(j, i, INF);
				}
			}
		}
		printed = false;
		for(i = 0; i < N; i++)
		{
			if(maxflow(source, i, 2 * N + 1) == total_penguins)
			{
				if(printed)
					std::cout << " ";
				std::cout << i;
				printed = true;
			}
		}
		if(printed) std::cout << endl;
		else std::cout << "-1" << endl;
	}
	return 0;
}
