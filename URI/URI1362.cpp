/*
	@problem:	Minha Camiseta Me Serve - 1362
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <string>

using namespace std;

int tipo[40][2];
int qtde[10];
bool found;
int m;

void calc(int p)
{
	if (p == m + 1)
	{
		found = true;
		return;
	}
	if (found) return;
	
	if (qtde[tipo[p][0]])
	{
		qtde[tipo[p][0]]--;
		calc(p + 1);
		qtde[tipo[p][0]]++;
	}
	if (qtde[tipo[p][1]])
	{
		qtde[tipo[p][1]]--;
		calc(p + 1);
		qtde[tipo[p][1]]++;
	}
}
int val(string s)
{
	if (s == "XS") return 1;
	if (s == "S") return 2;
	if (s == "M") return 3;
	if (s == "L") return 4;
	if (s == "XL") return 5;
	return 6;
}
int main()
{
	int n, numCasos;
	string tam1, tam2; 
	
	cin >> numCasos;
	
	while (numCasos--)
	{
		cin >> n >> m;
		for (int i = 0 ; i < 10; ++i) qtde[i] = n / 6;
		
		for (int i = 1 ; i <= m; ++i)
		{
			cin >> tam1 >> tam2;
			
			tipo[i][0] = val(tam1);
			tipo[i][1] = val(tam2);
		}
		
		found = false;
		calc(1);
	
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}