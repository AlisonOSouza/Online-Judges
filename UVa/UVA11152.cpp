/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 14
PROBLEMA:	#7 UVa 11152 - Colorful Flowers

SOLUÇÃO PROPOSTA:
Neste problema, leio os lados do triângulo (a, b e c) e com eles calculo
o semi-perímetro (s). Com isso, utilizo a fórmula de Heron para a área
do triângulo. Depois, calculo o raio do círculo inscrito no triângulo
(r = A/s) e o raio do círculo circunscrito (abc/4A). Com os raios, calculo
a área de cada circunferência (pi*r²) e calculo a área que cada tipo de
flor irá ocupar.
\*******************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c, pi, s, areaTriang, raioMenor, raioMaior, sunflowers, violets, roses;

	pi = acos(-1);

	while(std::cin >> a >> b >> c)
	{
		s = (a + b + c) / 2.0;
		areaTriang = sqrt(s*(s-a)*(s-b)*(s-c));
		raioMaior = (a*b*c) / (4*areaTriang);
		raioMenor = areaTriang / s;

		sunflowers = (pi*raioMaior*raioMaior) - areaTriang;
		roses = pi*raioMenor*raioMenor;
		violets = areaTriang-roses;

		std::cout << fixed << setprecision(4) << sunflowers << " " << violets << " " << roses << endl;
	}
	return 0;
}