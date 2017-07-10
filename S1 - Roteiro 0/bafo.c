// Não passou ainda...
// Algo na formatação da saída tá errado.

#include <stdio.h>

int main(void) {
	int a, b, n, r, aldo = 0, beto = 0;
	
	scanf("%d", &r);
	n = 1;
	while(r != 0)
	{
	    while(r > 0)
	    {
	        scanf("%d", &a);
	        aldo += a;
	        scanf("%d", &b);
	        beto += b;
	        r--;
	    }
	    if(aldo > beto) printf("Teste %d\nAldo\n", n);
	    else printf("Teste %d\nBeto\n", n);
    	
	    n++;
	    scanf("%d", &r);
	    if(r != 0) printf("\n");
	}
	return 0;
}