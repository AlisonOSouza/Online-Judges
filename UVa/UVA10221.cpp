/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 14
PROBLEMA:	#6 UVa 10221 - Satellites

SOLUÇÃO PROPOSTA:
Neste problema, verifico se a unidade do ângulo passado como entrada
está em minutos. Se estiver, divido esse valor por 60 para transformar
em graus. Após isso, verifico se o angulo passado como parâmetro é maior
que 180°, se for subtraio de 360 o valor passado como parâmetro. Depois,
somo a distância do satélite até a superfície da terra com 6440 para
obter o raio da órbita dos dois satélites. Com isso, calculo o arco
da circunferência com a fórmula (raio*angulo)/(180*PI), e calculo o
comprimento de corda como a hipotenusa de um triângulo isósceles.
\*******************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	double s, a, pi, arc, chord;
	string ang;
	
	pi = acos(-1);
	
	while(std::cin >> s >> a >> ang)
	{
		if(ang.compare("min") == 0)
			a /= 60;
		
		if(a > 180)
			a = 360-a;
		
		s += 6440;

		arc = s*a/180*pi;
		chord = 2*sqrt(s*s-pow(s*cos(a/360*pi), 2));
		
		std::cout << fixed << setprecision(6) << arc << " " << chord << endl;
	}
	return 0;
}