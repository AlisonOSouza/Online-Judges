#include <iostream>

using namespace std;

typedef struct williPoint
{
	int x;
	int y;
} wPoint_t;

wPoint_t majaCoord(int n)
{
	int i, v;
	wPoint_t p;

	p.x = 0;
	p.y = 0;
	v = 0;
	while(true)
	{
		if(n == 1) return p;

		v++, p.y++, n--;

		if(n == 1) return p;

		for(i = 0; i < (v-1); i++)
		{
			p.x--;
			p.y++;
			if(--n == 1) return p;
		}

		for(i = 0; i < v; i++)
		{
			p.x--;
			if(--n == 1) return p;
		}

		for(i = 0; i < v; i++)
		{
			p.y--;
			if(--n == 1) return p;
		}

		for(i = 0; i < v; i++)
		{
			p.x++;
			p.y--;
			if(--n == 1) return p;
		}

		for(i = 0; i < v; i++)
		{
			p.x++;
			if(--n == 1) return p;
		}

		for(i = 0; i < v; i++)
		{
			p.y++;
			if(--n == 1) return p;
		}
	}
}

int main()
{
	int n;
	wPoint_t p;

	while(std::cin >> n)
	{
		p = majaCoord(n);
		std::cout << p.x << " " << p.y << endl;
	}
	return 0;
}