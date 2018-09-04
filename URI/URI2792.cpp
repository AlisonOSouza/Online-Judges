/*
	@problem:	Golnaldinho - 2792
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

#define MAX 500005

using namespace std;

int modPow2(int n)
{
	return n & (-n);
}

void update(std::vector<int> &tree, int node, int v)
{
	while(node < MAX)
	{
		tree[node] += v;
		node += modPow2(node);
	}
}

int query(std::vector<int> &tree, int node)
{
	int sum = 0;

	while(node > 0)
	{
		sum += tree[node];
		node -= modPow2(node);
	}
	return sum;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, input, i;
	
	std::cin >> N;

	std::vector<int> tree(MAX, 0);
	
	for(i = 1; i <= N; i++)
	{
		std::cin >> input;
		std::cout << (input - query(tree, input));
		
		if(i == N)
			std::cout << endl;
		else
			std::cout << " ";
		
		update(tree, input, 1);
	}
	return 0;
}
