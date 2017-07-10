/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 2
PROBLEMA:	#10 ALIENSMG - Alienígenas

SOLUÇÃO PROPOSTA:
Leio a quantidade de casos de teste enquanto for diferente de 0.
Crio um laço e leio o mDNA de cada indivíduo, salvando em um vetor de
strings (da biblioteca vector). Após isso, uso std::sort() para ordenar
cada sequência de mDNA. Depois uso std::sort() novamente para ordenar 
os vetores, assim sequências iguais ficarão em posições adjacentes.
Após isso, verifico se a string[i] é igual a string[i+1]. Caso sim, 
incremento o contador de espécies (iniciado com 1). No final, é impresso
o número de espécies lidos.
\*******************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
	int i, j, n, num_especies;
	
	std::cin >> n;
	while(n > 0)
	{
	    // Lendo e ordenando as strings.
		vector<string> mDNA(n);
		for(i = 0; i < n; i++)
		{
			std::cin >> mDNA[i];
			std::sort(mDNA[i].begin(), mDNA[i].end());
		}
		
		std::sort(mDNA.begin(), mDNA.end());
		
		num_especies = 1;
		// Contando quantidade de strings diferentes.
		for(i = 0; i < n-1; i++)
		{
		    //std::cout << mDNA[i] << "\n";
		    
		    // Se não é igual (0 é igual)
		    if((mDNA[i].compare(mDNA[i+1])) != 0)
		        num_especies++;
		}
		std::cout << num_especies;
		std::cin >> n;
		if(n > 0) std::cout << "\n";
	}
	return 0;
}