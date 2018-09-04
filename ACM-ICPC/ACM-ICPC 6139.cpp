/*
	@problem:	Interval Product - 6139
	@site:		ACM-ICPC Live Archive
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int signal(int x)
{
	if(x == 0)
		return 0;
	else if(x > 0)
		return 1;
	else
		return -1;
}

int left(int i)
{
	return i*2;
}

int right(int i)
{
	return (i*2) + 1;
}

void build(std::vector<int> &stree, int node, int l, int r)
{
	int mid;

	if(l == r)
	{
		std::cin >> stree[node];
		stree[node] = signal(stree[node]);
		return;
	}
	else
	{
		mid = (l + r) / 2;
		build(stree, left(node), l, mid);
		build(stree, right(node), mid + 1, r);

		stree[node] = stree[left(node)] * stree[right(node)];
	}
}

void update(std::vector<int> &stree, int node, int l, int r, int index, int val)
{
	int mid;

	if(l == r)
	{
		stree[node] = val;
	}
	else
	{
		mid = (l + r) / 2;
		if(l <= index && index <= mid)
			update(stree, left(node), l, mid, index, val);
		else
			update(stree, right(node), mid + 1, r, index, val);
		
		stree[node] = stree[left(node)] * stree[right(node)];
	}
}

int query(std::vector<int> &stree, int node, int l, int r, int a, int b)
{
	int mid;

	if(a == l && b == r)
		return stree[node];

	mid = (l + r) / 2;
	if(b <= mid)
		return query(stree, left(node), l, mid, a, b);
	else if(a > mid)
		return query(stree, right(node), mid + 1, r, a, b);
	else
		return query(stree, left(node), l, mid, a, mid) * query(stree, right(node), mid + 1, r, mid + 1, b);
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, K, x, y, i;
	string op;

	while(std::cin >> N >> K)
	{
		std::vector<int> stree(4*N);

		build(stree, 1, 1, N);
		for(i = 0; i < K; ++i)
		{
			std::cin >> op >> x >> y;
			if(op.compare("C") == 0)
				update(stree, 1, 1, N, x, signal(y));
			else
			{
				if((query(stree, 1, 1, N, x, y) + 1) == 0)
					std::cout << "-";
				else if((query(stree, 1, 1, N, x, y) + 1) == 1)
					std::cout << "0";
				else
					std::cout << "+";
			}
		}
		std::cout << endl;
	}
	return 0;
}
