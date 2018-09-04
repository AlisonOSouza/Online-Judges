/*
	@problem:	Rabbit Hunt - 1052
	@site:		Timus Online Judge
	@author:	Alison Souza

	Para este problema basta verificarmos qual o maior número de coelhos 
	(pontos) colineares, ou seja, que estao numa mesma linha.
	Para isso, vamos usar a ideia do triangulo de area = 0, que significa
	que os tres pontos sao colineares.
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

	int N, i, j, k, aux, max_rabbits;
	t_Point pnt;
	std::vector<t_Point> rabbits;

	std::cin >> N;
	for(i = 0; i < N; i++) 
	{
		std::cin >> pnt.x >> pnt.y;
		rabbits.push_back(pnt);
	}
	max_rabbits = -1;

	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			// Sempre há uma linha entre dois pontos.
			aux = 2;
			for(k = j + 1; k < N; k++)
			{
				if(triangleArea(rabbits[i], rabbits[j], rabbits[k]) == 0)
					aux++;
			}
			if(aux > max_rabbits)
				max_rabbits = aux;
		}
	}

	std::cout << max_rabbits << endl;
	return 0;
}
