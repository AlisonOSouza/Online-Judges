/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 0
PROBLEMA:	#10 OVERF09 - Overflow

SOLUÇÃO PROPOSTA:
Leio o maior número que o computador representa (n) e em seguida leio
o primeiro operando (a), operador (sinal) e segundo operando (b). Se 
o operador for o operador de soma (+), verifico se a soma entre 'a' e
'b' é maior que o limite 'n', se for imprime OVERFLOW, se não imprime
OK. O mesmo ocorre com o operando '*', verificando o produto de 'a' e
'b'.
\*******************************************************************/

#include <stdio.h>

int main(void) {
    int a, b, n;
    char sinal;
    scanf("%d", &n);
    scanf("%d %c %d", &a, &sinal, &b);
    
    if(sinal == '+')
    {
        if(a + b > n) printf("OVERFLOW");
        else printf("OK");
    }
    else if(sinal == '*')
    {
        if(a * b > n) printf("OVERFLOW");
        else printf("OK");
    }
    
	return 0;
}