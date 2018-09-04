/*
	@problem:   Ball Stacking - 12357
	@site:      UVa Online Judge
	@author:    Alison Souza

	Programação Dinâmica (quase um Fibonacci)
*/

#include <iostream>

using namespace std;

#define MAX_N 1005

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, i, j, res;
	int stack[MAX_N][MAX_N], maxStack[MAX_N][MAX_N];

	while(std::cin >> N && N > 0)
	{
		res = 0;
		for(i = 1; i <= N; i++)
		{
			for(j = 1; j <= i; j++)
			{
				std::cin >> stack[i][j];
				stack[i][j] += stack[i - 1][j];
			}
		}
		maxStack[N][1] = stack[N][1];
		res = max(res, stack[N][1]);
		for(i = N - 1; i >= 1; i--)
		{
			res = max(stack[i][1], res);
			maxStack[i][1] = max(maxStack[i + 1][1], stack[i][1]);
		}
		for(j = 2; j <= N; j++)
		{
			for(i = j; i <= N; i++)
			{
				stack[i][j] = maxStack[i-1][j-1] + stack[i][j];
				res = max(res, stack[i][j]);
			}
			maxStack[N][j] = stack[N][j];
			for(i = N - 1; i >= j; i--)
				maxStack[i][j] = max(maxStack[i+1][j], stack[i][j]);
		}
		std::cout << res << endl;
	}
	return 0;
}
