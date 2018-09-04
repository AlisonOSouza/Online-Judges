/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 4
PROBLEMA:	#5 JDENTIST - Dentista

SOLUÇÃO PROPOSTA:
Neste problema temos uma variação do problema de escalonamento de recursos.
Com isso em mente, utilizei o método de ordenar as tarefas (consultas)
em função do horário de término de cada uma, e após isso, escolher a 
tarefa com menor tempo de término como a próxima a ser executada (desde
que ela não comece antes do último escolhido terminar). Quando escolho
uma tarefa, incremento uma variável que conta a quantidade de tarefas
escolhidas, e no final da execução, imprimo essa variável.
\*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(std::vector< pair<int, int> > v)
{
	unsigned int i;
	for(i = 0; i < v.size(); i++)
		std::cout << v[i].first << " " << v[i].second << endl;
}

bool sortConsulta(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

int main()
{
	int n, initTime, endTime, i, numConsultas;
	std::vector< pair<int, int> > consultas;

	std::cin >> n;

	for(i = 0; i < n; i++)
	{
		std::cin >> initTime >> endTime;
		consultas.push_back(make_pair(initTime, endTime));
	}

	std::sort(consultas.begin(), consultas.end(), sortConsulta);

	initTime = consultas[0].first;
	endTime = consultas[0].second;
	numConsultas = 1;
	for(i = 1; i < n; i++)
	{
		if(consultas[i].first >= endTime)
		{
			initTime = consultas[i].first;
			endTime = consultas[i].second;
			numConsultas++;
		}
	}
	std::cout << numConsultas;

	return 0;
}