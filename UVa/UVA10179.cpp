/*
	@problem:	Irreducable Basic Fractions - 10179
	@site:		UVa Online Judge
	@author:	Alison Souza

	Para esse problema, basta aplicar a função totiente de Euler:
	https://en.wikipedia.org/wiki/Euler%27s_totient_function
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define HIGHERBOUND 1000000000
#define ROOT 31622 // É a sqrt(HIGHERBOUND).

// Vetor que indica números primos.
std::vector<bool> isPrime(ROOT + 1, true);
// Vetor de números primos.
std::vector<int> primes;

// Encontra números primos até um limite superior.
void crivoEratostenes()
{
	int i, j;

	// Percorre os números de 2 até a raiz do limite superior, que é o
	// maior número a ser checado.
	for(i = 2; i <= ROOT; i++)
	{
		// Se está marcado como primo.
		if(isPrime[i])
		{
			// Percorre os multiplos de 'i' marcando como não primo.
			for(j = i * i; j <= ROOT; j += i)
				isPrime[j] = false;
			// Insere no vetor de primos.
			primes.push_back(i);
		}
	}
}

int totienteEuler(int n)
{
	int i, coPrime;
	coPrime = n;

	// Percorre a lista de primos.
	for(i = 0; i < primes.size(); i++)
	{
		// Se o primo[i] é menor que 'n', e o mod de de 'n' por ele é 0. 
		if((primes[i] <= n) && (n % primes[i] == 0))
		{
			// Então encontra os fatores primos distintos de 'n' e 
			// aplica a fórmula do produto de Euler.
			while(n % primes[i] == 0)
				n /= primes[i];
			coPrime *= (1.0 - 1.0 / primes[i]);
		}
	}
	if(n > 1)
		coPrime *= (1.0 - 1.0 / n);
	return coPrime;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n;

	crivoEratostenes();

	while(std::cin >> n && n != 0)
		std::cout << totienteEuler(n) << endl;
	
	return 0;
}
