/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 3
PROBLEMA:	#1 POPULAR - Popularidade

SOLUÇÃO PROPOSTA:
Neste problema, leio a quantidade de alunos da escola e crio dois
laços, um para verificar se é recebido 0 na entrada, e o outro para
para ler as cédulas de voto de cada aluno. Crio um vetor em que cada
posição 'i' indica o número de votos obtido pelo aluno 'i'.
Leio 'n' cédulas de votação uma de cada um dos 'n' alunos, e caso o 
voto seja 1, incremento a posição correspondente do vetor. Caso seja
0, não faço nada. Após ler toda as cédulas, percorro o vetor para
buscar o maior elemento e imprimo ele na tela.
\*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int i, n, aux;
	std::cin >> n;
	while(n > 0)
	{
		vector<int> votos(n);
		for(i = 0; i < n; i++)
		{
			votos[i] = 0;
		}
		
		while(n > 0)
		{
			for(i = 0; i < votos.size(); i++)
			{
				std::cin >> aux;
				if(aux) votos[i]++;
			}
			n--;
		}
		
		aux = 1;
		for(i = 0; i < votos.size(); i++)
		{
			if(votos[i] > aux) aux = votos[i];
		}
		std::cout << aux;
		std::cin >> n;
		if(n > 0) std::cout << endl;
	}

	return 0;
}