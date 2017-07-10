/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 9
PROBLEMA:	#8 UVa 10310 - Dog and Gopher

SOLUÇÃO PROPOSTA:
Neste problema, tentei utilizar o teorema de pitágoras para calcular as
distâncias entre pontos e verificar se a distância do cachorro até o 
buraco era maior ou igual a duas vezes a distância da marmota (? dopher)
até o mesmo buraco, porém por causa da precisão não consegui fazer
com que o UVa aceitasse meu código. Dado isso, decidi implementar a
fórmula dada na página de auxílio do problema.
\*******************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, x, find;
	double gx, gy, dx, dy, hx[1001], hy[1001], distGOPHER, distDOG;
	while(scanf("%ld%lf%lf%lf%lf",&n, &gx, &gy, &dx, &dy) == 5)
	{
		find = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%lf%lf", &hx[i], &hy[i]);
		}
		for(i = 0; i < n; i++)
		{
			distGOPHER = 4 * (pow((hx[i] - gx), 2) + pow((hy[i] - gy), 2));
			distDOG = pow((hx[i] - dx), 2) + pow((hy[i] - dy), 2);
			if(distGOPHER <= distDOG)
			{
				find++;
				x = i;
				break;
			}
		}
		if(find == 0) printf("The gopher cannot escape.\n");
		else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hx[x],hy[x]);
	}
	return 0;
}