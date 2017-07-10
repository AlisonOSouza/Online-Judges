#include <iostream>
#include <vector>

using namespace std;

typedef struct matriz
{
	int valor;
	bool visitado;
} matriz_t;

bool isVisited(matriz_t a)
{
	return a.visitado;
}

bool isWay(matriz_t a)
{
	return (a.valor == 0);
}

bool prendeu;

bool dfs(matriz_t mat[5][5], int i, int j)
{
	if(i >= 0 && i < 5 && j >=0 && j < 5 && !prendeu)
	{
		mat[i][j].visitado = true;
		if(i == 4 && j == 4)
		{
			prendeu = true;
		}
		else
		{
			if((i + 1) < 5 && isWay(mat[i+1][j]) && !isVisited(mat[i+1][j]))
				dfs(mat, i + 1, j);

			if((i - 1) >= 0 && isWay(mat[i-1][j]) && !isVisited(mat[i-1][j]))
				dfs(mat, i - 1, j);
			
			if((j + 1) < 5 && isWay(mat[i][j+1]) && !isVisited(mat[i][j+1]))
				dfs(mat, i, j + 1);

			if((j - 1) >= 0 && isWay(mat[i][j-1]) && !isVisited(mat[i][j-1]))
				dfs(mat, i, j - 1);
		}
	}
	return prendeu;
}

int main()
{
	int i, j, t;
	bool res;
	//std::vector< vector<matriz_t> > matriz(5);
	matriz_t matriz[5][5];

	std::cin >> t;

	while(t > 0)
	{
		// Preenchendo a matriz.
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 5; j++)
			{
				std::cin >> matriz[i][j].valor;
				matriz[i][j].visitado = false;
			}
		}

		// Buscando um caminho.
		prendeu = false;
		res = dfs(matriz, 0, 0);
		if(res) std::cout << "COPS" << endl;
		else std::cout << "ROBBERS" << endl;
		t--;
	}

	return 0;
}