/*
	@problem:	He is offside! - OFFSIDE
	@site:		SPOJ
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int A, D, i, dist;
	std::vector<int> attacking;
	std::vector<int> defending;

	while(std::cin >> A >> D && A > 0 && D > 0)
	{
		// Limpa os vetores de jogadores.
		attacking.clear();
		defending.clear();
		
		// Lê as distâncias para o gol.
		for(i = 0; i < A; i++)
		{
			std::cin >> dist;
			attacking.push_back(dist);
		}
		for(i = 0; i < D; i++)
		{
			std::cin >> dist;
			defending.push_back(dist);
		}
		
		// Ordena os vetores.
		std::sort(attacking.begin(), attacking.end());
		std::sort(defending.begin(), defending.end());

		// Se o atacante mais próximo do gol, estiver na mesma linha ou
		// mais afastado do gol que o segundo defensor, então não está 
		// impedido. Caso contrário está.
		if(attacking[0] >= defending[1])
			std::cout << "N" << endl;
		else
			std::cout << "Y" << endl;

	}
	return 0;
}