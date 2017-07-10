/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 14
PROBLEMA:	#4 DVORONOI - Diagrama de Voronoi

SOLUÇÃO PROPOSTA:
Neste problema, podemos achar o volume do tetraedro calculado o produto
misto entre os três vetores, usando a fórmula (Area * Altura)/3 do volume
de qualquer tetraedro. Temos que dividir a área por 2, para achar a base
triangular correta. Assim, para achar o volume do sólido leio os pontos
que formam o tetraedro e calculo os três vetores entre esses pontos,
usando a função subtract(). Após isso, calculo o determinante da matriz
formada pelos três vetores, usando a  função determinante(). Após isso
tudo, divido o determinante por 6 e obtenho o volume do tetraedro.
\*******************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct ponto
{
	int x;
	int y;
	int z;	
} ponto_t;

ponto_t subtract(ponto_t p, ponto_t q)
{
	ponto_t ret;
	ret.x = p.x - q.x;
	ret.y = p.y - q.y;
	ret.z = p.z - q.z;
	return ret;
}

int determinante(ponto_t p, ponto_t q, ponto_t r)
{
	int diagPrinc, diagSecund, det;
	diagPrinc = (p.x * q.y * r.z) + (p.y * q.z * r.x) + (p.z * q.x * r.y);
	diagSecund = (p.x * q.z * r.y) + (p.y * q.x * r.z) + (p.z * q.y * r.x);
	det = diagPrinc - diagSecund;
	return det;
}

int main()
{
	int t, det; 
	double vol;
	ponto_t a, b, c, d, u, v, w;

	std::cin >> t;
	while(t--)
	{
		std::cin >> a.x >> a.y >> a.z
				 >> b.x >> b.y >> b.z
				 >> c.x >> c.y >> c.z
				 >> d.x >> d.y >> d.z;

		u = subtract(a, d);
		v = subtract(b, d);
		w = subtract(c, d);

		det = determinante(u, v, w);
		if(det < 0) det = -det;

		vol = det/6.0;

		std::cout << fixed << setprecision(6) << vol << endl;
	}
	return 0;
}