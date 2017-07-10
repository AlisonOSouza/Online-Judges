#include <iostream>
#include <string>

using namespace std;

int main()
{
	int qt, j1, j2;
	string jog1, jog2, esc1, esc2;

	std::cin >> qt;
	while(qt > 0)
	{
		std::cin >> jog1 >> esc1 >> jog2 >> esc2;
		std::cin >> j1 >> j2;

		if((j1 + j2) % 2 == 0)
		{
			if(esc1.compare("PAR") == 0)
			{
				std::cout << jog1 << endl;
			}
			else
			{
				std::cout << jog2 << endl;
			}
		}
		if((j1 + j2) % 2 == 1)
		{
			if(esc1.compare("IMPAR") == 0)
			{
				std::cout << jog1 << endl;
			}
			else
			{
				std::cout << jog2 << endl;
			}
		}
		qt--;
	}

	return 0;
}