/*
	@problem:	Slurpys - 384
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

/*
	SLUMP:	Comeca com D ou E,
			seguido por F's,
			seguido por outra Slump ou termina em G.
*/
bool isSlump(string s, int a, int b)
{
	int aux;

	// Comeca com D ou E
	if(s[a] != 'D' && s[a] != 'E')
		return false;

	// Se a ultima letra nao for G, entao nao e' Slump
	if(s[b] != 'G')
		return false;

	// Segunda letra e' F
	if(s[a + 1] != 'F')
		return false;

	aux = a + 1;
	// Enquanto for F, avanca.
	while(s[aux] == 'F')
		aux++;

	if(aux == b)
		return true;

	return isSlump(s, aux, b);
}

/*
	SLIMP:	Comeca com A,
			se tem duas letras, so' sera' Slimp se for AH
			se segunda letra nao e' H, entao:
				Segunda letra e' B, seguido de um Slimp seguido de um C.
				Segunda parte e' um Slump, seguido de C.
*/
bool isSlimp(string s, int a, int b)
{
	// Se tem duas letras, so' sera' Slimp se for AH. 
	if(b - a + 1 == 2)
	{
		if(s[a] == 'A' && s[b] == 'H')
			return true;
		else 
			return false;
	}

	// Se nao comeca com A, nao e' Slimp.
	if(s[a] != 'A')
		return false;

	// Se tem mais de duas letras e nao termina em C, nao e' Slimp
	if(s[b] != 'C')
		return false;

	// Se a segunda letra e' B
	if(s[a + 1] == 'B')
	{
		// Se a parte seguinte e' um Slimp
		return isSlimp(s, a + 2, b - 1);
	}

	// Se a segunda parte e' um Slump
	return isSlump(s, a + 1, b - 1);
	
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, i, j, p;
	string s;
	bool slimp, slump;

	std::cin >> n;
	std::cout << "SLURPYS OUTPUT" << endl;

	for(i = 0; i < n; i++)
	{
		std::cin >> s;
		/*
			SLURPY:	Slimp seguida de Slump.
			Vamos procurar onde a Slimp termina (H ou ultimo C).
		*/
		
		// Se duas primeiras letras sao AH, entao Slimp acaba na posicao 1.
		if(s[0] == 'A' && s[1] == 'H')
			p = 1;
		// Senao, procura o ultimo C.
		else
		{
			for(j = s.size()-1; j >= 0; j--)
			{
				if(s[j] == 'C')
				{
					p = j;
					break;
				}
			}
		}

		// Agora verifica se temos uma Slimp e Slump, respectivamente
		slimp = isSlimp(s, 0, p);
		slump = isSlump(s, p+1, s.size()-1);
		
		if(slimp && slump)
			std::cout << "YES" << endl;
		else
			std::cout << "NO" << endl;	
	}

	std::cout << "END OF OUTPUT" << endl;

	return 0;
}