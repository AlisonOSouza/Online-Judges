/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 10
PROBLEMA:	#1 BICHO - Jogo do Bicho

SOLUÇÃO PROPOSTA:
Neste problema, leio os valores de entrada e passo eles para uma função
chamada calculaPremio(V, M, N) que verifica se os últimos 4, 3 ou 2
algarismos dos números M e N são iguais calculando os módulos (10000, 1000
e 100 respectivamente) e comparando se são iguais. Caso nenhuma das
hipóteses anteriores seja verdade, então chamo a função grupoAnimal(M, N)
que verifica se M e N pertencem ao mesmo grupo de animais, verificando
se o intervalo entre M e N é menor ou igual a 3. Se for verdade, então
os dois números são do mesmo grupo. Após isso, a função calculaPremio()
retornará o valor apostado multiplicado pelo multiplicador apropriado.
Com esse valor em mãos, imprimo na tela esse valor com duas casas
decimais.
\*******************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

bool grupoAnimal(int n, int m)
{
	int n_mod = n % 100;
	int m_mod = m % 100;

	if((MAX(n_mod, m_mod) - MIN(n_mod, m_mod) <= 3) && MIN(n_mod, m_mod) != 0)
		return true;
	else if(MAX(n_mod, m_mod) >= 97 && MIN(n_mod, m_mod) == 0)
		return true;
	else
		return false;
}

double calculaPremio(double v, int n, int m)
{
	if(n % 10000 == m % 10000)
	{
		return (v * 3000);
	}
	else if(n % 1000 == m % 1000)
	{
		return (v * 500);
	}
	else if(n % 100 == m % 100)
	{
		return (v * 50);
	}
	else if(grupoAnimal(n, m))
	{
		return (v * 16);
	}
	else return 0;
}

int main()
{
	int n, m;
	double v, premio;

	std::cin >> v >> n >> m;
	while(v > 0 || n > 0 || m > 0)
	{
		premio = calculaPremio(v, n, m);
		std::cout << fixed << setprecision(2) << premio << endl;
		std::cin >> v >> n >> m;
	}

	return 0;
}