/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 8
PROBLEMA:	#8 FINDSR - Find String Roots

SOLUÇÃO PROPOSTA:
Neste problema, leio as strings de entrada até achar o padrão * que
indica não haver mais entradas. Uso a função getDivisor() para pegar um
vetor 'V' com os divisores do tamanho da string original, ou seja, o
vetor com os tamanhos que as strings raízes poderão ter (ordenado do
maior tamanho para o menor). Após isso, uso a função isRoot() para
verificar se há alguma string com tamanho contido no vetor 'V' que é
realmente raiz da string de entrada. Se houver alguma string raiz, por
construção ela será a maior string raiz, pois começamos a busca pelo
maior tamanho possível. Então imprimo a quantidade máxima de raizes
para a string s.
\*******************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getDivisor(int n)
{
	int i;
	vector<int> d;
	for(i = 1; i <= n; i++)
	{
		if((n % i) == 0)
			d.push_back(i);
	}
	return d;
}

bool isRoot(string s, int k)
{
	int i, j, b;
	string aux(s.begin(), s.begin()+k);
	b = s.size()/k;

	for(i = 0; i < b; i++)
	{
		for(j = 0; j < aux.size(); j++)
		{
			if(s[(i * k) + j] != aux[j])
				return false;
		}
	}
	return true;
}

int main()
{
	int i;
	string s;
	std::vector<int> v;

	std::cin >> s;
	while(s.compare("*") != 0)
	{
		v = getDivisor(s.size());

		for(i = 0; i < v.size(); i++)
		{
			if(isRoot(s, v[i]))
			{
				std::cout << s.size()/v[i] << endl;
				break;
			}
		}
		std::cin >> s;
	}

	return 0;
}