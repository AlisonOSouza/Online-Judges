/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#2 ENCOTEL - Encontre o telefone

SOLUÇÃO PROPOSTA:
Neste problema, uso uma função auxiliar que converte cada caractere da
expressão de entrada em um número. Com isso leio a string de entrada,
e para cada caractere que não é um hífen, imprimo o número correspondente.
\*******************************************************************/

#include <iostream>
#include <string>

using namespace std;

int convert(char c)
{
	if(c == '0') return 0;
	if(c == '1') return 1;
	if(c == 'A' || c == 'B' || c == 'C') return 2;
	if(c == 'D' || c == 'E' || c == 'F') return 3;
	if(c == 'G' || c == 'H' || c == 'I') return 4;
	if(c == 'J' || c == 'K' || c == 'L') return 5;
	if(c == 'M' || c == 'N' || c == 'O') return 6;
	if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') return 7;
	if(c == 'T' || c == 'U' || c == 'V') return 8;
	if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z') return 9;
}

int main()
{
	int i;
	string s;

	while(std::cin >> s)
	{
		for(i = 0; i < s.size(); i++)
		{
			if(s[i] != '-')
				std::cout << convert(s[i]);
			else
				std::cout << "-";
		}
		std::cout << endl;
	}
	return 0;
}