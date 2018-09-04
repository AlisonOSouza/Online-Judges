/*
	@problem:	Greedy Gift Givers - 119
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef struct pessoa
{
	string nome;
	int valorDado;
	int valorRecebido;
} t_Pessoa;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int nPessoas, valorDado, qtdePresentes, troco, valorPresente, i, j, k, l;
	string nome, nomePresenteado;
	t_Pessoa pessoa[10];

	std::cin >> nPessoas;
	while(!cin.eof())
	{
		// Leio a lista de nomes.
		for(i = 0; i < nPessoas; i++)
		{
			std::cin >> pessoa[i].nome;
			pessoa[i].valorDado = 0;
			pessoa[i].valorRecebido = 0;
		}
		
		// Leio a lista de nomes e valores gastos
		for(i = 0; i < nPessoas; i++)
		{
			std::cin >> nome >> valorDado >> qtdePresentes;
			if(qtdePresentes > 0)
			{
				valorPresente = valorDado / qtdePresentes;
				troco = valorDado % qtdePresentes;
				
				for(j = 0; j < nPessoas; j++)
				{
					if(nome.compare(pessoa[j].nome) == 0)
					{
						pessoa[j].valorDado = valorDado;
						pessoa[j].valorRecebido += troco;

						for(k = 0; k < qtdePresentes; k++)
						{
							std::cin >> nomePresenteado;
							for(l = 0; l < nPessoas; l++)
							{
								if(nomePresenteado.compare(pessoa[l].nome) == 0)
								{
									pessoa[l].valorRecebido += valorPresente;
								}
							}
						}
					}
				}
			}
		}
		for(i = 0; i < nPessoas; i++)
		{
			std::cout << pessoa[i].nome << " " << pessoa[i].valorRecebido-pessoa[i].valorDado << endl;
		}
		std::cin >> nPessoas;
		if(!cin.eof())
			std::cout << endl;
	}
	return 0;
}
