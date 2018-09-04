/*
	@problem:	Ant on a Chessboard - 10161
	@site:		UVa
	@author:	Alison Souza

	Esse problema trabalha com valores altos, o que impossibilita a 
	utilizacao de uma solucao por forca bruta. Assim, verificamos que
	sempre que N é um quadrado perfeito (1, 4, 9, 16, ...), a formiga está
	em uma quina, ou andando para a direita e depois para baixo (se a raiz
	for impar), ou entao andando para cima e depois esquerda (se a raiz 
	for par). Dai para frente, podemos tentar 'caminhar' com a formiga ate
	chegar no ponto desejado.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	long long n, root, x, y, prev, up, down, right, left;

	while(std::cin >> n && n > 0)
	{
		// Calcula a raiz mais proxima de 'n'
		root = ceil(sqrt(n));
		// Calcula o quadrado inferior a posicao da formiga.
		prev = (root - 1) * (root - 1);
		
		// Se a raiz e' impar, anda para cima e para esquerda.
		if(root % 2 == 1)
		{
			x = root;
			y = 0;
			if(n - prev < root)
				up = n - prev;
			else
				up = root;
			y += up;

			left = 0;
			if(n - prev > up)
				left = n - prev - up;
			x -= left;
		}
		// Se a raiz e' par, anda para direita e para baixo.
		else
		{
			x = 0;
			y = root;
			if(n - prev < root)
				right = n - prev;
			else
				right = root;
			x += right;

			down = 0;
			if(n - prev > right)
				down = n - prev - right;
			y -= down;
		}
		std::cout << x << " " << y << endl;
	}
	return 0;
}