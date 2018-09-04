/*
	@problem:	Network - 315
	@site:		UVa Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

static const int UNVISITED = 0;

vector< vector<int> > network;
int dfsRoot;
int rootChildren;
int dfsCounter = 1;
vector<int> dfsNum;
vector<int> dfsLow;
vector<int> dfsParent;
vector<bool> artiVertices; 

void DFS(int u)
{
	int i, v;
	dfsNum[u] = dfsLow[u] = dfsCounter++;
	for (i = 0; i < network[u].size(); ++i)
	{
		v = network[u][i];
		if (dfsNum[v] == UNVISITED)
		{
			dfsParent[v] = u;
			if (u == dfsRoot)
				rootChildren++;
			DFS(v);

			if (u != dfsRoot && dfsLow[v] >= dfsNum[u])
				artiVertices[u] = true;

			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		}

		else if (v != dfsParent[u]) 
			dfsLow[u] = min(dfsLow[u], dfsNum[v]); 
	}
}

int main(int argc, char* argv[])
{  
	int n, u, v, p;
	while (std::cin >> n, n != 0)
	{
		std::cin.ignore();

		network.clear();
		network.resize(n + 1);
		dfsNum.clear();
		dfsNum.resize(n + 1, UNVISITED);
		dfsLow.clear();
		dfsLow.resize(n + 1, UNVISITED);
		dfsParent.clear();
		dfsParent.resize(n + 1, UNVISITED);

		artiVertices.clear();
		artiVertices.resize(n + 1, false);

		string s;
		while (getline(std::cin, s), s != "0")
		{
			stringstream ss(s);
			ss >> u;
			while (ss >> v)
			{
				network[u].push_back(v);
				network[v].push_back(u);
			}
		}
		for (p = 1; p < network.size(); ++p)
		{
			if (dfsNum[p] == UNVISITED)
			{
				dfsRoot = p;
				rootChildren = 0;
				DFS(p);
				if (rootChildren > 1)
					artiVertices[dfsRoot] = true;
			}
		}
		std::cout << count(artiVertices.begin(), artiVertices.end(), true) << endl;
	}
	return 0;
}