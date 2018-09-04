/*
	@problem:	Hooligan - 1394
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

#define MAX_VERTEX 3005
#define MAX_EDGES 9000
#define INF 0x3f3f3f3f

int V, E, t, f, sz;
// std::vector<int> flow, cap, to, prox, last, path;
int flow[2*MAX_EDGES], cap[2*MAX_EDGES], to[2*MAX_EDGES], prox[2*MAX_EDGES], last[MAX_VERTEX], path[MAX_VERTEX];
bool visited[MAX_VERTEX], found;

int min(int a, int b)
{
	return (a < b) ? a : b;
}

void dfs(int u, int depth)
{
	int v, num;

	if(u == t)
	{
		sz = depth;
		found = true;
		return;
	}
	
	for(num = last[u]; num != -1 && !found; num = prox[num])
	{
		v = to[num];
		
		if(!visited[v] && flow[num] < cap[num])
		{
			visited[v] = true;
			path[depth] = num;
			dfs(v, depth + 1);
		}
	}
}

bool expanding()
{
	int i, aux;

	for(i = 0; i < V; i++)
		visited[i] = false;
	
	found = false;
	sz = 0;
	dfs(0, 0);
	
	if(!found)
		return false;
	
	aux = INF;
	
	for(i = 0; i < sz; i++)
		aux = min(aux, cap[path[i]] - flow[path[i]]);
	
	f += aux;
	
	for(i = 0; i < sz; i++)
	{
		flow[path[i]] += aux;
		flow[path[i]^1] -= aux;
	}
	
	return true;
}


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, M, G, a, b, res, m, i, j, k;
	int points[40];
	int games[40][40];
	char op;
	bool flag;
	
	while(std::cin >> N >> M >> G && N > 0 && M > 0 && G > 0)
	{
		for(i = 0; i < N; i++)
		{
			points[i] = 0;

			for (j = 0; j < N; j++)
				games[i][j] = M;
		}
		
		res = M * N * (N-1) / 2 - G;
		
		for(i = 0; i < G; i++)
		{
			std::cin >> a >> op >> b;
			games[a][b]--;
			games[b][a]--;
			if(op == '=')
			{
				points[a]++;
				points[b]++;
			} 
			else
			{
				points[b] += 2;
			}
		}
		
		for(i = 1; i < N; i++)
		{
			points[0] += 2 * games[0][i];
			res -= games[0][i];
		}
		
		flag = true;
		for(i = 1; i < N; i++)
			if(points[i] >= points[0])
				flag = false;
		
		if(!flag)
		{
			std::cout << "N" << endl;
			continue;
		}
		
		V = 1 + res + N;
		E = 0;
		
		for(i = 0; i < 2*MAX_EDGES; i++)
			prox[i] = -1;

		for (i = 0; i < V; i++)
			last[i] = -1;
		
		for(i = 1; i <= res; i++){
			to[E] = i;
			cap[E] = 2;
			prox[E] = last[0];
			last[0] = E++;
			
			to[E] = 0;
			cap[E] = 0;
			prox[E] = last[i];
			last[i] = E++;
		}
		
		m = 1;
		
		for(i = 1; i < N; i++)
		{
			for(j = i + 1; j < N; j++)
			{
				for(k = 0; k < games[i][j]; k++)
				{
					to[E] = res + i;
					cap[E] = 2;
					prox[E] = last[m];
					last[m] = E++;
					
					to[E] = m;
					cap[E] = 0;
					prox[E] = last[res + i];
					last[res + i] = E++;
					
					to[E] = res + j;
					cap[E] = 2;
					prox[E] = last[m];
					last[m] = E++;
					
					to[E] = m;
					cap[E] = 0;
					prox[E] = last[res + j];
					last[res + j] = E++;
					
					m++;
				}
			}
		}
		
		for(i = 1; i < N; i++)
		{
			to[E] = V - 1;
			cap[E] = points[0] - points[i] - 1;
			prox[E] = last[res + i];
			last[res + i] = E++;
			
			to[E] = res + i;
			cap[E] = 0;
			prox[E] = last[V - 1];
			last[V - 1] = E++;
		}
		
		for(i = 0; i < E; i++)
			flow[i] = 0;

		t = V - 1;
		f = 0;
		
		while(expanding());
		
		if(f == res * 2) 
			std::cout << "Y" << endl;
		else
			std::cout << "N" << endl;
	}
	return 0;
}