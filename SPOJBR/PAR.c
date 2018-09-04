/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 0
PROBLEMA:	#5 PAR - Par ou ímpar

SOLUÇÃO PROPOSTA:
Leio o número de partidas e dentro do loop de rodadas leio o nome dos
participantes. É impresso a linha "Teste n" e dentro de outro loop leio
os números jogados em cada partida, somando-os e verificando se a soma
é par ou ímpar. Em cada caso imprime o jogador vencedor da partida.
Após as N rodadas, leio o próximo valor de N e verifico se ele é
maior que zero, se for devo imprimir uma linha vazia, se for 0 então
não imprimo a linha vazia e saio do loop externo.
\*******************************************************************/

#include <stdio.h>

int main(void)
{
    int a, b, i, n;
    char jog1[10], jog2[10];
    
    scanf("%d", &n);
    i = 1;
    while(n > 0)
    {
        scanf("%s", &jog1);
        scanf("%s", &jog2);
        printf("Teste %d\n", i);
		
        while(n > 0)
        {
            scanf("%d", &a);
            scanf("%d", &b);
            a += b;
            if((a % 2) == 0) printf("%s\n", jog1);
            else printf("%s\n", jog2);
            n--;
        }
        
        i++;
        scanf("%d", &n);
        if(n > 0) printf("\n");
    }
	return 0;
}