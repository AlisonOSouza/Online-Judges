/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 0
PROBLEMA:	#3 FATORIA2 - Fatorial

SOLUÇÃO PROPOSTA:
Leio o número de entrada (a) e uso uma variável auxiliar (b, inicialmente
setada como 1). Em um loop, multiplico b por a, salvando o resultado
em b. A cada iteração do loop, decremento o valor de a até chegar ao
valor 1. Nesse ponto, é encerrado o loop e impresso a saída.
\*******************************************************************/

#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d", &a);
	b = 1;
	while(a > 1)
	{
		b = a * b;
		a--;
	}
	printf("%d", b);
	return 0;
}