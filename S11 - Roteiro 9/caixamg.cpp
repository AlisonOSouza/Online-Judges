/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 9
PROBLEMA:	#11 CAIXAMG - Caixa de Papelão

SOLUÇÃO PROPOSTA:
Neste problema, utilizo a propriedade 'pontos cŕiticos' de uma função para
achar os valores de máximos e mínimos. A função a ser analisada será o
volume da caixa, dado por (a-2x)*(b-2x)*x = 4x³ - 2x²(a+b) + x(ab)
(comprimento * largura * altura, respectivamente). Utilizo então a primeira
derivada dessa função (12x² - 4x(u+v) + uv) para achar os pontos críticos.
Para isso, leio as dimensões do papelão e chamo a função pontosCriticos()
que recebe as dimensões do papelão como parâmetros e calcula as raízes
da derivada da função volume, aplicando a fórmula de Bhaskara. Após isso
eu tenho duas raízes, e para saber qual delas me dará o maior volume,
chamo a função calculaVolume() que simplesmente aplica os valores das
dimensões do papelão e uma das raízes na fórmula do volume. Após calcular
o volume para as duas raízes, comparo os resultados e imprimo o tamanho
do lado do quadrado cortado e o volume máximo correspondente.
\*******************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct raizes
{
	double raiz1;
	double raiz2;
} raiz_t;

raiz_t pontosCriticos(int u, int v) // aplica Bhaskara
{
	// Usa a primeira derivada do volume da caixa.
	//12x² - 4x(u+v) + uv = 0
	double a, b, c, delta;
	raiz_t r;

	a = 12;
	b = -4*(u+v);
	c = u*v;

	delta = (b*b) - 4*a*c;

	r.raiz1 = (-b + sqrt(delta))/(2*a);
	r.raiz2 = (-b - sqrt(delta))/(2*a);

	return r;
}

double calculaVolume(double x, int a, int b)
{
	// Volume da caixa:
	// (a − 2x) * (b − 2x) * x
	// 4x³ - 2x²(a+b) + x(ab)
	return (4*(x*x*x) - 2*(x*x)*(a+b) + x*(a*b));
}

int main()
{
	int a, b;
	double v1, v2;
	raiz_t r;

	std::cin >> a >> b;
	while(a > 0 && b > 0)
	{
		r = pontosCriticos(a, b);
		
		// Testando qual raiz é ponto de máximo:
		v1 = calculaVolume(r.raiz1, a, b);
		v2 = calculaVolume(r.raiz2, a, b);

		if(v1 > v2)
			std::cout << fixed << setprecision(4) << r.raiz1 << " " << v1 << endl;
		else
			std::cout << fixed << setprecision(4) << r.raiz2 << " " << v2 << endl;

		std::cin >> a >> b;
	}

	return 0;
}