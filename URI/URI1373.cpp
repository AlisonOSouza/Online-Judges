/*
	@problem:	Sequências de DNA - 1373
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>

#define MAX 1001

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int k, aux, kmax, suffix, i, j, a_size, b_size;
	int m[MAX][MAX];
	string a, b;

	for(i = 0; i < MAX; i++)
	{
		m[0][i] = 0;
		m[i][0] = 0;
	}

	while(std::cin >> k && k > 0)
	{
		std::cin >> a >> b;

		a_size = a.size();
		b_size = b.size();

		for(j = 1; j <= b_size; j++)
		{
			for(i = 1; i <= a_size; i++)
			{
				if(a[i - 1] == b[j - 1])
					m[j][i] = m[j - 1][i - 1] + 1;
				else
					m[j][i] = 0;
			}
		}

		for(j = 1; j <= b_size; j++)
		{
			for(i = 1; i <= a_size; i++)
			{
				aux = max(m[j][i - 1], m[j - 1][i]);
				kmax = m[j][i];
				for(suffix = k; suffix <= kmax; suffix++)
					aux = max(aux, m[j - suffix][i - suffix] + suffix);
				m[j][i] = aux;
			}
		}
		std::cout << m[b_size][a_size] << endl;
	}
	return 0;
}
