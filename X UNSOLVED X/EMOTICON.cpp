/*
	@problem:	Emoticons - EMOTICON
	@site:		SPOJ
	@author:	Alison Souza

	AINDA TEM ERROS...
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, M, i, j, changes;
	string emot, line;
	std::vector<string> emoticons;
	std::size_t pos, emot_size;

	while(std::cin >> N >> M && N > 0 && M > 0)
	{
		emoticons.clear();
		changes = 0;

		for(i = 0; i < N; i++)
		{
			std::cin >> emot;
			emoticons.push_back(emot);
		}

		cin.ignore(); // Descartando o "\n" após ler o último emoticon.
		for(i = 0; i < M; i++)
		{
			std::getline(std::cin, line);
			for(j = 0; j < emoticons.size(); j++)
			{
				while((pos = line.find(emoticons[j])) && (pos != string::npos))
				{
					emot_size = emoticons[j].length();
					line.replace(line.begin()+pos, line.begin()+pos+emot_size, " ");
					changes++;
				}
			}
		}

		std::cout << changes << endl;
	}
	return 0;
}