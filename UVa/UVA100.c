/*
	@problem:	The 3n + 1 problem - 100
	@site:		UVa
	@author:	Alison Souza
*/

#include <stdio.h>

int ciclo(int n)
{
	int ret = 1;
	while(n != 1)
	{	
		if(n % 2 == 1)
			n = 3*n+1;
		else
			n = n/2;
		ret++;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	int i, j, k, cont, maxCiclo;

	while(scanf("%d %d", &i, &j) == 2)
	{
		printf("%d %d ", i, j);

		if(i > j)
		{
			k = i;
			i = j;
			j = k;
		}

		maxCiclo = 0;
		for(cont = i; cont <= j; cont++)
		{
			k = ciclo(cont);
			if(k > maxCiclo)
				maxCiclo = k; 
		}
		
		printf("%d\n", maxCiclo);
	}

	return 0;
}