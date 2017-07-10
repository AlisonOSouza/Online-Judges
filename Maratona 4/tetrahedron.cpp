#include <iostream>

using namespace std;

int main()
{
	long long n, f, g, fAnt, gAnt, i;

	std::cin >> n;
	f = 0;
	g = 0;
	fAnt = 0;
	gAnt = 1;
	for(i = 2; i <= n; i++)
	{
		f = (4 - 1) * gAnt;
		g = fAnt + (4 - 2) *gAnt;

		f %= 1000000007;
		g %= 1000000007;

		fAnt = f;
		gAnt = g;
	}
	std::cout << f << endl;
	return 0;
}