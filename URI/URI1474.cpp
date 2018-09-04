/*
	@problem:	Ônibus - 1474
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Multiplica as matrizes A por B e retorna em A.
void multMatrix(long long a[2][2], long long b[2][2])
{
	int i, j, k;
	long long aux[2][2] = {{0}};

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			for(k = 0; k < 2; k++)
				aux[i][j] += ((a[i][k] % 1000000) * (b[k][j] % 1000000)) % 1000000;

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			a[i][j] = aux[i][j] % 1000000;
}

// Eleva a matriz m a potência n e retorna em result.
void powMatrix(long long m[2][2], long long n, long long result[2][2])
{
	result[0][0] = 1;
	result[1][1] = 1;
	result[1][0] = 0;
	result[0][1] = 0;

	while(n > 0)
	{
		if(n%2 == 0)
		{
			multMatrix(m, m);
			n /= 2;
		}
		else
		{
			multMatrix(result, m);
			n--;
		}
	}
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	long long n, k, l;

	while(std::cin >> n >> k >> l)
	{
		long long aux[2][2] = {{0}};
		long long matrizOnibus[2][2] = {{0,l},{1,k}};
		long long result[2][2] = {{1,k},{0,0}};

		powMatrix(matrizOnibus, n/5, aux);
		multMatrix(result, aux);

		std::cout << setfill('0') << setw(6) << result[0][0] << endl;
	}
	return 0;
}
