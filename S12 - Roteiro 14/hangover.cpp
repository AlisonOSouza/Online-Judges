/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 14
PROBLEMA:	#1 HANGOVER - Hangover

SOLUÇÃO PROPOSTA:
Neste problema, pré-computo os valores de cada parcela do somatório e
salvo os valores correspondentes num vetor. Depois, leio o valor do
tamanho limite da pilha e enquanto a soma das parcelas do vetor é menor
que o tamanho limite da pilha, somo mais uma posição do vetor. No final,
imprimo a quantidade de elementos do vetor somados.
\*******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int i;
	float n, sum, vetor[275];
	
	// Pré computa o valor do somatório.
	for(i = 0; i < 275; i++)
	{
		vetor[i] = 1.0/(2.0+i);
	}

	std::cin >> n;
	while(n != 0.00)
	{
		sum = 0;
		for(i = 0; i < 275; i++)
		{
			sum += vetor[i];
			if (sum >= n)
				break;
		}
	
		std::cout << i+1 << " card(s)" << endl;
		std::cin >> n;
	}
	return 0;
}