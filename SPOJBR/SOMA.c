/*
	@problem:	Soma - SOMA
	@site:		SPOJ BR
	@author:	Alison Souza
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int limite, a, b, i;
	a  = 0;
	scanf("%d", &limite);
	for(i = 0; i < limite; i++)
	{
		scanf("%d", &b);
		a +=b;
	}
	printf("%d", a);
	return 0;
}
