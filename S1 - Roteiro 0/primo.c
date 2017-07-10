/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 0
PROBLEMA:	#6 PRIMO - Primo

SOLUÇÃO PROPOSTA:
Primeiramente, verifico se o número de entrada é 2, se for imprime sim.
Caso não seja 2, verifico se a entrada é par, caso seja imprime nao.
Se a entrada for ímpar, calculo o limite a ser checado, calculado 
através da raiz quadrada do número de entrada (seguindo a ideia do 
Crivo de Eratóstenes). Uso uma flag (primo) para assumir que a entrada
é primo, e começo a percorrer os números ímpares (a partir do 3) até
chegar no limite, verificando se a entrada é divisível por algum
número. Caso seja divisível, marca a flag como não primo (valor 0)
e para a procura por um divisor. Verifico a flag primo e imprimo
a saída correspondente.
\*******************************************************************/

#include <stdio.h>
#include <math.h>

int main(void) {
    int a, i, limite, primo;
    scanf("%d", &a);
    
	// Verifica se é 2 (único par primo).
	if(a == 2)
	{
        printf("sim");
        return 0;
    }
	
	// Verifica se é par.
    if((a % 2) == 0)
    {
        printf("nao");
        return 0;
    }
    
    limite = sqrt(a);
    primo = 1; // Assume que a é primo
    
    for(i = 3; i <= limite; i+=2)
    {
        if((a % i) == 0) //se acha um fator
        {
            primo = 0; //a não é primo
            break; //sai do loop
        }
    }
    
    if(primo) printf("sim");
    else printf("nao");
    
	return 0;
}