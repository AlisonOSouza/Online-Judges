/*
	@problem:	Flores de Fogo - 1039
	@site:		URI Online Judge
	@author:	Alison Souza

	Para este problema, basta calcular o ponto do circulo da flor mais
	distante do centro do circulo do cacador e verificar se este ponto
	esta' dentro do circulo do cacador ou nao.
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef struct Circle
{
	double r, x, y;
} t_Circle;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	t_Circle cacador, flor;
	double dist;

	while(std::cin >> cacador.r >> cacador.x >> cacador.y
					>> flor.r >> flor.x >> flor.y)
	{
		// Calcula a distancia entre os centros dos dois circulos.
		dist = sqrt(((cacador.x - flor.x) * (cacador.x - flor.x)) + 
					((cacador.y - flor.y) * (cacador.y - flor.y)));

		// Se o raio do circulo desenhado pelo cacador for maior ou igual
		// que a soma do circulo da flor com a distancia entre os centros
		// (ponto mais distante do circulo da flor do centro do circulo
		// do cacador), então o cacador ficou rico.
		if(cacador.r >= flor.r + dist)
			std::cout << "RICO" << endl;
		else
			std::cout << "MORTO" << endl;
	}

	return 0;
}
