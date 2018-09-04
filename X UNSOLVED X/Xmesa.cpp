#include <iostream>
#include <vector>
//#include <set>

using namespace std;

int main()
{
	int v, e, v1, v2, i, flag;
	vector<int> ladoA, ladoB;

	std::cin >> v >> e;
	i = 1;
	while(cin)
	{
		ladoA.clear();
		ladoA.resize(v+1, 0);
		ladoB.clear();
		ladoB.resize(v+1, 0);
				
		flag = 0;
		while(e > 0)
		{
			std::cin >> v1 >> v2;

			if(ladoA[v1] == 0 && ladoB[v1] == 0 && flag == 0)
			{
				if((ladoA[v2] == 0 && ladoB[v2] == 0) ||
					(ladoA[v2] == 0 && ladoB[v2] == 1))
				{
					ladoA[v1] = 1;
					ladoB[v2] = 1;
					std::cout << "passo 1:" << v1 << " " << v2 << endl;
				}
				else if(ladoA[v2] == 1 && ladoB[v2] == 0)
				{
					ladoB[v1] = 1;
					std::cout << "passo 2:" << v1 << " " << v2 << endl;
				}
				else
				{
					flag = 1;
					std::cout << "passo 3:" << v1 << " " << v2 << endl;
					//break;
				}
			}
			else if(ladoA[v1] == 0 && ladoB[v1] == 1 && flag == 0)
			{
				if(ladoA[v2] == 0 && ladoB[v2] == 0)
				{
					ladoA[v2] == 1;
					std::cout << "passo 4:" << v1 << " " << v2 << endl;
				}
				else
				{
					flag = 1;
					std::cout << "passo 5:" << v1 << " " << v2 << endl;
					//break;
				}

			}
			else if(ladoA[v1] == 1 && ladoB[v1] == 0 && flag == 0)
			{
				if(ladoB[v2] == 0 && ladoA[v2] == 0)
				{
					ladoB[v2] == 1;
					std::cout << "passo 6:" << v1 << " " << v2 << endl;
				}
				else
				{
					flag = 1;
					std::cout << "passo 7:" << v1 << " " << v2 << endl;
					//break;
				}
			}
			else
			{
				flag = 1;
				std::cout << "passo 8:" << v1 << " " << v2 << endl;
			}

			e--;
		}

		std::cout << "Instancia " << i << endl;
		if(flag == 1) std::cout << "nao" << endl;
		else std::cout << "sim" << endl;

		std::cout << "LA: ";
		for(i = 0; i < v+1; i++)
		{
			std::cout << ladoA[i] << " ";
		}
		std::cout << endl << "LB: ";
		for(i = 0; i < v+1; i++)
		{
			std::cout << ladoB[i] << " ";
		}
		std::cout << endl;

		i++;
		std::cin >> v >> e;
		if(v > 0 && e > 0) std::cout << endl;
	}

	return 0;
}