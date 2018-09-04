/*
	@problem:	2048 - 1559
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

int main()
{
	int numCasos;
	int matriz[4][4], i, j;
	bool direita, esquerda, cima, baixo, none;

	std::cin >> numCasos;
	while(numCasos--)
	{
		direita = false;
		esquerda = false;
		cima = false;
		baixo = false;
		none = false;

		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				std::cin >> matriz[i][j];

		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				if(matriz[i][j] == 2048) none = true;

				if(j - 1 >= 0) //Se tem tabuleiro a esquerda.
				{
					if(matriz[i][j-1] == 0 && matriz[i][j] > 0) esquerda = true;
					if(matriz[i][j-1] == matriz[i][j] && matriz[i][j] > 0)
					{
						esquerda = true;
						direita = true;
					}
				}

				if(j + 1 < 4) //Se tem tabuleiro a direita.
				{
					if(matriz[i][j+1] == 0 && matriz[i][j] > 0) direita = true;
					if(matriz[i][j+1] == matriz[i][j] && matriz[i][j] > 0)
					{
						esquerda = true;
						direita = true;
					}
				}

				if(i - 1 >= 0) //Se tem tabuleiro acima.
				{
					if(matriz[i-1][j] == 0 && matriz[i][j] > 0) cima = true;
					if(matriz[i-1][j] == matriz[i][j] && matriz[i][j] > 0)
					{
						cima = true;
						baixo = true;
					}
				}

				if(i + 1 >= 0) //Se tem tabuleiro abaixo.
				{
					if(matriz[i+1][j] == 0 && matriz[i][j] > 0) baixo = true;
					if(matriz[i+1][j] == matriz[i][j] && matriz[i][j] > 0)
					{
						cima = true;
						baixo = true;
					}
				}
			}
		}

		if(baixo && !none) std::cout << "DOWN";
		if(baixo && (cima || esquerda || direita) && !none) std::cout << " ";
		if(esquerda && !none) std::cout << "LEFT";
		if(esquerda && (cima || direita) && !none) std::cout << " ";
		if(direita && !none) std::cout << "RIGHT";
		if(direita && cima && !none) std::cout << " ";
		if(cima && !none) std::cout << "UP";
		if((!cima && !baixo && !esquerda && !direita) || none) std::cout << "NONE";
		std::cout << endl;
	}

	return 0;
}