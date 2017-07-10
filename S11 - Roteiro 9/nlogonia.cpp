/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 9
PROBLEMA:	#1 NLOGONIA - Divisão da Nlogônia

SOLUÇÃO PROPOSTA:
Neste problema, leio o número 'k' de consultas a ser realizadas e leio as 
coordenadas do ponto divisor em seguida. Após isso, para cada uma das 
consultas leio as coordenadas, e chamo a função qualPais() que recebe o
ponto divisor e o ponto de consulta como parâmetros. Essa função verifica
inicialmente se o ponto de consulta está em uma divisa. Caso não esteja, 
a função verifica se a coordenada X e Y do ponto de consulta é maior ou
menor que do ponto de divisa, como se estivesse analisando um plano
cartesiano. Após verificar em qual 'quadrante' do País o ponto de consulta
se encontra, é impresso a saída correspondente.
\*******************************************************************/

#include <iostream>

using namespace std;

typedef struct ponto
{
	int x;
	int y;	
} ponto_t;

void qualPais(ponto_t divisor, ponto_t consulta)
{
	if(consulta.x == divisor.x || consulta.y == divisor.y)
	{
		std::cout << "divisa" << endl;
		return;
	}
	if(consulta.x < divisor.x && consulta.y < divisor.y)
	{
		std::cout << "SO" << endl;
		return;
	}
	if(consulta.x < divisor.x && consulta.y > divisor.y)
	{
		std::cout << "NO" << endl;
		return;
	}
	if(consulta.x > divisor.x && consulta.y < divisor.y)
	{
		std::cout << "SE" << endl;
		return;
	}
	if(consulta.x > divisor.x && consulta.y > divisor.y)
	{
		std::cout << "NE" << endl;
		return;
	}
}

int main()
{
	int k, i;
	ponto_t divisor, consulta;

	std::cin >> k;
	while(k > 0)
	{
		std::cin >> divisor.x >> divisor.y;

		for(i = 0; i < k; i++)
		{
			std::cin >> consulta.x >> consulta.y;
			qualPais(divisor, consulta);
		}

		std::cin >> k;
	}
	return 0;
}