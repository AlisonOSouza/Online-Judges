/*
	@problem:	Booklet Printing - 637
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, n_folhas, pag_init, pag_final, i;

	while(std::cin >> n && n > 0)
	{
		// Imprimo a frase inicial.
		std::cout << "Printing order for " << n << " pages:" << endl;

		// Verifico se e' apenas uma pagina a imprimir. Esse caso deve
		// estar separado porque nao precisa imprimir o verso.
		if(n == 1)
		{
			std::cout << "Sheet 1, front: Blank, 1" << endl;
		}
		else
		{
			// Divido o numero de paginas da entrada pra descobrir quantas folhas preciso.
			if(n % 4 != 0)
				n_folhas = n / 4 + 1;
			else
				n_folhas = n / 4;
			// Defino qual é a ultima pagina a imprimir (n + Blank's).
			pag_final = n_folhas * 4;
			// Inicializo a variavel com o valor da primeira pagina a imprimir.
			pag_init = 1;

			// Enquanto não imprimiu todas as folhas.
			for(i = 1; i <= n_folhas; i++)
			{
			// Imprime frente:
				std::cout << "Sheet " << i << ", front: ";
				// Verifica se e' uma pagina blank.
				if(pag_final > n)
					std::cout << "Blank, ";
				else
					std::cout << pag_final << ", ";
				// Imprime o numero da primeira pagina.
				std::cout << pag_init << endl;
				// Incrementa o valor da primeira pagina e decrementa o da ultima.
				pag_init++;
				pag_final--;

			// Imprime verso: (repete os passos acima em ordem inversa,
			// porque no verso as paginas blank devem ficar por ultimo).
				std::cout << "Sheet " << i << ", back : ";
				std::cout << pag_init << ", ";
				if(pag_final > n)
					std::cout << "Blank" << endl;
				else
					std::cout << pag_final << endl;
				pag_init++;
				pag_final--;
			}
		}
	}
	return 0;
}