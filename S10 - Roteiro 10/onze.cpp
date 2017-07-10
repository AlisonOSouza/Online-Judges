/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 10
PROBLEMA:	#13 ONZE - Você pode dizer 11

SOLUÇÃO PROPOSTA:
Neste problema, leio os números de entrada como string, já que o tamanho
limite não caberia em int ou long long. Para verificar se o número dado
é divisível por 11 uso o critério da divisibilidade por 11, que diz que:

"Um número é divisível por 11, caso a soma dos algarismos de ordem par
subtraídos da soma dos algarismos de ordem ímpar, resultar em um número
divisível por 11. Caso o resultado seja igual a 0, pode-se afirmar
também que é divisível por 11."

FONTE: http://escolakids.uol.com.br/divisibilidade-por-11.htm

Com essa propriedade em mãos, basta calcular a soma dos algarismos de 
ordem par e ímpar, subtrair a soma de ordem par da soma de ordem ímpar
e verificar se o resultado é divisível por 11.
\*******************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ordemImpar, ordemPar, i;
    string s;

	std::cin >> s;
	while(s.compare("0") != 0)
	{
	
        ordemPar = 0;
        ordemImpar = 0;
    
        for(i = 0; i < s.size(); i+=2)
            ordemImpar += (s[i] - '0');
        
        for(i = 1; i < s.size(); i+=2)
            ordemPar += (s[i] - '0');
    
        if((ordemImpar - ordemPar) % 11 == 0)
			std::cout << s << " is a multiple of 11." << endl;
		else
			std::cout << s << " is not a multiple of 11." << endl;

		std::cin >> s;
	}
	return 0;
}