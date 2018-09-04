/*
	@problem:   Ahoy, Pirates - 11402
	@site:      UVa Online Judge
	@author:    Alison Souza
*/

#include <iostream>

using namespace std;

struct treeType
{
	int v, l, r, op;
} tree[2100000];

string pirates;

int left(int i)
{
	return i*2;
}

int right(int i)
{
	return (i*2) + 1;
}

void build(int node, int l, int r)
{
	int mid;

	tree[node].l = l;
	tree[node].r = r;
	tree[node].v = 0;
	if(l == r)
	{
		tree[node].v = pirates[l] - '0';
		tree[node].op = 0;
	}
	if(l < r)
	{
		mid = (l + r) / 2;
		build(left(node), l, mid);
		build(right(node), mid + 1, r);
		tree[node].op = 0;
		tree[node].v = tree[left(node)].v + tree[right(node)].v;
	}
}

void single(int node)
{
	if(tree[node].op)
	{
		if(tree[node].op == 1)
			tree[node].v = tree[node].r - tree[node].l + 1;
		else if(tree[node].op == 2)
			tree[node].v = 0;
		else
			tree[node].v = tree[node].r - tree[node].l + 1 - tree[node].v;
		
		if(tree[node].l < tree[node].r)
		{
			if(tree[node].op == 3)
			{
				tree[left(node)].op = 3 - tree[left(node)].op;
				tree[right(node)].op = 3 - tree[right(node)].op;
			}
			else
			{
				tree[left(node)].op = tree[node].op;
				tree[right(node)].op = tree[node].op;
			}
		}

		tree[node].op = 0;
	}
}

void update(int node, int l, int r, int op)
{
	int mid; 

	if(l == tree[node].l && r == tree[node].r)
	{
		if(op == 3)
			tree[node].op = 3-tree[node].op;
		else
			tree[node].op = op;
	}

	single(node);
	
	if(l == tree[node].l && r == tree[node].r)
		return;
	
	mid = (tree[node].l + tree[node].r) / 2;
	
	if(r <= mid)
		update(left(node), l, r, op);
	else if(l > mid)
		update(right(node), l, r, op);
	else
	{
		update(left(node), l, mid, op);
		update(right(node), mid + 1, r, op);
	}
	
	single(left(node));
	single(right(node));
	tree[node].v = tree[left(node)].v + tree[right(node)].v;
}

int count(int node, int l, int r)
{
	int mid;

	single(node);
	
	if(l == tree[node].l && r == tree[node].r)
		return tree[node].v;
	
	mid = (tree[node].l + tree[node].r) / 2;
	
	if(r <= mid)
		return count(left(node), l, r);
	else if(l > mid)
		return count(right(node), l, r);
	else
		return count(left(node), l, mid) + count(right(node), mid + 1, r);
	
	single(left(node)), single(right(node));
	tree[node].v = tree[left(node)].v + tree[right(node)].v;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int testCases, M, N, Q, T, i, a, b, QCase;
	string op, str;
	
	std::cin >> testCases;
	for(i = 1; i <= testCases; i++)
	{
		std::cin >> M;
		pirates.clear();
		while(M--)
		{
			std::cin >> T >> str;
			while(T--)
				pirates += str;
		}
		N = pirates.size();
		build(1, 0, N-1);
		std::cin >> Q;
		std::cout << "Case " << i << ":" << endl;
		QCase = 1;
		while(Q--)
		{
			std::cin >> op >> a >> b;
			if(op.compare("F") == 0)
				update(1, a, b, 1);
			else if(op.compare("E") == 0)
				update(1, a, b, 2);
			else if(op.compare("I") == 0)
				update(1, a, b, 3);
			else
				std::cout << "Q" << QCase++ << ": " << count(1, a, b) << endl;
		}
	}
	return 0;
}
