/*
	@problem:	Useless Tile Packers - 10065
	@site:		UVa Online Judge
	@author:	Alison Souza

	Para este problema, devemos encontrar o polígono que cobre o azulejo,
	calcular a area do azulejo, calcular a area do poligono e calcular
	a proporção entre as duas areas.
*/

#include <iostream>
#include <cmath> // std::abs()
#include <iomanip> // setprecision()
#include <algorithm> // sort()

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

double polygonArea(t_Point* vec, int n)
{
	int i, j; 
	double area = 0;
	
	for(i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		area += (vec[i].x + vec[j].x) * (vec[i].y - vec[j].y);
	}
	return (area / 2);
}

double crossProduct(const Point &A, const Point &B, const Point &C)
{
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Fonte: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
int convexHull(t_Point* P, int n, t_Point* S)
{
	int i, j, k;

	sort(P, P + n);

	k = 0;
	for(i = 0; i < n; i++)
	{
		while(k >= 2 && crossProduct(S[k-2], S[k-1], P[i]) <= 0)
			k--;
		S[k++] = P[i];
	}
	k--;
	
	j = k;
	for(i = n-1; i >= 0; i--)
	{
		while(k >= j+2 && crossProduct(S[k-2], S[k-1], P[i]) <= 0)
			k--;
		S[k++] = P[i];
	}
	k--;
	
	return k;
}

t_Point P[110], S[110];

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int n, m, i, tile;
	double azulejo, poligono, prop;

	tile = 0;
	while(std::cin >> n && n)
	{
		for(i = 0; i < n; i++)
			std::cin >> P[i].x >> P[i].y;
		
		azulejo = std::abs(polygonArea(P, n));        

		m = convexHull(P, n, S);     
		poligono = std::abs(polygonArea(S, m));
		prop = 100 * (1.0 - (azulejo/poligono));
		
		std::cout << "Tile #" << ++tile << endl;
		std::cout << "Wasted Space = " << fixed << setprecision(2) << prop << " %" << endl;
		std::cout << endl;
	}
	return 0;
}
