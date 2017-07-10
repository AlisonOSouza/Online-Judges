#include <cstdio>

int main()
{
	int m, n, colunas[100], i, j, linha, aux, c1, c2, c3, c4;

	while(scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0)
	{
		for(i = 0; i < m ; i++)
			colunas[i] = 0;
		
		c1 = c2 = c3 = c4 = 1;
		
		for(i = 0; i < n; i++)
		{
			linha = 0;
			for(j = 0; j < m; j++)
			{
				scanf("%d", &aux);
				linha += aux;
				colunas[j] += aux;
			}
			c1 &= (linha < m);
			c4 &= (linha > 0);
		}
		
		for(i = 0; i < m; i++)
		{
			c2 &= (colunas[i] > 0);
			c3 &= (colunas[i] < n);
		}
		
		printf("%d\n", c1 + c2 + c3 + c4);
	}
	return 0;
}