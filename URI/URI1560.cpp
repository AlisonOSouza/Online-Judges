/*
	@problem:   Energia dos Triangulos - 1560
	@site:      URI Online Judge
	@author:    Alison Souza
*/

#include <iostream>
#include <vector>
#include <cmath> // std::abs()

using namespace std;

typedef struct Ponto
{
	int x, y;
} t_Ponto;

double triangleArea(t_Ponto a, t_Ponto b, t_Ponto c)
{
	// Fonte: https://www.mathopenref.com/coordtrianglearea.html
	return std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y))/2.0;
}

bool isInside(t_Ponto P, t_Ponto a, t_Ponto b, t_Ponto c)
{
	// Um ponto P estará dentro de um triangulo ABC se a area total de
	// ABC for igual a soma das areas dos triangulos PBC, APC e ABP.
	double A, a1, a2, a3;
	A = triangleArea(a, b, c);
	a1 = triangleArea(P, b, c);
	a2 = triangleArea(a, P, c);
	a3 = triangleArea(a, b, P);

	return (A == a1 + a2 + a3);
}


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, M, i, j, k, l;
	int saida, aux;
	t_Ponto pnt;
	std::vector<t_Ponto> blacks;
	std::vector<t_Ponto> whites;

	while(std::cin >> N >> M)
	{
		blacks.clear();
		whites.clear();

		for(i = 0; i < N; i++)
		{
			std::cin >> pnt.x >> pnt.y;
			blacks.push_back(pnt);
		}

		for(i = 0; i < M; i++)
		{
			std::cin >> pnt.x >> pnt.y;
			whites.push_back(pnt);
		}
		
		saida = 0;
		
		// Percorro a lista de pontos pretos, selecionando 3 pontos diferentes.
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < i; j++)
			{
				for(k = 0; k < j; k++)
				{
					aux = 0;
					// Percorro a lista de pontos brancos
					for(l = 0; l < M; l++)
						// Se o ponto branco esta dentro do triangulo formado
						// pelos pontos pretos.
						if(isInside(whites[l], blacks[i], blacks[j], blacks[k]))
							// Incrementa o contador de pontos.
							aux ++;
					
					saida += aux * aux;
				}
			}
		}
		std::cout << saida << endl;
	}
	return 0;
}