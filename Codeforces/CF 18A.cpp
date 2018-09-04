/*******************************************************************\
NOME:		Alison de Oliveira Souza
MATRÍCULA:	2012049316
ROTEIRO:	Roteiro 3
PROBLEMA:	#3 TRIANGLE - Triangle

SOLUÇÃO PROPOSTA:
Para este problema, criei uma classe Point, que representa cada ponto
dado como entrada. Além disso, também indica os vetores entre os pontos
de entrada. Leio os valores de 'x' e 'y' para os três pontos e calculo
os vetores entre os pontos. Após isso, faço a verificação se o triângulo
é retângulo utilizando a função isRightAngle(vec1, vec2), que calcula
o produto escalar entre dois vetores. Caso o produto escalar seja zero,
imprimo 'RIGHT', caso contrário (ou seja, o triângulo não é retângulo), 
faço a verificação se o triângulo se torna retângulo alterando uma das
cordenadas em mais ou menos 1 usando a função 
almostRightAngle(Point a, Point b, Point c). Caso retorne verdadeiro,
imprima 'ALMOST', caso retorne falso imprima 'NEITHER'.
\*******************************************************************/


#include <iostream>

using namespace std;

class Point
{
        int x;
        int y;
	public:
	    int getX();
	    int getY();
        void setPoint (int, int);
        Point calculatesVector(Point p);
        bool isRightAngled(Point p);
        bool isOrigin();
};

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setPoint(int a, int b)
{
    x = a;
    y = b;
}

Point Point::calculatesVector(Point p)
{
	Point ret;
	ret.setPoint(getX() - p.getX(), getY() - p.getY());
	return ret;
}

bool Point::isRightAngled(Point p)
{
	if(((getX() * p.getX()) + (getY() * p.getY()) == 0) && (getX() != p.getX() || getY() != p.getY()))
		return true;
	else
		return false;
}

bool Point::isOrigin()
{
    if(getX() == 0 && getY() == 0)
        return true;
    else
        return false;
}

