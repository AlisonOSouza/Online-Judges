/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#6 NHAY - A Needle in the Haystack

SOLUÇÃO PROPOSTA:
Neste problema, crio uma função que preenche um map com o padrão (needle)
encontrado, atribuindo a cada letra um valor correspondente ao tamanho
do neddle menos a posição da letra (-1 por causa da linguagem).
Leio a string haystack e itero sobre cada caractere dessa string,
verificando se a posição atual do haystack mais um deslocamento é
igual a posição desse deslocamento no padrão needle. Se for igual, 
decremento o deslocamento e refaço a verificação, checando o resto do
padrão. Se não for igual paro o laço de verificação. Após isso, verifico
se a variável do deslocamento é menor que zero, ou seja, se o padrão foi
totalmente encontrado na string haystack, e se foi encontrado imprimo
a posição da ocorrência do padrão.
\*******************************************************************/

#include <iostream>
#include <map>

using namespace std;

void needleProcess(string &s, map<char, int> &m)
{
	int i;
	for(i = 0; i < s.size(); i++)
	{
		m[s[i]] = s.size() - i - 1;
	}
	m[s[s.size() - 1]] = 1;
}

int main()
{
	map<char, int> m;
	map<char, int>::iterator it;
	string needle, haystack;
	int length, aux, i;
	bool flag;
	
	while(std::cin >> length >> needle >> haystack)
	{
		m.clear();
		needleProcess(needle, m);

		i = 0;
		flag = false;
		while(i < haystack.size())
		{
			aux = length - 1;
			while(aux >= 0)
			{
				if(haystack[i + aux] == needle[aux])
					aux--;
				else
					break;
			}

			if(aux < 0)
			{
				std::cout << i << endl;
				flag = true;
				i++;
			}
			else
			{
				it = m.find(needle[aux]);
				if(it == m.end())
					i += length;
				else
					i += it->second;
			}
		}

		if(flag == false)
			std::cout << endl;
	}

	return 0;
}