/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 14
PROBLEMA:	#3 ELEVADOR - Elevador

SOLUÇÃO PROPOSTA:
Neste problema, leio os valores de entrada e verifico se cada cilindro
sozinho cabe no elevador, se não couber imprimo N e passo para o pŕoximo
caso de teste. Caso caiba, verifico se os dois cilindros cabem juntos
checando se o segmento mínimo que liga os centro das circunferências
(dist_quad) é menor que o segmento máximo que liga os centros das
circunferências (max_dist_quad).
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int l, c, r1, r2, l_rest, c_rest, dist_quad, max_dist_quad;

	std::cin >> l >> c >> r1 >> r2;
	while(l > 0 && c > 0 && r1 > 0 && r2 > 0)
	{
		if(2*r1 > l || 2*r1 > c || 2*r2 > l || 2*r2 > c)
			std::cout << "N" << endl;
		else
		{
			l_rest = l - r1 - r2;
			c_rest = c - r1 - r2;

			dist_quad = (l_rest * l_rest) + (c_rest * c_rest);
			max_dist_quad = (r1 + r2) * (r1 + r2);

			if(dist_quad < max_dist_quad)
				std::cout << "N" << endl;
			else
				std::cout << "S" << endl;
		}

		std::cin >> l >> c >> r1 >> r2;
	}
	return 0;
}