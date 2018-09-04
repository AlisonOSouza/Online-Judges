/*
	@problem:	Cercadinho de Plantas - CERCAMG
	@site:		SpojBR
	@author:	Alison Souza
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct Point
{
	int x, y;
} t_Point;

double distancePitagoras(t_Point a, t_Point b)
{
	return sqrt(((a.x-b.x) * (a.x-b.x)) + ((a.y-b.y) * (a.y-b.y)));
}

// Retorna a orientação dos pontos(p, q, r);
// 0 - colineares
// 1 - Horario
// 2 - Anti-Horario
int orientation(t_Point a, t_Point b, t_Point c)
{
	int orient = ((b.y - a.y) *(c.x - b.x) -(b.x - a.x) *(c.y - b.y));

	if(orient == 0)
		return 0;
	else if(orient > 0)
		return 1;
	else
		return 2;
}

std::vector<t_Point> convexHull(std::vector<t_Point> P, int N)
{
	int start, p, q, i;
	std::vector<bool> used(N, false);
	std::vector<t_Point> ret;

	// Necessario no minimo três pontos;
	if(N < 3)
		return ret;

	p = 0;
	for(i = 1; i < N; i++)
	{
		if(P[p].x > P[i].x)
			p = i;
	}

	start = p;
	do
	{
		q = (p + 1) % N;

		for(i = 0; i < N; i++)
		{
			if(!used[i] && orientation(P[p], P[i], P[q]) == 2)
				q = i;
		}

		ret.push_back(P[q]);
		used[q] = 1;
		p = q;
	} while(start != p);

	return ret;
}

// void printPoints(std::vector<t_Point> P)
// {
// 	for(int i = 0; i < P.size(); ++i)
// 		std::cout << "(" << P[i].x << ", " << P[i].y << ")" << endl;
// }

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
		// printPoints(convex_hull);

		resp = 0;
		for(i = 1; i < convex_hull.size(); i++)
			resp += distancePitagoras(convex_hull[i-1], convex_hull[i]);

		resp += distancePitagoras(convex_hull[0], convex_hull[convex_hull.size()-1]);

		std::cout << fixed << setprecision(2) << resp << endl;
	}
	return 0;
}
