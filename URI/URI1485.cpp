/*
	@problem:	Roleta Turca - 1485
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

std::vector<int> spaces;
std::vector<int> balls;

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int solve(int S, int B)
{
	int i, j, aux;
	std::vector< vector<int> > pd(S, vector<int>(S));
	
	for(j = 0; j < S; j++)
	{
		if(j == 0)
			pd[0][j] = INF;
		else
			pd[0][j] = balls[0]*spaces[j-1] + balls[0]*spaces[j];
	}

	for(i = 1; i < B; i++)
	{
		aux = INF;
		for(j = 0; j < S; j++)
		{
			if(j <= 2)
				pd[i][j] = INF;
			else
			{
				aux = min(aux, pd[i-1][j-2]);

				if(aux == INF)
					pd[i][j] = INF;
				else
					pd[i][j] = aux + (balls[i]*spaces[j-1] + balls[i]*spaces[j]);
			}
		}
	}
	return pd[B-1][S-1];
}

void rotateVector(int S)
{
	int aux, aux2, i;
	
	aux2 = spaces[0];
	for(i = 1; i < S; i++)
	{
		aux = spaces[i];
		spaces[i] = aux2;
		aux2 = aux;
	}
	spaces[0] = aux2;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int S, B, i, sol, res;

	while(std::cin >> S >> B && S > 0 && B > 0)
	{
		spaces.clear();
		spaces.resize(S);
		balls.clear();
		balls.resize(B);

		i = 0;
		for(i = 0; i < S; i++)
			std::cin >> spaces[i];
		
		for(i = 0; i < B; i++)
			std::cin >> balls[i];

		res  =  INF;
		for(i = 0; i < S; i++)
		{
			sol = solve(S, B);
			res = min(sol, res);
			rotateVector(S);
		}
		std::cout << -res << endl;
	}
	return 0;
}
