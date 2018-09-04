/*
	@problem:	Query on a tree - QTREE
	@site:		SPOJ
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

#define MAXN 10005

using namespace std;

std::vector<int> graph[MAXN], cost[MAXN], edges[MAXN];

int left(int i)
{
	return (i*2) + 1;
}

int right(int i)
{
	return (i*2) + 2;
}

void build(std::vector<int> &stree, std::vector<int> &array, int node, int l, int r)
{
	int mid;

	if(l == r)
	{
		stree[node] = array[l];
	} 
	else
	{
		mid = (l + r) / 2;
		build(stree, array, left(node), l, mid);
		build(stree, array, right(node), mid + 1, r);

		if(stree[left(node)] > stree[right(node)])
			stree[node] = stree[left(node)];
		else
			stree[node] = stree[right(node)];
	}
}

void update(std::vector<int> &stree, int node, int l, int r, int index, int val)
{
	int mid;

	if(index < l || r < index )
		return;

	if(l == r)
	{
		stree[node] = val;
	}
	else
	{
		mid = (l + r) / 2;
		update(stree, left(node), l, mid, index, val);
		update(stree, right(node), mid + 1, r, index, val);

		if(stree[left(node)] > stree[right(node)])
			stree[node] = stree[left(node)];
		else
			stree[node] = stree[right(node)];
	}
}

int query(std::vector<int> &stree, int node, int l, int r, int a, int b)
{
	int mid, q1, q2;

	if(b < l || r < a)
		return 0;
	if(a <= l && r <= b)
		return stree[node];

	mid = (l + r) / 2;
	q1 = query(stree, left(node), l, mid, a, b);
	q2 = query(stree, right(node), mid + 1, r, a, b);

	return max(q1, q2);
}

void dfs(std::vector<int> &subtree, std::vector<int> &parent, std::vector<int> &aux, int v, int pv)
{
	unsigned int i;

	parent[v] = pv;
	aux[v] = aux[pv] + 1 ;
	subtree[v] = 1;	

	for(i = 0; i < graph[v].size(); i++)
	{
		if(graph[v][i] != pv)
		{
			dfs(subtree, parent, aux, graph[v][i], v);
			subtree[v] += subtree[graph[v][i]];
		}
	}
}

void HLD(std::vector<int> &location, std::vector<int> &array, std::vector<int> &subtree, std::vector<int> &head, int v, int pv, int value, int &pos)
{
	unsigned int i;
	int maxsubtree, Cost, special;

	if(head[v] == -1)
		head[v] = v;
	else
		head[v] = head[pv];

	maxsubtree = 0;
	special = -1;
	location[v] = pos;
	array[pos++] = value;

	for(i = 0; i < graph[v].size(); i++)
	{
		if(graph[v][i] != pv)
		{
			if(subtree[graph[v][i]] > maxsubtree)
			{
				maxsubtree = subtree[graph[v][i]];	
				Cost = cost[v][i];
				special = graph[v][i];
			}
		}
	}

	if(special != -1)
	{
		HLD(location, array, subtree, head, special, v, Cost, pos);
		for(i = 0; i < graph[v].size(); i++)
		{
			if(graph[v][i] != special && graph[v][i]!= pv)
			{
				head[graph[v][i]] = -1;
				HLD(location, array, subtree, head, graph[v][i], v, cost[v][i], pos);
			}
		}
	}
}

int LCA(std::vector<int> &parent, std::vector<int> &head, std::vector<int> &aux, int i, int j)
{
	while(head[i] != head[j])
	{
		if(aux[head[j]] > aux[head[i]])
			j = parent[head[j]];
		else
			i = parent[head[i]];
	}

	if(aux[j] > aux[i])
		return i ;
	else
		return j;
}

int query_up(std::vector<int> &stree, std::vector<int> &location, std::vector<int> &parent, std::vector<int> &head, int i, int lca, int n)
{
	int maximum = 0;
	
	while(i != lca)
	{
		if(head[i] == head[lca])
		{
			maximum = max(maximum, query(stree, 0, 0, n-1, location[lca]+1, location[i]));
			break;
		}

		maximum = max(maximum, query(stree, 0, 0, n-1, location[head[i]], location[i]));
		i = parent[head[i]];
	}
	return maximum;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int testCase, N, a, b, edge_cost, node, i, lca, left, right, pos;
	string instruction;
	
	std::cin >> testCase;
	
	while(testCase--)
	{
		std::cin >> N;
		pos = 0;

		std::vector<int> location(N+1);
		std::vector<int> array(N+1);
		std::vector<int> subtree(N+1);
		std::vector<int> parent(N+1);
		std::vector<int> aux(N+1);
		std::vector<int> head(N+1, 0);
		std::vector<int> stree(4*N, 0);

		for(i = 0; i <= MAXN; i++)
		{
			graph[i].clear();
			cost[i].clear();
			edges[i].clear();
		}

		head[1] = -1;
		for(i = 1; i < N; i++)
		{
			std::cin >> a >> b >> edge_cost;
			graph[a].push_back(b);
			graph[b].push_back(a);
			cost[a].push_back(edge_cost);
			cost[b].push_back(edge_cost);
			edges[i].push_back(a);
			edges[i].push_back(b);
		}

		dfs(subtree, parent, aux, 1, 0);
		HLD(location, array, subtree, head, 1, 0, 0, pos);
		build(stree, array, 0, 0, N-1);

		while(std::cin >> instruction && instruction.compare("DONE") != 0)
		{
			std::cin >> a >> b;
			if(instruction.compare("QUERY") == 0)
			{
 				lca = LCA(parent, head, aux, a, b);
				left = query_up(stree, location, parent, head, a, lca, N);
				right = query_up(stree, location, parent, head, b, lca, N);
				std::cout << max(left, right) << endl;
			}
			else if(instruction.compare("CHANGE") == 0)
			{
				if(aux[edges[a][0]] > aux[edges[a][1]])
					node = edges[a][0];
				else
					node = edges[a][1];
				update(stree, 0, 0, N-1, location[node], b);
			}
		}
	}
	return 0;
}
