/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 3
PROBLEMA:	#4 Candy - CANDY I

SOLUÇÃO PROPOSTA:
Neste problema, leio a quantidade de pacotes 'n' e faço um laço enquanto
'n' for maior que -1 (que indica o final da entrada). Crio então, um
vetor 'packet' com 'n' posições, e leio a quantidade de doces em cada
pacote, salvo no vetor 'packet' e somo todos os doces na variável 
'candy_num'. Após isso, verifico se o resto da divisão de 'candy_num'
por 'n' é zero (ou seja, se será possível colocar um mesmo número de
doces em todos os pacotes). Caso seja possível, calculo na variável
'candy_per_packet' a quantidade de doces por pacotes e inicializo a
variável 'num_moves' como zero. Após isso, crio um laço de 0 até 'n-1'
para verificar se cada posição do vetor 'packet' tem mais do que 
'candy_per_packet' em cada pacote. Se tiver, acrescento na variável
'num_moves' a diferença entre o número de doces em 'packet[i]' e
'candy_per_packet'. Ao final do laço, imprimo a variável 'num_moves'.
Caso não seja possível colocar um mesmo número de doces em todos os
pacotes, imprimo -1.
\*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int i, n, candy_num, candy_per_packet, num_moves;

	std::cin >> n;
	while(n > -1)
	{
	    std::vector<int> packet(n);
		i = 0;
		candy_num = 0;
		while(i < n)
		{
			std::cin >> packet[i];
			candy_num += packet[i];
			i++;
		}

		if(candy_num % n == 0)
		{
			candy_per_packet = candy_num / n;
			num_moves = 0;
			i = 0;
			while(i < n)
			{
				if(packet[i] > candy_per_packet)
				    num_moves += (packet[i] - candy_per_packet);
				i++;
			}
			std::cout << num_moves;
		}
		else
		{
			std::cout << -1;
		}
		std::cin >> n;
		if(n > -1) std::cout << endl;
	}

	return 0;
}