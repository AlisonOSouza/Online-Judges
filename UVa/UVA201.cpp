/*
	@problem:	Squares - 201
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, m, flag, x, y, i, j, k, find;
	char c;
	
	flag = 0;
	while(std::cin >> n >> m)
	{
		int H[10][10], V[10][10], res[10];
		for(i = 0; i < 10; i++)
		{
			res[i] = 0;
			for(j = 0; j < 10; j++)
			{
				H[i][j] = 0;
				V[i][j] = 0;
			}
		}

		while(m--)
		{
			std::cin >> c >> x >> y;
			if(c == 'H')
				H[x][y] = 1;
			else
				V[y][x] = 1;
		}
		for(i = n; i >= 0; i--)
		{	
			for(j = n; j >= 0; j--)
			{
				if(H[i][j])
					H[i][j] = H[i][j+1] + 1;
				if(V[i][j])
					V[i][j] = V[i+1][j] + 1;
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(H[i][j] < V[i][j])
				{
					for(k = H[i][j]; k >= 1; k--)
					{
						if(H[i+k][j] >= k && V[i][j+k] >= k)
							res[k]++;
					}
				}
				else
				{
					for(k = V[i][j]; k >= 1; k--)
					{
						if(H[i+k][j] >= k && V[i][j+k] >= k)
							res[k]++;
					}
				}
			}
		}

		if(flag)
			std::cout << endl << "**********************************" << endl << endl;
		flag++;
		std::cout << "Problem #" << flag << endl << endl;

		find = 0;
		for(i = 1; i < n; i++)
		{
			if(res[i])
			{
				std::cout << res[i] << " square (s) of size " << i << endl;
				find = 1;
			}
		}
		if(!find)
			std::cout << "No completed squares can be found." << endl;
	}
	return 0;
}