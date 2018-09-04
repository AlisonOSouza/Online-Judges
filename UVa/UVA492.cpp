/*
	@problem:	Pig-Latin - 492
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

bool isLetter(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}

bool isVowel(char c)
{
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
		|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	unsigned int i, j;
	string line, word, word2;

	// Le a linha
	while(getline(cin, line))
	{
		// Percorre os caracteres
		for(i = 0; i < line.size(); i++)
		{
			// Se e' letra junta numa palavra
			if(isLetter(line[i]))
				word.push_back(line[i]);
			// Se nao e' letra, entao formou uma palavra
			else
			{
				// Se nao for vazia e comecar com vogal
				if(!word.empty() && isVowel(word[0]))
				{
					// Acrescenta o "ay" e imprime
					word.append("ay");
					std::cout << word;
				}
				// Se nao for vazia e comecar com consoante
				else if(!word.empty())
				{
					for(j = 1; j < word.size(); j++)
						std::cout << word[j];
					std::cout << word[0] << "ay";

				}
				// Limpa a string
				word.clear();
				// Imprime os outros caracteres
				std::cout << line[i];
			}
		}
		std::cout << endl;
	}
	return 0;
}