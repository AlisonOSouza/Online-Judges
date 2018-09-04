/*
	@problem:	Book Club - bookclub
	@site:		Kattis Problem Archive
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

using namespace std;

bool match(int curr, std::vector< std::vector<int> >& adj,
					std::vector<int>& left, std::vector<int>& right,
					std::vector<int>& vis)
{
	std::vector<int>::iterator it;

	if(vis[curr]) return false;
	vis[curr] = true;

	for(it = adj[curr].begin(); it != adj[curr].end(); it++)
	{
		if(right[*it] == -1 || match(right[*it], adj, left, right, vis))
		{
			left[curr] = *it;
			right[*it] = curr;
			return true;
		}
	}
	return false;
}

int bipartite(std::vector< std::vector<int> >& adj, int n, int m)
{
	int i, ret;
	bool works;
	std::vector<int> left(n, -1), right(m, -1), vis(n);
	
	works = true;
	while(works)
	{
		works = false;
		fill(vis.begin(), vis.end(), 0);
		for(i = 0; i < n; i++)
		{
			if(left[i] == -1)
				works = works | match(i, adj, left, right, vis);
		}
	}

	ret = 0;
	for(i = 0; i < n; i++)
		ret += (left[i] != -1);

	return ret;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, M, i, A, B;
	std::cin >> N >> M;

	std::vector< std::vector<int> > adj(N);
	for(i = 0; i < M; i++)
	{
		std::cin >> A >> B;
		adj[A].push_back(B);
	}

	if(bipartite(adj, N, N) == N)
		std::cout << "YES" << endl;
	else
		std::cout << "NO" << endl;

	return 0;
}