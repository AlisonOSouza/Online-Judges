/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 9
PROBLEMA:	#3 METEORO - Meteoro

SOLUÇÃO PROPOSTA:
Neste problema, leio as coordenadas da fazenda e o número de meteoritos
que caíram do céu. Em seguida, leio as coordenadas de cada meteorito e
verifico se essas coordenadas estão dentro dos limites do retângulo que
delimita a fazenda. Caso esteja, incremento a variável 'num_meteoritos'
que armazena o número de meteoritos que caíram dentro da fazenda. Ao
final, imprimo o valor da variável 'num_meteoritos'.
\*******************************************************************/

#include <iostream>

using namespace std;

typedef struct ponto
{
	int x;
	int y;	
} ponto_t;

int main()
{
	int n, num_meteoritos, i;
	ponto_t p1, p2, m;

	i = 1;
	std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
	while(p1.x != 0 || p1.y != 0 || p2.x != 0 || p2.y != 0)
	{
		num_meteoritos = 0;
		std::cin >> n;
		while(n--)
		{
			std::cin >> m.x >> m.y;

			if(m.x >= p1.x && m.x <= p2.x && m.y >= p2.y && m.y <= p1.y)
				num_meteoritos++;
		}

		std::cout << "Teste " << i << endl << num_meteoritos << endl;
		std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
		if(p1.x != 0 || p1.y != 0 || p2.x != 0 || p2.y != 0)
			std::cout << endl;
		i++;
	}

	return 0;
}