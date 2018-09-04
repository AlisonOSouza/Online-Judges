/*
	@problem:   Tree 2 - 1752
	@site:      Timus Online Judge
	@author:    Alison Souza
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAXN 20001

int level[MAXN];
int P[15][MAXN];
std::vector<int> L[MAXN];
pair<int, int> down[MAXN][2], best[MAXN][2];

void dfs(int cur, int prev, int lvl)
{
	int i, nxt;

	down[cur][0] = make_pair(cur, 0);
	down[cur][1] = make_pair(0, 0);
	
	P[0][cur] = prev;
	level[cur] = lvl;
	
	for(i = L[cur].size()-1; i >= 0; i--)
	{
		nxt = L[cur][i];
		
		if(nxt != prev)
		{
			dfs(nxt, cur, lvl + 1);
			
			if(1 + down[nxt][0].second > down[cur][1].second)
			{
				down[cur][1] = down[nxt][0];
				down[cur][1].second++;
				
				if(down[cur][1].second > down[cur][0].second)
					swap(down[cur][0], down[cur][1]);
			}
		}
	}
}

void dfs2(int cur, int prev)
{
	int i, nxt;

	best[cur][0] = down[cur][0];
	best[cur][1] = down[cur][1];
	
	if(prev != -1)
	{
		for(i = 0; i < 2; i++)
		{
			if(best[prev][i].first != down[cur][0].first)
			{
				if(1 + best[prev][i].second > best[cur][1].second)
				{
					best[cur][1] = best[prev][i];
					best[cur][1].second++;
				}
				
				if(best[cur][1].second > best[cur][0].second)
					swap(best[cur][0], best[cur][1]);
				
				break;
			}
		}
	}
	
	for(i = L[cur].size() - 1; i >= 0; i--)
	{
		nxt = L[cur][i];
		if(nxt != prev)
			dfs2(nxt, cur);
	}
}

pair<int, int> lca(int x, int y)
{
	int dist, i;

	if(level[x] < level[y])
		swap(x, y);
	
	dist = level[x] - level[y];
	
	for(i = 14; i >= 0; i--)
		if(dist & (int) pow(2, i))
			x = P[i][x];
	
	for(i = 14; i >= 0; i--)
	{
		if(P[i][x] != P[i][y])
		{
			dist += pow(2, (i + 1));
			x = P[i][x];
			y = P[i][y];
		}
	}
	
	if(x != y)
	{
		x = P[0][x];
		y = P[0][y];
		dist += 2;
	}
	return make_pair(x, dist);
}

int go_up(int x, int d)
{
	int i;
	for(i = 0; i <= 14; i++)
	{
		if(d % 2 == 1)
			x = P[i][x];
		d /= 2;
	}
	
	return x;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, Q, i, j, u, v, x, d;
	int to[MAXN], D[MAXN], D2[MAXN];
	
	std::cin >> N >> Q;
	
	// Edges
	for(i = 1; i < N; i++)
	{
		std::cin >> u >> v;
		L[u].push_back(v);
		L[v].push_back(u);
	}
	
	dfs(1, -1, 0);
	dfs2(1, -1);

	for(i = 1; pow(2, i) < N; i++)
		for(j = 1; j <= N; j++)
			if(P[i - 1][j] != -1)
				P[i][j] = P[i-1][P[i-1][j]];

	
	for(i = 1; i <= N; i++)
		to[i] = best[i][0].first;
	
	for(i = 1; i <= N; i++)
	{
		pair<int, int> aux = lca(i, to[i]);
		
		D[i] = level[i] - level[aux.first];
		D2[i] = level[ to[i] ] - level[aux.first];
	}
	
	// Queries
	for(i = 0; i < Q; i++)
	{
		std::cin >> x >> d;
		
		if(d > D[x] + D2[x])
			std::cout << "0" << endl;
		else if(d <= D[x])
			std::cout << go_up(x, d) << endl;
		else
			std::cout << go_up(to[x], (D2[x] + D[x] - d)) << endl;
	}
	return 0;
}
