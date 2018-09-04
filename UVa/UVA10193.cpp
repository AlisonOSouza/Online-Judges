/*
	@problem:	All You Need Is Love - 10193
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

int bin2dec(string bin) // Binary to decimal
{
	int dec, base, i; 

	dec = 0;
	base = 1;
	for(i = bin.length()-1; i >= 0; i--)
	{
		if(bin[i] == '0')
			base = base * 2;
		else
		{
			dec += 1*base;
			base = base * 2;
		}
	}
	return dec;
}

int MDC(int a, int b)
{
	if(b > a)
		return MDC(b, a);
	if(b == 0)
		return a;
	else
		return MDC(b, a%b);
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int i, n, d1, d2;
	string s1, s2;

	// Le o valor de 'n' e itera sobre cada par de entrada.
	std::cin >> n;
	for(i = 1; i <= n; i++)
	{
		// Le os numeros de entrada e chama a funcao que converte
		// as strings em binario para int decimal. 
		std::cin >> s1 >> s2;
		d1 = bin2dec(s1);
		d2 = bin2dec(s2);

		// Se o MDC entre os dois numeros for maior que 1, entao existe um
		// valor 'L' que pode ser subtraido dos dois até sobrar apenas 'L'.
		if(MDC(d1, d2) > 1)
			std::cout << "Pair #" << i << ": All you need is love!" << endl;
		else
			std::cout <<  "Pair #" << i << ": Love is not all you need!" << endl;
	}
	return 0;
}