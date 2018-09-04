/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 4
PROBLEMA:	#2 BIT - Bits Trocados

SOLUÇÃO PROPOSTA:
Neste problema, basta realizar uma divisão inteira do valor do saque
desejado pelo cliente pelo valor da maior nota e assim, encontrar a
quantidade dessa nota. Em seguida, basta pegar o resto dessa divisão e
dividir pela maior nota imediatamente menor que a anterior, e realizar
os mesmos passos até que se calcule a quantidade de notas de 1. No final
basta imprimir o número do teste e a quantidade de cada nota.
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int v, i, n50, n10, n5, n1, r50, r10, r5;

	std::cin >> v;
	i = 1;
	while(v > 0)
	{
		n50 = v/50;
		r50 = v%50;
		n10 = r50/10;
		r10 = r50%10;
		n5 = r10/5;
		r5 = r10%5;
		n1 = r5/1;

		std::cout << "Teste" << " " << i << endl;
		std::cout << n50 << " " << n10 << " " << n5 << " " << n1 << endl;

		i++;
		std::cin >> v;
		if(v > 0) std::cout << endl;
	}
	return 0;
}
