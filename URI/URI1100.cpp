/*
	@problem:	Movimentos do Cavalo - 1100
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

typedef struct posicao 
{
	int linha;
	int coluna;
	int moves;
} posicao_t;

posicao_t lista[1000000];

int main()
{
	string a, b;

	while(std::cin >> a >> b)
	{
		posicao_t origem, destino, atual;
		origem.linha = (int)a[0] - 96;
		origem.coluna = (int)a[1] - 48;
		origem.moves = 0;
		destino.linha = (int)b[0] - 96;
		destino.coluna = (int)b[1] - 48;

		int prox = 0;
		int ult = 0;
		lista[0] = origem;

		while(1)
		{
			atual = lista[prox++];
			if(atual.linha == destino.linha && atual.coluna == destino.coluna)
				break;

			if(atual.linha + 2 < 9)
			{
				if(atual.coluna + 1 < 9)
				{
					ult++;
					lista[ult].linha = atual.linha + 2;
					lista[ult].coluna = atual.coluna + 1;
					lista[ult].moves = atual.moves + 1;
				}

				if(atual.coluna - 1 > 0)
				{
					ult++;
					lista[ult].linha = atual.linha + 2;
					lista[ult].coluna = atual.coluna - 1;
					lista[ult].moves = atual.moves + 1;
				}
			}


			if(atual.linha - 2 > 0)
			{
				if(atual.coluna + 1 < 9)
				{
					ult++;
					lista[ult].linha = atual.linha - 2;
					lista[ult].coluna = atual.coluna + 1;
					lista[ult].moves = atual.moves + 1;
				}

				if(atual.coluna - 1 > 0)
				{
					ult++;
					lista[ult].linha = atual.linha - 2;
					lista[ult].coluna = atual.coluna - 1;
					lista[ult].moves = atual.moves + 1;
				}
			}

			if(atual.coluna + 2 < 9)
			{
				if(atual.linha + 1 < 9)
				{
					ult++;
					lista[ult].linha = atual.linha + 1;
					lista[ult].coluna = atual.coluna + 2;
					lista[ult].moves = atual.moves + 1;
				}

				if(atual.linha - 1 > 0)
				{
					ult++;
					lista[ult].linha = atual.linha - 1;
					lista[ult].coluna = atual.coluna + 2;
					lista[ult].moves = atual.moves + 1;
				}
			}

			if(atual.coluna - 2 > 0)
			{
				if(atual.linha + 1 < 9)
				{
					ult++;
					lista[ult].linha = atual.linha + 1;
					lista[ult].coluna = atual.coluna - 2;
					lista[ult].moves = atual.moves + 1;
				}

				if(atual.linha - 1 > 0)
				{
					ult++;
					lista[ult].linha = atual.linha - 1;
					lista[ult].coluna = atual.coluna - 2;
					lista[ult].moves = atual.moves + 1;
				}
			}
		}

		std::cout << "To get from " << a << " to " << b << " takes "
				  << atual.moves << " knight moves." << endl;
	}
	return 0;
}