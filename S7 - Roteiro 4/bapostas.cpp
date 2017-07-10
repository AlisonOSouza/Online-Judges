/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 4
PROBLEMA:	#6 BAPOSTAS - O Bolo de Apostas

SOLUÇÃO PROPOSTA:
Neste problema, leio a quantidade de números da sequência e em seguida
leio cada elemento da sequência e somo ela numa variável 'soma'. Se essa
variável ficar negativa, atribuo nela o valor 0 (já que a soma da maior
sequência nunca 'começaria' com uma soma negativa). Se a soma atual, for
maior que a soma máxima vista até agora (somaMax), atribuo 'soma' a
'somaMax'. No final das iterações imprimo a mensagem correspondente ao
valor final de 'somaMax'.
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int n, soma, somaMax, i, aux;

	std::cin >> n;

	while(n > 0)
	{
		soma = 0;
		somaMax = 0;
		for(i = 0; i < n; i++)
		{
			std::cin >> aux;

			soma += aux;
			if(soma < 0) soma = 0;
			if(soma > somaMax) somaMax = soma;
		}

		if(somaMax == 0) std::cout << "Losing streak." << endl;
		else std::cout << "The maximum winning streak is " << somaMax << "." << endl;

		std::cin >> n;
	}

	return 0;
}