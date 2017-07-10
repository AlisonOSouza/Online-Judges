// Esse código funciona, porém não passa no UVA por erro de precisão.
// Decedi salvar esse código porque a implementação ficou legal. :D

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct ponto
{
	double x;
	double y;	
} ponto_t;

double pitagoras(ponto_t p1, ponto_t p2)
{
	double x, y;
	x = p1.x - p2.x;
	y = p1.y - p2.y;

	return sqrt((x*x) + (y*y));
}

int main()
{
	int n, i;
	double distDOG, distGOPHER;
	ponto_t dog, gopher, hole;

	while(std::cin >> n >> gopher.x >> gopher.y >> dog.x >> dog.y)
	{
		for(i = 0; i < n; i++)
		{
			// Lê os buracos.
			std::cin >> hole.x >> hole.y;

			// Calcula a distância do cão e da marmota até o buraco.
			distDOG = pitagoras(dog, hole);
			distGOPHER = pitagoras(gopher, hole);

			// Se a distância do cão for maior que 2* a distância da 
			// mamota até o buraco, então escapou.
			if(distDOG >= 2*distGOPHER)
			{
				std::cout << fixed << setprecision(3)
						  << "The gopher can escape through the hole at (" 
						  << hole.x << "," << hole.y << ")." << endl;
				return 0;
			}
		}
		std::cout << "The gopher cannot escape." << endl;
	}

	return 0;
}