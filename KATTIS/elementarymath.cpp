/*
	@problem:	Elementary Math - elementarymath
	@site:		Kattis Problem Archive
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

bool match(long long curr, std::vector< std::vector<long long> >& adj, 
			std::vector<long long>& l, std::vector<long long>& r, 
			std::vector<long long>& vis)
{
	std::vector<long long>::iterator it;

	if(vis[curr]) return false;
	vis[curr] = true;

	for(it = adj[curr].begin(); it != adj[curr].end(); it++)
	{
		if(r[*it] == -1 || match(r[*it], adj, l, r, vis))
		{
			l[curr] = *it;
			r[*it] = curr;
			return true;
		}
	}
	return false;
}

std::vector<long long> bipartite(std::vector< std::vector<long long> >& adj,
								 long long n, long long m)
{
	int i;
	bool works;
	std::vector<long long> left(n, -1), right(m, -1), vis(n);
	
	works = true;
	while(works)
	{
		works = false;
		fill(vis.begin(), vis.end(), 0);
		for(i = 0; i < n; i++)
		{
			if(left[i] == -1)
				works = works | match(i, adj, left, right, vis);
		}
	}
	return left;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	long long n, num1, num2, num3, total, count, i;
	std::vector< pair<long long, long long> > input;
	std::vector<long long>  nodeToNum, matching;
	std::map<long long, long long> numToNode;
	pair<long long, long long> p;

	count = 0;

	std::cin >> n;
	std::vector< std::vector<long long> > adj(n);
	
	for(i = 0; i < n; i++)
	{
		std::cin >> p.first >> p.second;
		input.push_back(p);

		num1 = p.first + p.second;
		if(numToNode.count(num1) == 0)
		{
			numToNode[num1] = count;
			nodeToNum.push_back(num1);
			count++;
		}

		num2 = p.first - p.second;
		if(numToNode.count(num2) == 0)
		{
			numToNode[num2] = count;
			nodeToNum.push_back(num2);
			count++;
		}

		num3 = p.first * p.second;
		if(numToNode.count(num3) == 0)
		{
			numToNode[num3] = count;
			nodeToNum.push_back(num3);
			count++;
		}

		adj[i].push_back(numToNode[num1]);
		adj[i].push_back(numToNode[num2]);
		adj[i].push_back(numToNode[num3]);
	}

	matching = bipartite(adj, n, count);

	total = 0;
	for(i = 0; i < n; i++)
		total += (matching[i] != -1);

	if(total == n)
	{
		for(i = 0; i < n; i++)
		{
			if(input[i].first + input[i].second == nodeToNum[matching[i]])
				std::cout << input[i].first << " + " << input[i].second << " = " << nodeToNum[matching[i]] << endl;
			else if(input[i].first - input[i].second == nodeToNum[matching[i]])
				std::cout << input[i].first << " - " << input[i].second << " = " << nodeToNum[matching[i]] << endl;
			else
				std::cout << input[i].first << " * " << input[i].second << " = " << nodeToNum[matching[i]] << endl;
		}
	}
	else
		std::cout << "impossible" << endl;

	return 0;
}