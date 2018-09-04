/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 5
PROBLEMA:	#8 NATUREZA - Natureza

SOLUÇÃO PROPOSTA:
Neste problema, leio os dois números que representam o número de criaturas
(C) e o número de relações (R). Faço um loop e leio os nomes das criaturas,
salvando seus dados em um map<string, int>. Após isso, faço um laço para
ler as relações e crio um grafo, sendo que cada animal é um vértice e as
relações entre eles são arestas. Após isso, executo uma busca em largura 
em cada vértice do grafo, para procurar a maior cadeia alimentar. Faço 
isso utilizando um vetor para indicar se os vértices já foram visitados 
e qual o tamanho da cadeia que inclui esse vértice, e uma pilha usada 
para indicar quais serão os próximos vértices a ser percorrido pela busca.
Após cada iteração da busca, se o tamanho da cadeia achado nessa iteração
for maior que o salvo anteriormente (o maior até então), atualizo o
tamanho da maior cadeia. Após executar a busca em todos os vértices,
imprimo o tamanho da maior cadeia encontrado.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

typedef vector< vector<int> > grafo_t;

int bfs(grafo_t &g, int start)
{
	int prox, atual, cnt, i;
	vector<int> visitado;
	stack<int> s;

	visitado.resize(g.size(), 0);
	s.push(start);

	visitado[start] = 1;
	cnt = 1;

	while(!s.empty())
	{
		atual = s.top();
		s.pop();

		for(i = 0; i < g[atual].size(); i++)
		{
			prox = g[atual][i];

			if(visitado[prox] == 0)
			{
				visitado[prox] = visitado[atual] + 1;
				s.push(prox);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int cnt, aux, r, c, i;
	string a, b;
	grafo_t grafo;
	map<string, int> mapa;

	while(true)
	{
	    std::cin >> c >> r;
	    if(c == 0 && r == 0) break;
	    
		mapa.clear();
		grafo.clear();
		grafo.resize(c);

		for(i = 0; i < c; i++)
		{
			std::cin >> a;
			mapa.insert(make_pair(a, i));
		}

		for(i = 0; i < r; i++)
		{
			std::cin >> a >> b;
			grafo[mapa[a]].push_back(mapa[b]);
			grafo[mapa[b]].push_back(mapa[a]);
		}

		cnt = 1;
		for(i = 0; i < c; i++)
		{
			aux = bfs(grafo, i);
			if(aux > cnt) cnt = aux;
		}

		std::cout << cnt << endl;
	}

	return 0;
}