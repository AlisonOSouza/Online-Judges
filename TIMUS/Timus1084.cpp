/*
	@problem:	Goat in the Garden - 1084
	@site:		Timus Online Judge
	@author:	Alison Souza

	Para este problema, basta calcularmos a área do circulo que está 
	circunscrito no quadrado.
	- Se o quadrado esta contido no circulo, entao a resposta e' a area do
	quadrado.
	- Se o circulo esta contido no quadrado, entao a resposta e' a area do
	circulo.
	- Se a borda do circulo cruza com a borda do quadrado, entao calculamos
	a area do circulo menos as 4 areas de segmento do circulo que estao
	para fora do quadrado. Ou seja:
		area_total = area_circulo - (4 * area_segmento)
*/

// Usado para acessar M_PI.
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip> // setprecision()

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int lado, raio;
	double diagonal, diametro, area, ang, seg_area;

	std::cin >> lado >> raio;

	diagonal = sqrt(lado*lado + lado*lado);
	diametro = 2.0*raio;

	// Se a diagonal do quadrado for menor ou igual a duas vezes o raio
	// (diametro), então o quadrado esta' totalmente contido no circulo.
	if(diagonal <= diametro)
		area = lado*lado;
	
	// Se o diametro for menor ou igual ao lado, entao o circulo esta
	// totalmente contido no quadrado.
	else if(diametro <= lado)
		area = M_PI*raio*raio;
	
	// Se não caiu em nenhuma das condicoes anteriores, entao o circulo
	// cobre parte do quadrado, mas tambem cobre pedacos fora do quadrado.
	else
	{
		ang = sqrt(4.*raio*raio - lado*lado) * lado/(2.*raio*raio);
		seg_area = asin(ang) / (2.*M_PI) * M_PI*raio*raio - sqrt(4.*raio*raio - lado*lado)*lado/4.;
		area = M_PI*raio*raio -  4.*seg_area;
	}

	std::cout << fixed << setprecision(3) << area << endl;
	return 0;
}
