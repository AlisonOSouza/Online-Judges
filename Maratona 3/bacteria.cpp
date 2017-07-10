#include <iostream>
#include <string>

using namespace std;

int main()
{
	string d, s;
	size_t ret;

	while(std::cin >> d >> s)
	{
		ret = d.find(s);
		if(ret != std::string::npos)
			std::cout << "Resistente" << endl;
		else
			std::cout << "Nao resistente" << endl;
	}
	
	return 0;
}