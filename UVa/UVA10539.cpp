/*
	@problem:	Almost Prime Numbers - 10539 
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define HIGHERBOUND 1000000000000
#define ROOT 1000000

using namespace std;

// Vetor que indica números não primos.
std::vector<bool> isPrime(ROOT + 1, true);
// Vetor de números primos.
std::vector<unsigned long long> primes;

// Encontra números primos até um limite superior.
void crivoEratostenes()
{
	unsigned long long i, j;

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

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n;
	unsigned long long low, high, i, j;
	std::vector<unsigned long long> vec;
	std::vector<unsigned long long>::iterator it1, it2;

	// Gera o vetor de números primos.
	crivoEratostenes();

	// Preenche o vetor de almost primes.
	for(i = 0; i < primes.size(); i++)
	{
		for(j = primes[i] * primes[i]; j <= HIGHERBOUND; j *= primes[i])
			vec.push_back(j);
	}

	sort(vec.begin(), vec.end());

	std::cin >> n;
	while(n--)
	{
		std::cin >> low >> high;
		it1 = upper_bound(vec.begin(), vec.end(), high);
		it2 = lower_bound(vec.begin(), it1, low);
		std::cout << it1 - it2 << endl;
	}
	return 0;
}
