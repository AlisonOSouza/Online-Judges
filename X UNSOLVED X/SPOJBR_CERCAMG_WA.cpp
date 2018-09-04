/*
	@problem:	Cercadinho de Plantas - CERCAMG
	@site:		SpojBR
	@author:	Alison Souza

	WRONG ANSWER
	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

double distancePitagoras(t_Point a, t_Point b)
{
	return sqrt(((a.x-b.x) * (a.x-b.x)) + ((a.y-b.y) * (a.y-b.y)));
}

void printPoints(std::vector<t_Point> P)
{
	for(int i = 0; i < P.size(); ++i)
		std::cout << "(" << P[i].x << ", " << P[i].y << ")" << endl;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int A, D, i;
	double resp;
	t_Point pnt;
	std::vector<t_Point> trees;
	std::vector<t_Point> convex_hull;

	while(std::cin >> A >> D)
	{
		trees.clear();
		convex_hull.clear();

		for(i = 0; i < A; i++)
		{
			std::cin >> pnt.x >> pnt.y;
			trees.push_back(pnt);
		}

		convex_hull = convexHull(trees, trees.size());
		printPoints(convex_hull);

		resp = 0;
		for(i = 1; i < convex_hull.size(); i++)
			resp += distancePitagoras(convex_hull[i-1], convex_hull[i]);

		resp += distancePitagoras(convex_hull[0], convex_hull[convex_hull.size()-1]);

		std::cout << fixed << setprecision(2) << resp << endl;
	}
	return 0;
}
