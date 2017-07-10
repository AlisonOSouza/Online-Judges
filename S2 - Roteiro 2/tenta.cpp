/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 2
PROBLEMA:	#4 TENTA - Brincadeira das Tentativas

SOLUÇÃO PROPOSTA:
Enquanto não leio o valor de escape (0), leio a quantidade de figurinhas
e crio um laço para ler todas as figurinhas, salvando elas num vetor de
tamanho máximo 8. Uso a função std::sort() para ordenar o vetor e depois
gero as permutações usando um laço e a função std::next_permutation().
\*******************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int i, n, fig[8];
	
	std::cin >> n;
	while(n > 0)
	{
		for(i = 0; i < n; i++)
		{
			std::cin >> fig[i];
		}
		
		std::sort(fig, fig+n);
		
		do
		{
		    for(i = 0; i < n; i++)
		    {
                std::cout << fig[i];
                if(i != n-1) std::cout << " ";
		    }
            std::cout << "\n";
		} while(std::next_permutation(fig, fig+n));
		
		std::cin >> n;
		if(n > 0) std::cout << "\n";
	}
	return 0;
}