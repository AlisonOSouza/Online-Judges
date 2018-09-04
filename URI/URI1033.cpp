/*
	@problem:	Quantas Chamadas Recursivas? - 1033
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>

using namespace std;

int bigMod(long long n, int M)
{
	if(n <= 0)
		return 0;

	long long a, b, c, d, r;
	
	a = 1, b = 0 , c = 0, d = 1;
	n--;

	while(n > 0)
	{
		if(n % 2 == 1)
		{
			r =((d*b) + (c*a)) % M;
			b =(d * (b+a) + (c*b)) % M;
			a = r;
		}

		r =(c*c + d*d) % M;
		d =(d * (2*c + d)) % M;
		c = r;
		n = n / 2;
	}
	return (a + b) % M;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	long long n, b, mod_b, testCase = 1;

	while(std::cin >> n >> b && (n > 0 || b > 0))
	{
		mod_b =((2 * bigMod(n+1, b)) - 1 + b) % b;
		std::cout << "Case " << testCase << ": " << n << " " << b << " " << mod_b << endl;
		testCase++;
	}
	return 0;
}
