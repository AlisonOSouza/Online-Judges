/*
	@problem:	TEX Quotes - 272
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int i;
	string input;
	// true se existe aspas abertas, false caso contrario.
	bool flag = false; 
	
	// Le a linha
	while(getline(cin, input))
	{
		// Percorre os caracteres
		for(i = 0; i < input.size(); i++)
		{
			// Se e' aspas duplas
			if(input[i] == '"')
			{
				// Verifica se e' de abertura ou fechamento e substitui
				if(flag)
				{	
					std::cout << '\'' << '\'';
					flag = false;
				}
				else
				{
					std::cout << '`' << '`';
					flag = true;
				}
			}
			// Se nao for aspas, apenas imprime
			else
				std::cout << input[i];
		}
		// Quebra a linha
		std::cout << endl;
	}
	return 0;
}