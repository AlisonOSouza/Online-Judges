/*
	@problem:	Bob Laptop Woolmer and Eddie Desktop Barlow - 10072
	@site:		UVa Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define maxN 110

int n, x, y, z;
int f[maxN][8][6][5], trace[maxN][8][6][5];
std::vector<int> resX, resY, resZ;

int roundedNumber(double a)
{
	int res = (int) a;
	if(a - res >= 0.5)
		res++;
	return res;
}

void findResult()
{
	int aux;

	resX.clear();
	resY.clear();
	resZ.clear();
	while(n)
	{
		aux = trace[n][x][y][z];
		if(aux == 1)
		{
			resX.push_back(n);
			x--;
		}
		else if(aux == 2) {
			resY.push_back(n);
			y--;
		}
		else if(aux == 3) {
			resZ.push_back(n);
			z--;
		}
		n--;
	}
	sort(resX.begin(), resX.end());
	sort(resY.begin(), resY.end());
	sort(resZ.begin(), resZ.end());
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int caseNo, bat, bow, fd, next, res, i, xx, yy, zz, vecSize;
	std::vector<int> fx, fy, fz;
	std::vector<bool> okX, okY, okZ;

	caseNo = 1;
	while(std::cin >> n && n)
	{
		fx.clear();
		fx.resize(n+1);
		fy.clear();
		fy.resize(n+1);
		fz.clear();
		fz.resize(n+1);
		okX.clear();
		okX.resize(n+1);
		okY.clear();
		okY.resize(n+1);
		okZ.clear();
		okZ.resize(n+1);

		for(i = 1; i <= n; i++)
		{
			std::cin >> bat >> bow >> fd;
			fx[i] = roundedNumber(0.8 * bat + 0.2 * fd);
			fy[i] = roundedNumber(0.7 * bow + 0.1 * bat + 0.2 * fd);
			fz[i] = roundedNumber(0.4 * bat + 0.4 * bow + 0.2 * fd);
			okX[i] = bat && fd;
			okY[i] = bow && (bat || fd);
			okZ[i] = bow && bat && fd;
		}
		std::cin >> x >> y >> z;
		
		memset(f, 0, sizeof(f));
		for(i = 1; i <= n; i++)
		{
			for(xx = 0; xx <= x + 1; xx++)
			{
				for(yy = 0; yy <= y + 1; yy++)
				{
					for(zz = 0; zz <= z + 1; zz++)
					{
						int &cur = f[i][xx][yy][zz];
						trace[i][xx][yy][zz] = 0;
						cur = f[i - 1][xx][yy][zz];
						if(xx > 0 && okX[i])
						{
							next = f[i - 1][xx - 1][yy][zz] + fx[i];
							if(next > cur)
							{
								cur = next;
								trace[i][xx][yy][zz] = 1;
							}
						}
						if(yy > 0 && okY[i])
						{
							next = f[i - 1][xx][yy - 1][zz] + fy[i];
							if(next > cur)
							{
								cur = next;
								trace[i][xx][yy][zz] = 2;
							}
						}
						if(zz > 0 && okZ[i])
						{
							next = f[i - 1][xx][yy][zz - 1] + fz[i];
							if(next > cur)
							{
								cur = next;
								trace[i][xx][yy][zz] = 3;
							}
						}
					}
				}
			}
		}
		
		res = f[n][x][y][z];
		findResult();
		if(caseNo > 1)
			std::cout << endl;
		
		std::cout << "Team #" << caseNo++ << endl;
		std::cout << "Maximum Effective Score = " << res << endl;
		std::cout << "Batsmen : ";
		
		vecSize = (resX.size() - 1);
		for(i = 0; i < vecSize; i++)
			std::cout << resX[i] << " ";
		std::cout << resX[vecSize] << endl << "Bowlers : ";

		vecSize = (resY.size() - 1);
		for(i = 0; i < vecSize; i++)
			std::cout << resY[i] << " ";
		std::cout << resY[vecSize] << endl << "All-rounders : ";

		vecSize = (resZ.size() - 1);
		for(i = 0; i < vecSize; i++)
			std::cout << resZ[i] << " ";
		std::cout << resZ[vecSize] << endl;
	}
	return 0;
}