bool almostRightAngle(Point a, Point b, Point c)
{
	int i, j;
	Point a_v[4], b_v[4], c_v[4], v[8], w[8], u[8], r[8], s[8], t[8],
		  ab, ac, ba, bc, ca, cb;
	
	a_v[0].setPoint(a.getX() + 1, a.getY());
	a_v[1].setPoint(a.getX() - 1, a.getY());
	a_v[2].setPoint(a.getX(), a.getY() + 1);
	a_v[3].setPoint(a.getX(), a.getY() - 1);
	
	b_v[0].setPoint(b.getX() + 1, b.getY());
	b_v[1].setPoint(b.getX() - 1, b.getY());
	b_v[2].setPoint(b.getX(), b.getY() + 1);
	b_v[3].setPoint(b.getX(), b.getY() - 1);
	
	c_v[0].setPoint(c.getX() + 1, c.getY());
	c_v[1].setPoint(c.getX() - 1, c.getY());
	c_v[2].setPoint(c.getX(), c.getY() + 1);
	c_v[3].setPoint(c.getX(), c.getY() - 1);
	
	v[0] = a.calculatesVector(b_v[0]);
	v[1] = a.calculatesVector(b_v[1]);
	v[2] = a.calculatesVector(b_v[2]);
	v[3] = a.calculatesVector(b_v[3]);
	v[4] = a.calculatesVector(c_v[0]);
	v[5] = a.calculatesVector(c_v[1]);
	v[6] = a.calculatesVector(c_v[2]);
	v[7] = a.calculatesVector(c_v[3]);
	
	w[0] = b.calculatesVector(a_v[0]);
	w[1] = b.calculatesVector(a_v[1]);
	w[2] = b.calculatesVector(a_v[2]);
	w[3] = b.calculatesVector(a_v[3]);
	w[4] = b.calculatesVector(c_v[0]);
	w[5] = b.calculatesVector(c_v[1]);
	w[6] = b.calculatesVector(c_v[2]);
	w[7] = b.calculatesVector(c_v[3]);
	
	u[0] = c.calculatesVector(a_v[0]);
	u[1] = c.calculatesVector(a_v[1]);
	u[2] = c.calculatesVector(a_v[2]);
	u[3] = c.calculatesVector(a_v[3]);
	u[4] = c.calculatesVector(b_v[0]);
	u[5] = c.calculatesVector(b_v[1]);
	u[6] = c.calculatesVector(b_v[2]);
	u[7] = c.calculatesVector(b_v[3]);
	
	r[0] = a_v[0].calculatesVector(b);
	r[1] = a_v[1].calculatesVector(b);
	r[2] = a_v[2].calculatesVector(b);
	r[3] = a_v[3].calculatesVector(b);
	r[4] = a_v[0].calculatesVector(c);
	r[5] = a_v[1].calculatesVector(c);
	r[6] = a_v[2].calculatesVector(c);
	r[7] = a_v[3].calculatesVector(c);
	
	s[0] = b_v[0].calculatesVector(a);
	s[1] = b_v[1].calculatesVector(a);
	s[2] = b_v[2].calculatesVector(a);
	s[3] = b_v[3].calculatesVector(a);
	s[4] = b_v[0].calculatesVector(c);
	s[5] = b_v[1].calculatesVector(c);
	s[6] = b_v[2].calculatesVector(c);
	s[7] = b_v[3].calculatesVector(c);
	
	t[0] = c_v[0].calculatesVector(a);
	t[1] = c_v[1].calculatesVector(a);
	t[2] = c_v[2].calculatesVector(a);
	t[3] = c_v[3].calculatesVector(a);
	t[4] = c_v[0].calculatesVector(b);
	t[5] = c_v[1].calculatesVector(b);
	t[6] = c_v[2].calculatesVector(b);
	t[7] = c_v[3].calculatesVector(b);
	
	ab = a.calculatesVector(b); //v[4] a v[7]
	ac = a.calculatesVector(c); //v[0] a v[3]
	
	ba = b.calculatesVector(a); //w[4] a w[7]
	bc = b.calculatesVector(c); //w[0] a w[3]
	
	ca = c.calculatesVector(a); //u[4] a u[7]
	cb = c.calculatesVector(b); //u[0] a u[3]
	
	i = 0; j = 4;
	while(i < 4 && j < 8)
    {
        if(!v[j].isOrigin())
        {
            if(ab.isRightAngled(v[j]))
                return true;
        }
        if(!v[i].isOrigin())
        {
            if(ac.isRightAngled(v[i]))
                return true;
        }
        if(!w[j].isOrigin())
        {
            if(ba.isRightAngled(w[j]))
                return true;
        }
        if(!w[i].isOrigin())
        {
            if(bc.isRightAngled(w[i]))
                return true;
        }
        if(!u[j].isOrigin())
        {
            if(ca.isRightAngled(u[j]))
                return true;
        }
        if(!u[i].isOrigin())
        {
            if(cb.isRightAngled(u[i]))
                return true;
        }
		if(!r[i].isOrigin() && !r[j].isOrigin())
		{
			if(r[i].isRightAngled(r[j]))
				return true;
		}
		if(!s[i].isOrigin() && !s[j].isOrigin())
		{
			if(s[i].isRightAngled(s[j]))
				return true;
		}
		if(!t[i].isOrigin() && !t[j].isOrigin())
		{
			if(t[i].isRightAngled(t[j]))
				return true;
		}
        i++;
        j++;
    }
		
	return false;
}

int main(void)
{
    int x1, x2, x3, y1, y2, y3;
	Point a, b, c;
	
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	a.setPoint(x1, y1);
	b.setPoint(x2, y2);
	c.setPoint(x3, y3);
	
	Point ab = a.calculatesVector(b);
	Point ac = a.calculatesVector(c);
	
	Point ba = b.calculatesVector(a);
	Point bc = b.calculatesVector(c);
	
	Point ca = c.calculatesVector(a);
	Point cb = c.calculatesVector(b);
	
	if(ab.isRightAngled(ac) || ba.isRightAngled(bc) || ca.isRightAngled(cb)) 
		std::cout << "RIGHT";
	else if(almostRightAngle(a, b, c))
		std::cout << "ALMOST";
	else
		std::cout << "NEITHER";
	
	return 0;
}