/*
	@problem:	Problema dos Pares Mais Próximos - 1295
	@site:		URI Online Judge
	@author:	Alison Souza

	Para resolver este problema, ordenamos os pontos lidos da entrada (em
	Y primeiro) e depois calculamos as distâncias entre pontos enquanto
	ainda achamos uma distância menor que a atual. Quando a distancia 
	minima encontrada ate agora for menor a distancia calculada nesta 
	iteracao, então todas as proximas tambem serao maiores, porque os 
	pontos estao ordenados. Assim, fazemos uma especie de poda na forca
	bruta, para evitar gerar todas as combinacoes.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct Point
{
	double x, y;
} t_Point;

double distancePitagoras(t_Point a, t_Point b)
{
	return (sqrt( ((a.x-b.x) * (a.x-b.x)) + ((a.y-b.y) * (a.y-b.y)) ) );
}

// Necessario para usar o metodo sort() de algorithm.
bool operator <(const t_Point a, const t_Point b)
{
	if(a.y == b.y)
	{
		if(a.x < b.x)
			return true;
		else
			return false;
	}
	else if(a.y < b.y)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, i, j;
	double distMin, dist, aux;
	t_Point pnt;
	std::vector<t_Point> pontos;

	while(std::cin >> n && n)
	{
		pontos.clear();

		for(i = 0; i < n; i++)
		{
			std::cin >> pnt.x >> pnt.y;
			pontos.push_back(pnt);
		}
		if(n <= 1)
			std::cout << "INFINITY" << endl;
		else
		{
			std::sort(pontos.begin(), pontos.end());
			distMin = 10001;

			for(i = 0; i < n-1; i++)
			{
				dist = distancePitagoras(pontos[i], pontos[i+1]);
				for(j = i + 2; j < n; j++)
				{
					aux = distancePitagoras(pontos[i], pontos[j]);
					if(dist > aux)
						dist = aux;
					else
						break;
				}
				if(distMin > dist)
					distMin = dist;
			}

			if(distMin < 10000)
				std::cout << std::fixed << std::setprecision(4) << distMin << endl;
			else
				std::cout << "INFINITY" << endl;
		}
	}
	return 0;
}