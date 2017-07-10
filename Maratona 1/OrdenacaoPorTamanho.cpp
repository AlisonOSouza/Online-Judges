#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct word
{
	string pal;
	int tam;
	int pos;
} word_t;

bool compare(word_t a, word_t b)
{
	if(a.tam > b.tam) return true;
	else if(a.tam == b.tam && a.pos < b.pos) return true;
	else return false;
}


int main()
{
	int i, n, num_palavras;
	string linha;
	vector<word_t> palavra(50);
	
	std::cin >> n;
	std::cin.ignore(1, '\n');
	
	while(n > 0)
	{
		getline(std::cin, linha);
		i = 0;
		std::istringstream iss(linha);
		while(getline(iss, palavra[i].pal, ' '))
		{
			palavra[i].pos = i;
			palavra[i].tam = palavra[i].pal.size();
			i++;
		}
		num_palavras = i;
		
		std::sort(palavra.begin(), palavra.begin() + num_palavras, compare);

		for(i = 0; i < num_palavras; i++)
		{
			std::cout << palavra[i].pal;
			if(i < num_palavras-1)
			    std::cout << " ";
		}
		n--;
		std::cout << endl;
	}

	return 0;
}
