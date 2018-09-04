/*
	@problem:	Matrix Game - MATGAME
	@site:		SPOJ
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	
	int testCase, n, m, aux, ans, i, j;
	
	std::cin >> testCase;
	while(testCase--)
	{
		std::cin >> n >> m;

		std::vector< std::vector<int> > Matrix(n, std::vector<int>(m));

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				std::cin >> Matrix[i][j];
		
		ans = 0;
		for(i = 0; i < n; i++)
		{
			aux = Matrix[i][m-1];
			for(j = m-2; j >= 0; j--)
			{
				if(Matrix[i][j] > aux)
					aux = Matrix[i][j];
				else
					aux = Matrix[i][j]-1;
			}
			ans ^= aux;
		}
		if(ans != 0)
			std::cout << "FIRST" << endl;
		else
			std::cout << "SECOND" << endl;
	}
	return 0;
} 
