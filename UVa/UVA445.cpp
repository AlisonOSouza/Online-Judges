/*
	@problem:	Marvelous Mazes - 445
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int i, j, qtde;
	string input;

	while(getline(cin, input))
	{
		qtde = 0;
		for(i = 0; i < input.size(); i++)
		{
			// Se for ! ou \n, vai para a linha seguinte.
			if(input[i] == '!' || input[i] == '\n')
			{
				std::cout << endl;
				qtde = 0;
			}
			else if(isdigit(input[i]))
			{
				qtde += input[i] - '0';
			}
			else
			{
				for(j = 0; j < qtde; j++)
				{
					if(input[i] == 'b')
						std::cout << ' ';
					else
						std::cout << input[i];
				}
				qtde = 0;
			}
		}
		std::cout << endl;
	}
	return 0;
}