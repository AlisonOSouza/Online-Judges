/*
	@problem:	Mutant Flatworld Explorers - 118
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int xGrid, yGrid, xRobot, yRobot, i;
	char orient;
	string instruct;
	int grid[52][52];
	bool lost;

	std::cin >> xGrid >> yGrid;
	
	// Enquanto houver robos na entrada
	while(std::cin >> xRobot >> yRobot >> orient >> instruct)
	{
		// Marco o robo como nao perdido.
		lost = false;
		
		// Percorro a lista de instrucoes.
		for(i = 0; i < instruct.size(); i++)
		{
			// Se a instrucao for para andar
			if(instruct[i] == 'F')
			{
				if(orient == 'N') yRobot++;
				else if(orient == 'S') yRobot--;
				else if(orient == 'E') xRobot++;
				else if(orient == 'W') xRobot--;
			}
			// Se for pra virar a direita
			else if(instruct[i] == 'R')
			{
				if(orient == 'N') orient = 'E';
				else if(orient == 'S') orient = 'W';
				else if(orient == 'E') orient = 'S';
				else if(orient == 'W') orient = 'N';
			}
			// Se for pra andar a esquerda
			else if(instruct[i] == 'L')
			{
				if(orient == 'N') orient = 'W';
				else if(orient == 'S') orient = 'E';
				else if(orient == 'E') orient = 'N';
				else if(orient == 'W') orient = 'S';
			}
			// Se o robo caiu do grid
			if(xRobot < 0 || xRobot > xGrid || yRobot < 0 || yRobot > yGrid)
			{
				// Volto pra ultima posição antes da queda
				if(orient == 'N') yRobot--;
				else if(orient == 'S') yRobot++;
				else if(orient == 'E') xRobot--;
				else if(orient == 'W') xRobot++;

				// E marco como caido se ninguem tinha caido neste lugar
				// Se alguem ja tinha caido, passa direto.
				if(grid[xRobot][yRobot] != 1)
				{
					lost = true;
					grid[xRobot][yRobot] = 1;
					break;
				}
			}
		}
		if(lost)
			std::cout << xRobot << " " << yRobot << " " << orient << " LOST" << endl;
		else
			std::cout << xRobot << " " << yRobot << " " << orient << endl;
	}
	return 0;
}