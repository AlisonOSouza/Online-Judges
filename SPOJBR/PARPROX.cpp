/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 9
PROBLEMA:	#2 PARPROX - Pontos

SOLUÇÃO PROPOSTA:
Neste problema, leio os pontos de entrada e armazeno os dados em um vetor.
Após isso, inicializo uma variável 'distMin', que armazenará a distância 
mínima entre dois pontos, como infinito (definido como 0x3f3f3f3f). Após
isso, percorro o vetor de pontos calculando as distâncias entre cada par
de pontos. Se a distância calculada for menor que a distMin, então atualizo
o valor de distMin como a distância recém calculada. Ao final do loop,
se o valor de distMin for menor que infinito, então imprimo distMin.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

#define INF 0x3f3f3f3f

typedef struct ponto
{
	int x;
	int y;	
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
	int n, i, j;
	double distMin, distAtual;
	ponto_t p;
	std::vector<ponto_t> vp;

	std::cin >> n;
	while(n--)
	{
		std::cin >> p.x >> p.y;
		vp.push_back(p);
	}

	distMin = INF;
	for(i = 0; i < vp.size() - 1; i++)
	{
		for(j = i+1; j < vp.size(); j++)
		{
			distAtual = pitagoras(vp[i], vp[j]);
			if(distAtual < distMin) distMin = distAtual;
		}
	}

	if(distMin < INF) std::cout << fixed << setprecision(3) << distMin << endl;
	else std::cout << "0" << endl;

	return 0;
}