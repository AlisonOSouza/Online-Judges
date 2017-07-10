/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 5
PROBLEMA:	#1 IREVIR - Ir e vir

SOLUÇÃO PROPOSTA:
Neste problema, leio o número de interseções e o número de ruas e crio
um laço para poder ler cada rua, verificando se a rua é de mão dupla ou
não. Salvo os dados num grafo (matriz de adjacência), sendo os cruzamentos
os vértices e ruas as arestas, e executo uma busca em largura em cada 
vérice verificando se é possível acessar todos os outros vértices. Se não
for possível visitar todos os vértices, a busca retorna falso e então 
imprimo 0. Caso seja possível, continuo realizando buscas nos próximos
vértices até que acabe o número de vértices. Nesse ponto, imprimo 1.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > grafo_t;

bool bfs(grafo_t grafo, int start)
{
	int atual, prox, i;
	std::queue<int> fila;
	std::vector<int> visitado;

	visitado.resize(grafo.size(), 0);
	fila.push(start);

	while(!fila.empty())
	{
		atual = fila.front();
		fila.pop();

		for(i = 0; i < grafo[atual].size(); i++)
		{
			if(grafo[atual][i] == 1) 
				prox = i;
			else
				continue;
			if(visitado[prox] == 0)
			{
				visitado[prox] = 1;
				fila.push(prox);
			}
		}
	}

	for(i = 0; i < visitado.size(); i++)
	{
		if(visitado[i] == 0)
			return false;
	}
	return true;

}

int main()
{
	int v, e, v1, v2, p, i;
	grafo_t grafo;

	std::cin >> v >> e;
	while(v > 0 && e > 0)
	{
		grafo.clear();
		grafo.resize(v);
		for(i = 0; i < v; i++)
			grafo[i].resize(v, 0);
	
		while(e > 0)
		{
			std::cin >> v1 >> v2 >> p;

			grafo[v1-1][v2-1] = 1;
			if(p == 2)
			{
				grafo[v2-1][v1-1] = 1;
			}

			e--;
		}

		bool flag = true;
		for(i = 0; i < v; i++)
		{
			flag = bfs(grafo, i);
			if(!flag)
			{
				std::cout << 0;
				break;
			}
		}
		if(flag) std::cout << 1;

		std::cin >> v >> e;
		if(v > 0 && e > 0) std::cout << endl;
	}

	return 0;
}