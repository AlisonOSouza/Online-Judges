/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#1 POODLEMG - Poodle

SOLUÇÃO PROPOSTA:
Neste problema, leio a quantidade de documentos encontrados (N) e o número
de resultados exibidos por página (P). Para calcular a quantidade de O's
no logotipo, faço a divisão de N por P e se houver resto, incremento
o número de O's. Após isso, subtraio 4 para remover as letras P D L E.
Para imprimir a saída, verifico se o número de O's é maior que 2 e
menor que 16 (limite de 20 caracteres na logo) e imprimo a quantidade
correspondente. Se for maior que 16, imprimo 16 O's (mais as 4 letras 
P D L E). Se não cair em nenhum desses casos, então o número de O's é
menor que 2 e então imprimo "Poodle".
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int n, p, num_o;

	std::cin >> n >> p;
	while(n > 0 && p > 0)
	{
		num_o = n / p;
		if(n % p > 0) num_o++;

		num_o -= 4; // Retira as letras P, d, l, e.

		if(num_o > 2 && num_o < 16)
		{
			std::cout << "P";	
			while(num_o--)
			{
				std::cout << "o";
			}
			std::cout << "dle" << endl;
		}
		else if(num_o >= 16)
		{
			std::cout << "Poooooooooooooooodle" << endl;
		}
		else
		{
			std::cout << "Poodle" << endl;
		}

		std::cin >> n >> p;
	}

	return 0;
}