/*
	@problem:	Potentiometers - 12086
	@site:		UVa Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int left(int i)
{
	return i*2;
}

int right(int i)
{
	return (i*2) + 1;
}

void build(std::vector<int> &stree, std::vector<int> &arr, int node, int l, int r)
{
	int mid;

	if(l == r)
	{
		stree[node] = arr[l];
	}
	else
	{
		mid = (l + r) / 2;
		build(stree, arr, left(node), l, mid);
		build(stree, arr, right(node), mid + 1, r);

		stree[node] = stree[left(node)] + stree[right(node)];
	}
}

void update(std::vector<int> &stree, std::vector<int> &arr, int node, int l, int r, int index, int val)
{
	int mid;

	if(l == r)
	{
		arr[index] = val;
		stree[node] = val;
	}
	else
	{
		mid = (l + r) / 2;
		if(l <= index && index <= mid)
			update(stree, arr, left(node), l, mid, index, val);
		else
			update(stree, arr, right(node), mid + 1, r, index, val);

		stree[node] = stree[left(node)] + stree[right(node)];
	}
}

int measure(std::vector<int> &stree, int node, int l, int r, int a, int b)
{
	int mid, p1, p2;

	if(b < l || r < a)
		return 0;
	if(a <= l && r <= b)
		return stree[node];
	
	mid = (l + r) / 2;
	p1 = measure(stree, left(node), l, mid, a, b);
	p2 = measure(stree, right(node), mid + 1, r, a, b);

	return p1 + p2;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	int n, a, b, i, testCase = 1;
	string op;
	
	while(std::cin >> n && n > 0)
	{
		if(testCase != 1)
			std::cout << endl;

		std::vector<int> arr(n);
		std::vector<int> stree(4*n);

		for(i = 0; i < n; i++)
			std::cin >> arr[i];

		build(stree, arr, 1, 0, n - 1);
		
		std::cout << "Case " << testCase++ << ":" << endl;
		
		while(std::cin >> op && op.compare("END") != 0)
		{
			std::cin >> a >> b;
			if(op.compare("M") == 0) 
				std::cout << measure(stree, 1, 0, n - 1, --a, --b) << endl;
			else if(op.compare("S") == 0)
				update(stree, arr, 1, 0, n - 1, --a, b);
		}
	}
	return 0;
}
