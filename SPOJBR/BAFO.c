/*
	@problem:	Bafo - BAFO
	@site:		SPOJ BR
	@author:	Alison Souza
*/

#include <stdio.h>

int main(void)
{
	int r, a, b, n, sum_a, sum_b;
	n = 0;
	while(scanf("%d", &r) == 1 && r > 0)
	{
		sum_a = 0;
		sum_b = 0;

		while(r--)
		{
			scanf("%d %d", &a, &b);
			sum_a += a;
			sum_b += b;
		}
		n++;
		printf("Teste %d\n", n);
		if(sum_a > sum_b) printf("Aldo\n\n");
		else printf("Beto\n\n");

	}
	return 0;
}