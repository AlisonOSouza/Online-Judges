/*
	@problem:	Joining Couples - 6140
	@site:		ACM-ICPC Live Archive
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100005
#define MAXD 18

int tot, fa[MAXN][MAXD];

void pfs(std::vector<int> &cir_cnt, std::vector<int> &cir_no,
		 std::vector<int> &nxt, std::vector<int> &cir,
		 std::vector<int> &dfs_no, int v, int n)
{
	int i, last;

	dfs_no[v] = n;
	if(!dfs_no[nxt[v]])
	{
		pfs(cir_cnt, cir_no, nxt, cir, dfs_no, nxt[v], n);
	}
	else if(dfs_no[nxt[v]] == n)
	{
		tot++;
		cir[v] = tot;
		cir_cnt[tot] = 1;
		cir_no[v] = 1;

		last = v;
		for(i = nxt[v]; i != v; i = nxt[i])
		{
			cir[i] = cir[last];
			cir_no[i] = cir_no[last] + 1;
			cir_cnt[tot]++;
			last = i;
		}
	}
}

void dfs(std::vector<int> &vis, std::vector<int> &gen, 
		 std::vector<int> &nxt, std::vector<int> &cir,
		 std::vector<int> &dep, int v)
{
	vis[v] = 1;
	if(!cir[v])
	{
		fa[v][0] = nxt[v];
		if(!vis[nxt[v]])
			dfs(vis, gen, nxt, cir, dep, nxt[v]);

		gen[v] = gen[nxt[v]];
		dep[v] = dep[nxt[v]] + 1;
	}
	else
	{
		fa[v][0] = 0;
		gen[v] = v;
		dep[v] = 0;
	}
}

int dist(std::vector<int> &dep, int u, int v)
{
	int i, j, t, u_, v_;
	u_ = u;
	v_ = v;

	if(dep[u] > dep[v])
	{
		t = u;
		u = v;
		v = t;
	}

	for(i = 0, j = dep[v] - dep[u]; i < MAXD && j > 0; i++, j /= 2)
		if(j % 2 == 1)
			v = fa[v][i];
	
	if(u == v)
		return dep[u_] + dep[v_] - 2 * dep[u];

	for(i = MAXD - 1; i >= 0; i--)
		if(fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	
	return dep[u_] + dep[v_] - 2 * dep[fa[u][0]];
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, Q, i, u, v, d, tmp1, tmp2, now;

	while(std::cin >> N)
	{
		std::vector<int> vis(N+5, 0);
		std::vector<int> nxt(N+5, 0);
		std::vector<int> cir(N+5, 0);
		std::vector<int> gen(N+5, 0);
		std::vector<int> dep(N+5, 0);
		std::vector<int> cir_cnt(N+5, 0);
		std::vector<int> cir_no(N+5, 0);
		std::vector<int> dfs_no(N+5, 0);

		tot = 0;

		for(i = 1; i <= N; i++)
			std::cin >> nxt[i];

		for(i = 1; i <= N; ++i)
			if(!dfs_no[i])
			{
				now = i;
				pfs(cir_cnt, cir_no, nxt, cir, dfs_no, i, now);
			}

		for(i = 1; i <= N; i++)
			if(!vis[i])
				dfs(vis, gen, nxt, cir, dep, i);

		for(d = 1; d < MAXD; d++)
			for(i = 1; i <= N; i++)
				fa[i][d] = fa[fa[i][d - 1]][d - 1];

		std::cin >> Q;
		for(i = 0; i < Q; i++)
		{
			std::cin >> u >> v;
			if(cir[gen[u]] != cir[gen[v]])
				std::cout << "-1" << endl;
			else if(gen[u] == gen[v])
				std::cout << dist(dep, u, v) << endl;
			else
			{
				tmp1 = dep[u] + dep[v];
				tmp2 = cir_no[gen[u]] - cir_no[gen[v]];
				if(tmp2 < 0)
					tmp2 = -tmp2;
				if(tmp2 > cir_cnt[cir[gen[u]]] - tmp2)
					tmp2 = cir_cnt[cir[gen[u]]] - tmp2;
				std::cout << tmp1 + tmp2 << endl;
			}
		}
	}
	return 0;
}
