//AINDA NÃO FUNCIONA

/*
4
cardonha 9
infelizreprovado 3
marcel 9 
infelizaprovado 3
5
alison 7
yuri 7
daniel 8
ivo 9
lucas 6
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j, n, prob_resol, prob_resol_reprovado, flag;
	char nome[20], rep_nome[20];

	scanf("%d", &n);
	j = 1;
	while(!feof(stdin))
	{
		prob_resol_reprovado = 11; //valor impossível
		//strcpy(rep_nome, "{"); //valor ascii imediatamente superior a z.
		while(n > 0)
		{
			scanf("%s %d", &nome, &prob_resol);
			if(prob_resol < prob_resol_reprovado)
			{
				prob_resol_reprovado = prob_resol;
				strcpy(rep_nome, nome);
			}
			else if(prob_resol == prob_resol_reprovado)
			{
				flag = 0;
				for(i = 0; i < 20; i++)
				{
					if(nome[i] > rep_nome[i])
					{
						flag = 1;
						break;
					}
					if(nome[i] != '\0' || rep_nome[i] != '\0') break;
				}
				if(flag == 1) stpcpy(rep_nome, nome);
			}
			n--;
			//printf("%s\n", rep_nome);
		}
		printf("Instancia %d\n%s", j, rep_nome);
		j++;
		scanf("%d", &n);
		if(!feof(stdin)) printf("\n");
	}
	return 0;
}
