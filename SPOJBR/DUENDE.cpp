/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 5
PROBLEMA:	#7 DUENDE - Duende Perdido

SOLUÇÃO PROPOSTA:
Neste problema, leio os números N e M que representam o tamanho da matriz
e em seguida leio a matriz. Para buscar a quantidade mínima de salões
para sair da caverna, faço uma busca em largura na matriz, partindo do
ponto onde o duende está. Para isso, uso outra matriz para indicar quais
salões já foram visitados, e uma fila de pares para indicar qual a ordem
de visita dos salões. A cada iteração da busca, caso ache o valor que 
indica saída (0) retorno a distância do salão atual até o salão de partida,
caso não ache o valor, leio o próximo salão da fila e atribuo a ele a
distância do salão anterior + 1, e continuo iterando até achar uma saída
(assumo que sempre haverá saídas).
\*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef vector< vector<int> > matriz_t;

int bfs(matriz_t mat, int init_x, int init_y, int n, int m)
{
	int i;
	pair<int, int> p;
	queue< pair<int, int> > fila;
	vector< vector<int> > visitados;

	visitados.resize(n);
	for(i = 0; i < n; i++)
		visitados[i].resize(m, 0);	

	visitados[init_x][init_y] = 0;
	mat[init_x][init_y] = 1;

	fila.push(make_pair(init_x, init_y));

	while(!fila.empty())
	{
		p = fila.front();
		fila.pop();

		if((p.first-1) >= 0 && (p.first-1) < n && p.second >= 0 && p.second < m)
		{
			if(mat[p.first-1][p.second] == 1 && visitados[p.first-1][p.second] == 0)
			{
				visitados[p.first-1][p.second] = visitados[p.first][p.second] + 1;
				fila.push(make_pair(p.first-1, p.second));
				mat[p.first-1][p.second] = mat[p.first][p.second] + 1;
			}
			else if(mat[p.first-1][p.second] == 0)
			{
				return visitados[p.first][p.second] + 1;
			}
		}

		if((p.first+1) >= 0 && (p.first+1) < n && p.second >= 0 && p.second < m)
		{
			if(mat[p.first+1][p.second] == 1 && visitados[p.first+1][p.second] == 0)
			{
				visitados[p.first+1][p.second] = visitados[p.first][p.second] + 1;
				fila.push(make_pair(p.first+1, p.second));
				mat[p.first+1][p.second] = mat[p.first][p.second] + 1;
			}
			else if(mat[p.first+1][p.second] == 0)
			{
				return visitados[p.first][p.second] + 1;
			}
		}
		
		if(p.first >= 0 && p.first < n && (p.second-1) >= 0 && (p.second-1) < m)
		{
			if(mat[p.first][p.second-1] == 1 && visitados[p.first][p.second-1] == 0)
			{
				visitados[p.first][p.second-1] = visitados[p.first][p.second] + 1;;
				fila.push(make_pair(p.first, p.second-1));
				mat[p.first][p.second-1] = mat[p.first][p.second] + 1;
			}
			else if(mat[p.first][p.second-1] == 0)
			{
				return visitados[p.first][p.second] + 1;
			}
		}
		
		if(p.first >= 0 && p.first < n && (p.second+1) >= 0 && (p.second+1) < m)
		{
			if(mat[p.first][p.second+1] == 1 && visitados[p.first][p.second+1] == 0)
			{
				visitados[p.first][p.second+1] = visitados[p.first][p.second] + 1;;
				fila.push(make_pair(p.first, p.second+1));
				mat[p.first][p.second+1] = mat[p.first][p.second] + 1;
			}
			else if(mat[p.first][p.second+1] == 0)
			{
				return visitados[p.first][p.second] + 1;
			}
		}
	}
}

int main()
{
	int n, m, init_x, init_y, aux, i, j;
	matriz_t mat;

	std::cin >> n >> m;

	mat.resize(n);
	for(i = 0; i < n; i++)
		mat[i].resize(m, 0);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			std::cin >> aux;
			if(aux == 3)
			{
				init_x = i;
				init_y = j;
			}
			mat[i][j] = aux;
		}
	}

	aux = bfs(mat, init_x, init_y, n, m);
	cout << aux << endl;

	return 0;
}