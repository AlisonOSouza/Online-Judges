/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 5
PROBLEMA:	#4 PEDAGIO - Pedágio

SOLUÇÃO PROPOSTA:
Para este problema, crio um grafo bidirecionado onde os vértices são as
cidades do país e as arestas são as estradas que ligam cada par de cidades,
com cada aresta tendo peso igual a 1. Após criar o grafo, executo uma
busca em largura a partir da cidade onde Juquinha está, cuidando do custo
máximo de pedágio que podem pagar. Para isso, uso uma fila onde insiro
as possíveis cidades que Juquinha pode visitar. Insiro inicialmente a
cidade C, onde Juquinha está, nessa fila e verifico as cidades que tem
estradas até C, inserindo-as na lista de resultado e na fila. Continuo 
iterando na fila, marcando qual cidade já foi visitada até que a fila
esteja vazia ou que o custo máximo seja atigido. Nesse ponto, imprimo
o vetor de cidades que podem ser visitados por Juquinha.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > grafo_t;

void bfs(grafo_t grafo, int start, int custo)
{
	int atual, prox, i, custo_atual, tam_flia, num_result;
	std::queue<int> fila;
	std::vector<int> visitado;
	std::vector<int> resultado;

	visitado.resize(grafo.size(), 0);
	resultado.resize(grafo.size(), 0);
	fila.push(start);
	visitado[start] = 1;

	custo_atual = 0;
	num_result = 0;
	while(!fila.empty() && custo_atual < custo)
	{
		tam_flia = fila.size();
		while(tam_flia > 0)
		{
			atual = fila.front();
			fila.pop();

			for(i = 0; i < grafo[atual].size(); i++)
			{
				if(grafo[atual][i] == 1) 
					prox = i;
				else
					continue;

				if(resultado[prox] != 1)
				{	
					resultado[prox] = 1;
					num_result++;
				}

				if(visitado[prox] == 0)
				{
					visitado[prox] = 1;
					fila.push(prox);
				}
			}
			tam_flia--;
		}
		custo_atual++;
	}

	resultado[start] = 0;

	for(i = 0; i < resultado.size(); i++)
	{
		if(resultado[i] == 1)
		{
			std::cout << i+1;
			num_result--;
			if(num_result > 0) std::cout << " ";
		}
	}
	std::cout << endl;
}

int main()
{
	int c, e, l, p, c1, c2, i, j;
	grafo_t grafo;

	std::cin >> c >> e >> l >> p;
	j = 1;
	while(c > 0 && e > 0 && l > 0 && p > 0)
	{
		grafo.clear();
		grafo.resize(c);
		for(i = 0; i < c; i++)
			grafo[i].resize(c, 0);
	
		while(e > 0)
		{
			std::cin >> c1 >> c2;

			grafo[c1-1][c2-1] = 1;
			grafo[c2-1][c1-1] = 1;
			
			e--;
		}

		std::cout << "Teste " << j << endl;

		bfs(grafo, l-1, p);
		
		j++;
		std::cin >> c >> e >> l >> p;
		if(c > 0 && e > 0 && l > 0 && p > 0) std::cout << endl;
	}

	return 0;
}