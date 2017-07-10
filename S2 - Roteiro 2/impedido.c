/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 2
PROBLEMA:	#5 IMPEDIDO - Ele está impedido

SOLUÇÃO PROPOSTA:
Leio a quantidade de atacantes e defensores até que leia os valores
de escape (0 0). Após isso, leio os atacantes e salvo a menor distância
de um atacante ao gol em uma variável. Leio então os defensores e 
salvo as duas menores distâncias em duas variáveis. Com esses valores
salvos, verifico se a distância do último atacante é menor que a 
distância do penúltimo defensor. Se sim, o jagador está impedido e
imprimo Y. Caso contrário, não está impedido e imprimo N.
\*******************************************************************/

#include <stdio.h>

int main(void)
{
	int a, d, dist_ult_atk, dist_ult_def, dist_pnult_def, i, aux;
	
	scanf("%d %d", &a, &d);
	
	while(a > 0 && d > 0)
	{
		// Procura a distância do atacante mais próximo do gol.
		scanf("%d", &dist_ult_atk);
		for(i = 0; i < a-1; i++)
		{
			scanf("%d", &aux);
			if(aux < dist_ult_atk) dist_ult_atk = aux;
		}
		
		// Procura a distância dos dois defensores mais próximos do gol.
		scanf("%d %d", &dist_pnult_def, &dist_ult_def);
		if(dist_pnult_def < dist_ult_def)
		{
			aux = dist_ult_def;
			dist_ult_def = dist_pnult_def;
			dist_pnult_def = aux;
		}
		for(i = 0; i < d-2; i++)
		{
			scanf("%d", &aux);
			if(aux < dist_pnult_def)
			{
				if(aux < dist_ult_def)
				{
					dist_pnult_def = dist_ult_def;
					dist_ult_def = aux;
				}
				else
				{
					dist_pnult_def = aux;
				}
			}
		}
		
		// Verifico se a distância do último atacante é menor que
		// a distância do penúltimo defensor.
		if(dist_ult_atk >= dist_pnult_def) printf("N");
		else printf("Y");
		
		scanf("%d %d", &a, &d);
		if(a > 0 && d > 0) printf("\n");
	}
	return 0;
}