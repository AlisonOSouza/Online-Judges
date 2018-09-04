/*
	@problem:	Procurando Assentos - 1365
	@site:		URI Online Judge
	@author:	Alison Souza

	Encontre o menor retângulo dentro do grid(R, C) que possua
	pelo menos K "." (pontos).
*/

#include <iostream>
#include <cmath> // abs()

using namespace std;

#define MAX 305
#define INF MAX*MAX

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	
	int R, C, K, i, j, l, m, area, dots;
	int aux[MAX];
	int grid[MAX][MAX];
	char in;

	// Lê a entrada enquanto R,C,K for maior que 0.
	while(std::cin >> R >> C >> K && R > 0 && C > 0 && K > 0)
	{
		// Lê o grid das cadeiras.
		for(i = 0; i < R; i++)
		{
			for(j = 0; j < C; j++)
			{
				std::cin >> in;
				// Salva 1 se ".", 0 caso contrário.
				grid[i][j] = (in == '.') ? 1 : 0;
			}
		}

		// Define a area inicialmente como infinita
		area = INF;
		for(i = 0; i < R; i++)
		{
			// Zera o vetor aux.
			for(j = 0; j < C; j++)
				aux[j] = 0;

			for(j = i; j < R; j++)
			{
				// Soma no vetor aux a quantidade de "." na coluna "l" 
				// até a linha "j".
				for(l = 0; l < C; l++)
					aux[l] += grid[j][l];

				dots = 0;
				l = 0;
				// Para cada coluna "m", soma a quantidade de pontos
				// encontrados até a linha "j" usando o vetor auxiliar.
				for(m = 0; m < C; m++)
				{
					dots += aux[m];
					// Enquanto o número de "." for maior que "K" + os
					// pontos da coluna "l", então shifta o retângulo
					// para a direita e diminui a quantidade de pontos
					// que o retângulo possui.
					while((l < m) && (dots >= K + aux[l]))
					{
						dots -= aux[l];
						l++;
					}
					// Se a quantidade de "." for maior ou igual a K.
					if(dots >= K)
						// Então vê se a área é menor que a área atual.
						area = min(area, (abs(l-m) + 1) * (abs(i-j) + 1));
				}
			}
		}
		std::cout << area << endl;
	}
	return 0;
}
