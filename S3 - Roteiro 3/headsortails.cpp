/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 3
PROBLEMA:	#2 HEADSORTAILS - Heads or Tails

SOLUÇÃO PROPOSTA:
Neste problema, leio o número de jogadas das duas participantes e leio
em seguida o número mínimo de 'heads' tiradas por cada uma. Verifico
se o número de jogadas de Vasya é menor ou igual que a quantidade de 
'heads' de Petya, caso seja imprimo 0. Caso não seja crio dois laços
aninhados indo do número mínimo de 'heads' de Vasya até o número de 
jogadas dela (ou seja, do mínimo ao máximo) e faço o mesmo para Petya
Se o número de 'heads' possíveis de Vasya for maior que o de Petya,
insiro os dois valores em um vetor 'saida'. Ao final dos laços, imprimo
a quantidade de possibilidades de partida (tamanho do vetor saida divido
por 2, já que a cada possibilidade eu inseria dois valores no vetor, um
indicando o número de 'heads' de Vasya e outro de Petya), e crio um laço
para imprimir as possibilidades de partidas.
\*******************************************************************/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int jogadas_vasya, jogadas_petya, min_heads_vasya, min_heads_petya;
	int i, j;
	std::vector<int> saida;
	
	std::cin >> jogadas_vasya >> jogadas_petya >> min_heads_vasya >> min_heads_petya;
	
	if(jogadas_vasya <= min_heads_petya) 
	{
		std::cout << 0;
	}
	else
	{
		for(i = min_heads_vasya; i <= jogadas_vasya; i++)
		{
			for(j = min_heads_petya; j <= jogadas_petya; j++)
			{
				if(i > j)
				{
					saida.push_back(i);
					saida.push_back(j);
				}
			}
		}
		
		std::cout << saida.size() / 2 << endl;
		i = 0;
		while(i < saida.size())
		{
			std::cout << saida[i] << " " << saida[i+1];
			i += 2;
			if(i < saida.size()) std::cout << endl;
		}	
	}
	return 0;
}