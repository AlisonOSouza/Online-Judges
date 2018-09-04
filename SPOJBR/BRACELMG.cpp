/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 2
PROBLEMA:	#2 BRACELMG - Braceletes Mágicos

SOLUÇÃO PROPOSTA:
Leio o número de casos de testes e leio a sequência proibida (padrão)
e o bracelete. Concateno o bracelete duas vezes em uma só string, para
poder pegar os casos onde o padrão está nas pontas do bracelete. Após
isso, em outra string inverto o padrão original, para pegar os casos
onde o padrão está ao contrário no bracelete. Fazendo isso, basta
procurar no bracelete (duplo) o padrão e o padrão invertido. Caso
ache um dos dois, marco uma flag e uso a flag para decidir se imprime
N ou S em cada caso.
\*******************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string padrao, bracelete, bracelete2;
    int i, j, n, flag, size;
    std::size_t aux;

    std::cin >> n;
    while(n > 0)
    {
        flag = 0;
        std::cin >> padrao;
        std::cin >> bracelete;

        // Concatenando dois braceletes
        bracelete2.clear();
        bracelete2 += bracelete;
        bracelete2 += bracelete;
        
		// Inverte o padrão
		std::string padrao_r(padrao);
		std::reverse(padrao_r.begin(), padrao_r.end());
		
		// Procuro o padrão e o padrão inverso no bracelete
		aux = string::npos;
        aux = bracelete2.find(padrao);
        if(aux != std::string::npos) flag = 1;
        
        aux = bracelete2.find(padrao_r);
        if(aux != std::string::npos) flag = 1;

        if(flag == 1) std::cout << "S";
        else std::cout << "N";

        n--;
        if(n > 0) std::cout << endl;
    }

	return 0;
}
