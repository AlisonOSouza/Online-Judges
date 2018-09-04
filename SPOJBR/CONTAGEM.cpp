/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 6
PROBLEMA:	#1 CONTAGEM - Não é mais um Joguinho Canadense

SOLUÇÃO PROPOSTA:
Neste problema, usei a propriedade que qualquer valor de 'a' antes da 
primeira ocorrência de 'b' é descartado, já que a palavra estará no estado
'p'. Na primeira ocorrência de 'b', a palavra estará no estado 'q' e a 
cada 'b' após a primeira ocorrência, eu somo em uma variável "2^r", onde
'r' é o tamanho do restante da palavra que falta ser computada.
\*******************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	unsigned int i, j;
	long long int res;
	string s;

	j = 1;
	while(std::cin >> s)
	{
		res = 0;
		for(i = 0; i < s.length(); i++)
		{
			if(s[i] == 'b')
			{
				res += (long long int)pow(2, (s.length() - i-1));
			}
		}
		std::cout << "Palavra " << j << endl;
		std::cout << res << endl << endl;
		j++;
	}

	return 0;
}