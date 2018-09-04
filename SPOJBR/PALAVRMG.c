/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 2
PROBLEMA:	#1 PALAVRMG - Palavras Ordenadas

SOLUÇÃO PROPOSTA:
Leio o inteiro que indica a quantidade de palavras e crio um laço
para ler cada palavra. Em cada iteração, leio uma palavra e verifico
se cada letra da palavra é lexicograficamente menor que a próxima, ou
seja, se o valor ascii de cada letra é menor que o da próxima letra,
utilizando a função tolower() para evitar comparar o valor ascii de
letras maiúsculas e minúsculas.
\*******************************************************************/

#include <stdio.h>

int main(void)
{
	int i, j, P, flag;
	char word[42];
	scanf("%d", &P);
	for(i = 0; i < P; i++)
	{
	    scanf("%s", &word);
	    flag = 0;
	    for(j = 0; j < 42; j++)
	    {
	        if(word[j+1] == '\0') break;
	        if(tolower(word[j]) >= tolower(word[j+1]))
	        {
	            flag = 1;
	            break;
	        }
	    }
	    if(flag == 0) printf("%s: O\n", word);
	    else printf("%s: N\n", word);
	}
	return 0;
}