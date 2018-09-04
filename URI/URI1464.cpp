/*
	@problem:	Camadas de Cebola (Onions Layers) - 1464
	@site:		URI Online Judge
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <algorithm> // std::sort()
#include <set>

using namespace std;

typedef struct Point
{
	int x, y;
} t_Point;

bool operator <(const t_Point p, const t_Point q)
{
	if (p.x != q.x)
		return (p.x < q.x);
	else
		return (p.y < q.y);
}

int crossProduct(const Point &A, const Point &B, const Point &C)
{
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Fonte: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
std::vector<t_Point> convexHull(std::vector<t_Point> P, int n)
{
	int i, j, k;
	std::vector<t_Point> S(2*n);

	std::sort(P.begin(), P.end());

	k = 0;
	for(i = 0; i < n; i++)
	{
		while(k >= 2 && crossProduct(S[k-2], S[k-1], P[i]) < 0)
			k--;
		S[k++] = P[i];
	}
	
	j = k + 1;
	for(i = n-2; i >= 0; i--)
	{
		while(k >= j && crossProduct(S[k-2], S[k-1], P[i]) < 0)
			k--;
		S[k++] = P[i];
	}
	
	S.resize(k);
	return S;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, i, layers;
	t_Point pnt;
	std::vector<t_Point> points;

	while(std::cin >> N && N)
	{
		points.clear();

		for(i = 0; i < N; i++)
		{
			std::cin >> pnt.x >> pnt.y;
			points.push_back(pnt);
		}

		layers = 0;
		while(points.size())
		{
			std::vector<t_Point>::iterator it;
			std::vector<t_Point> convex_hull;
			std::vector<t_Point> aux;
			std::set<t_Point> seen;

			convex_hull = convexHull(points, points.size());

			layers++;

			for (it = convex_hull.begin(); it != convex_hull.end(); it++)
				seen.insert(*it);

			for (it = points.begin(); it != points.end(); it++)
			{
				if(!seen.count(*it))
					aux.push_back(*it);
			}
			points = aux;
		}

		if(layers % 2 == 1)
			std::cout << "Take this onion to the lab!" << endl;
		else
			std::cout << "Do not take this onion to the lab!" << endl;
	}
	return 0;
}
