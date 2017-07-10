/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 3
PROBLEMA:	#5 CMIYC - Catch Me If You Can

SOLUÇÃO PROPOSTA:
Neste problema, leio o inteiro 't' que é o número de casos de testes.
Crio então, um laço para calcular os 't' casos de testes.
Há um padrão nesse problema, que caso o tamanho do terreno seja um
múltiplo de 3, a solução é o tamanho do terreno ('n') dividido por 3.
Caso o tamanho do terreno não seja maior que três, a solução é 0.
\*******************************************************************/


#include <iostream>

using namespace std;

int main(void)
{
	int t;
	long long n;
    
    std::cin >> t;
    
    while(t > 0)
    {
        std::cin >> n;
        if(n % 3 == 0)
            std::cout << n/3;
        else
            std::cout << 0;
        t--;
        if(t > 0) std::cout << endl;
    }
	return 0;
}