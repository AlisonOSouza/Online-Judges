/*
	@problem:	Intersection - 1410
	@site:		PKU Online Judge
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

typedef struct Point
{
	int x, y;
} t_Point;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, delta_y, delta_x, aux;
	t_Point l_start, l_end, r_LT, r_RB;

	std::cin >> N;
	while(N--)
	{
		std::cin >> l_start.x >> l_start.y
				 >> l_end.x >> l_end.y
				 >> r_LT.x >> r_LT.y
				 >> r_RB.x >> r_RB.y;

		// Garantindo que os valores de LT e RB estao corretos. Ou seja, se
		// o maior valor de X esta em RB e o maior valor de Y em LT.
		if(r_LT.x > r_RB.x) swap(r_LT.x, r_RB.x);
		if(r_LT.y < r_RB.y) swap(r_LT.y, r_RB.y);

		// Se a reta esta fora dos limites do retangulo, ja imprime F.
		if((l_start.x < r_LT.x && l_end.x < r_LT.x) ||
			(l_start.x > r_RB.x && l_end.x > r_RB.x) ||
			(l_start.y < r_RB.y && l_end.y < r_RB.y) ||
			(l_start.y > r_LT.y && l_end.y > r_LT.y))
		{
			std::cout << "F" << endl;
			continue;
		}

		// Tratando o caso onde a reta tem X constante (reta vertical).
		if(l_start.x == l_end.x)
		{
			if(!(r_LT.x <= l_start.x && l_start.x <= r_RB.x &&
				!((l_start.y > r_LT.y && l_end.y > r_LT.y) || (l_start.y < r_RB.y && l_end.y < r_RB.y))))
			{
				std::cout << "F" << endl;
				continue;
			}
		}

		// Tratando o caso onde a reta tem y constante (reta horizontal).
		else if(l_start.y == l_end.y)
		{
			if(!(r_RB.y <= l_start.y && l_start.y <= r_LT.y &&
				!((l_start.x > r_RB.x && l_end.x > r_RB.x) || (l_start.x < r_LT.x && l_end.x < r_LT.x))))
			{
				std::cout << "F" << endl;
				continue;
			}
		}

		// Tratando outros casos (retas diagonais).
		delta_y = l_end.y - l_start.y;
		delta_x = l_start.x - l_end.x;
		aux = l_start.x * l_end.y - l_end.x * l_start.y;
		if(((delta_y * r_LT.x + delta_x * r_LT.y) > aux && (delta_y * r_LT.x + delta_x * r_RB.y) > aux &&
			(delta_y * r_RB.x + delta_x * r_LT.y) > aux && (delta_y * r_RB.x + delta_x * r_RB.y) > aux) ||
			((delta_y * r_LT.x + delta_x * r_LT.y) < aux && (delta_y * r_LT.x + delta_x * r_RB.y) < aux &&
			(delta_y * r_RB.x + delta_x * r_LT.y) < aux && (delta_y * r_RB.x + delta_x * r_RB.y) < aux))
		{
			std::cout << "F" << endl;
			continue;
		}

		std::cout << "T" << endl;
	}
	return 0;
}
