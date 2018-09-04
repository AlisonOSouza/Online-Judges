/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#11 UVA 10008 - What's Cryptanalysis?

SOLUÇÃO PROPOSTA:
Neste problema, crio um vetor de pares para armazenar a quantidade de 
cada caractere da entrada. Leio o número de linhas e leio as linhas em
seguinda. Ao ler cada linha, percorro os caracteres verificando se são
letras ou não (usando os valores da tabela ascii). Se for letra, uso uma
função que busca a posição correspondente dessa letra no vetor, e se ele
já existir no vetor incremento o contador dele. Se não existir, insiro
um novo par no vetor, correspondente a letra lida. Após ler a entrada e
preencher o vetor, uso a função sort() da biblioteca algorithm para
ordenar o vetor, auxiliado pela função compare() que ordena pelo
número de ocorrências de letras, e desempata pela posição da letra no
alfabeto. Ao final disso, imprimo o vetor ordenado.
\*******************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int busca(vector< pair<char, int> > v, char c)
{
	int i;
	for(i = 0; i < v.size(); i++)
	{
		if(v[i].first == c)
			return i;
	}
	return -1;
}

int main()
{
	int n, i, j;
	string s;
	std::vector< pair<char, int> > v;
	pair<char, int> p;

	vector< pair<char, int> >::iterator it;

	std::cin >> n;
	cin.ignore();

	while(n--)
	{
		std::getline(std::cin, s);
		std::cout << "Linha: " << s << endl;
		for(i = 0; i < s.size(); i++)
		{
			if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
			{
				j = busca(v, toupper(s[i]));
				if(j > -1)
				{
					v[j].second++;
				}
				else
				{
					p = make_pair(toupper(s[i]), 1);
					v.push_back(p);
				}
			}

		}
	}

	std::sort(v.begin(), v.end(), compare);

	for(it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " " << it->second << endl;

	return 0;
}