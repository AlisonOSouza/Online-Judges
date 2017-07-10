#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int i, n;
	
	std::cin >> n;
	std::vector<int> litros(n);
	for(i = 0; i < n; i++)
	{
		std::cin >> litros(n);
	}
	
	std::sort(litros.begin(), litrs.end());
	
	if(n % 2 == 1) std::cout << litros[(n/2) + 1];
	else std::cout << ((litros[n/2] + litros[(n/2) + 1])/2);
	
	return 0;
}