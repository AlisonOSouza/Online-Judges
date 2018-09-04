/*
	@problem:	Power Crisis - 151
	@site:		UVa
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>

using namespace std;

bool make13Last(int m, int n)
{
	int i, j, cnt;
	// Vetor de n+1 posicoes, pra indicar se passou por todos os numeros.
	std::vector<bool> aux(n+1, false);

	i = 1;
	cnt = 0;

	// Enquanto o numero 13 nao foi visitado
	while(aux[13] == false)
	{
		// Faz o mod, se necessario.
		if(i > n)
			i -= n;

		// Se o numero ainda nao foi visitado,
		if(aux[i] == false)
		{
			// Se cnt for igual a 'm', significa que andamos 'm' vezes no
			// vetor aux (somamos 'm' ao indice anterior).
			if(cnt == m)
			{
				aux[i] = true;
				cnt = 0;
			}
			// Incrementa a posicao do vetor e o contador de passos.
			i++;
			cnt++;
			aux[1] = true;
		}
		// Se já foi visitado, apenas passa pro proximo.
		else
			i++;
	}

	// Percorre o vetor para verificar se visitou todos os numeros.
	for(j = 1; j <= n; j++)
	{
		// Se ainda tem algum numero depois do 13, retorna falso.
		if(aux[j] == false)
			return false;
	}
	// Se visitou todos os numeros, retorna veraddeiro.
	return true;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, m;
	
	// Lê a entrada, equanto for maior que zero.
	while(std::cin >> n && n > 0)
	{
		// Percorre os numeros de 1 a 'n' para procurar um numero 'm' que
		// garanta que o 13 sera o ultimo da lista.
		for(m = 1; m < n; m++)
		{
			// Chama a funcao que verifica se 'm' cumpre os requisitos.
			if(make13Last(m, n))
			{
				// Se cumprir, imprime 'm' e para o loop.
				std::cout << m << endl;
				break;
			}
		}
	}
	return 0;
}