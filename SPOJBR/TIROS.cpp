/*
	@problem:	Atirador de Elite - TIROS
	@site:		SPOJBR
	@author:	Alison Souza

	Para este problema basta verificarmos qual o maior número de balões 
	(pontos) colineares, ou seja, que estao numa mesma linha.
	Para isso, vamos usar a ideia do triangulo de area = 0, que significa
	que os tres pontos sao colineares.
	Mesma ideia utilizada no problema Rabbit Hunt (1052) do Timus OJ.
*/

#include <iostream>
#include <vector>
#include <cmath> // std::abs()

using namespace std;

typedef struct Point
{
	int x, y;
} t_Point;

int triangleArea(t_Point a, t_Point b, t_Point c)
{
	// Fonte: https://www.mathopenref.com/coordtrianglearea.html
	return std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int T, N, i, j, k, max_balloons, aux;
	t_Point coord;
	std::vector<t_Point> baloons;

	std::cin >> T;
	while(T--)
	{
		baloons.clear();
		
		std::cin >> N;
		
		// Trata o caso de existir 1 ou 2 balões.
		if(N <= 2)
			std::cout << N << endl;
		// Trata o caso de 3 ou mais balões.
		else
		{
			for(i = 0; i < N; i++)
			{
				std::cin >> coord.x >> coord.y;
				baloons.push_back(coord);
			}

			max_balloons = -1;
			for(i = 0; i < N; i++)
			{
				for(j = i+1; j < N; j++)
				{
					// Sempre há dois baloes em linha.
					aux = 2;
					for(k = j+1; k < N; k++)
					{
						if(triangleArea(baloons[i], baloons[j], baloons[k]) == 0)
							aux++;
					}
					if(aux > max_balloons)
						max_balloons = aux;
				}
			}
			std::cout << max_balloons << endl;
		}
	}
	return 0;
}
