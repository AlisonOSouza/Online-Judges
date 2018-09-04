/*
	@problem:	Ubiquitous Religions - 10583
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

int parent[50000], ranking[50000];

int findParent(int x){
	if(parent[x] != x)
		parent[x] = findParent(parent[x]);
	return parent[x];
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, m, x, y, i, testCase, parentX, parentY, res;

	testCase = 1;
	while(std::cin >> n >> m && m > 0 && n > 0)
	{
		// Inicializa os vetores.
		for(i = 0; i < n; i++)
		{
			parent[i] = i;
			ranking[i] = 0;
		}

		res = n;
		for(i = 0; i < m; i++)
		{
			std::cin >> x >> y;
			parentX = findParent(x);
			parentY = findParent(y);
			
			if(parentX != parentY)
			{
				res--;
				if(ranking[parentX] > ranking[parentY])
					parent[parentY] = parentX;
				else
				{
					parent[parentX] = parentY;
					if(ranking[parentX] == ranking[parentY])
						ranking[parentY]++;
				}
			}
		}
		std::cout << "Case " << testCase << ": " << res << endl;
		testCase++;
	}
	return 0;
}