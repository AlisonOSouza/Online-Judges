#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned long long n, a, b;
	double game_percent;

	std::cin >> n;
	while(n > 0)
	{
		game_percent = n/90.0;
		a = ceil(game_percent * 7);
		b = floor(game_percent * 1);
		
		std::cout << "Brasil " << b << " x Alemanha " << a << endl;
		std::cin >> n;
	}
	return 0;
}