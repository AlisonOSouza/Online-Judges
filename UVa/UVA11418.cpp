/*
	@problem:	Clever Naming Patterns - 11418
	@site:		UVa Online Judge
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

#define MAX 100

int g[MAX][MAX];
int mx[MAX], my[MAX], gt[MAX], used[MAX];

int dfs(int a)
{
	int i, aux;

	for(i = 0; i < gt[a]; i++)
	{
		aux = g[a][i];
		if(!used[aux])
		{
			used[aux] = 1;
			if(my[aux] == 0 || dfs(my[aux]))
			{
				mx[a] = aux, my[aux] = a;
				return 1;
			}
		}
	}
	return 0;
}


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int testCases, n, i, j, k, cases, aux;
	int K[30];
	char word[30][30][MAX];
	
	cases = 1;

	std::cin >> testCases;
	while(testCases--)
	{
		for (i = 0; i < MAX; i++)
		{
			gt[i] = 0;
			mx[i] = 0;
			my[i] = 0;
		}

		std::cin >> n;
		for(i = 1; i <= n; i++)
		{
			std::cin >> K[i];
			for(j = 0; j < K[i]; j++)
			{
				std::cin >> word[i][j];
				aux = 30+(word[i][j][0] >= 'a' ? word[i][j][0]-'a' : word[i][j][0]-'A');
				g[aux][gt[aux]++] = i;
			}
		}
		for(i = 30; i < 30+n; i++)
		{
			if(!mx[i])
			{
				for(j = 0; j < MAX; j++)
					used[j] = 0;
				dfs(i);
			}
		}
		std::cout << "Case #" << cases++ << ":" << endl;
		for(i = 30; i < 30+n; i++)
		{
			for(j = 0; j < K[mx[i]]; j++)
			{
				if(tolower(word[mx[i]][j][0]) == i-30+'a')
				{
					char c1 = (char) std::toupper(word[mx[i]][j][0]);
					std::cout << c1;
					for(k = 1; word[mx[i]][j][k]; k++)
					{	
						char c2 = (char) std::tolower(word[mx[i]][j][k]);
						std::cout << c2;
					}
					std::cout << endl;
					break;
				}
			}
		}
	}
	return 0;
}
