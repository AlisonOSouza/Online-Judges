/*
	@problem:	Tour - 1347
	@site:		UVa Online Judge
	@author:	Alison Souza

	Caixeiro viajante...
*/

#include <iostream>
#include <cmath> // hypot()
#include <vector>
#include <iomanip> // setprecision()

using namespace std;

#define MAX_N 100
#define INF 0x3F3F3F3F

typedef struct Point
{
	double x, y;
} t_Point;

double dp[MAX_N][MAX_N];
std::vector<t_Point> points;

double min(double a, double b)
{
	return (a < b) ? a : b;
}

double dist(t_Point p1, t_Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double rec(int a, int b)
{
	int i;
	double opt;

	if(a == 0 && b == 0)
		return 0;

	if(dp[a][b] < INF)
		return dp[a][b];
	
	if(a < b -1)
		return rec(a, b -1) + dist(points[b-1], points[b]);
	
	opt = INF;
	for(i = 0; i < b; i++)
		opt = min(opt, rec(i, a) + dist(points[i], points[b]));

	dp[a][b] = opt;

	return opt;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, i, j;
	t_Point p;

	while(std::cin >> N)
	{
		points.clear();
		for(i = 0; i < N; i++)
		{
			std::cin >> p.x >> p.y;
			points.push_back(p);

			for(j = 0; j < N+1; j++)
				dp[i][j] = INF;
		}
		std::cout << fixed << setprecision(2) << rec(N-1, N-1) << endl;
	}
	return 0;
}