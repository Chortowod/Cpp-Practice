#include "triangleS.h"
#include <math.h>
#include <iostream>

using namespace std;

TriangleS::Dot::Dot() : x(0), y(0) {}
TriangleS::Dot::Dot(double x, double y) : x(x), y(y) {}

double TriangleS::Dot::distanceTo(Dot point)
{
	return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
}

double TriangleS::Dot::getX() { return x; }
double TriangleS::Dot::getY() { return y; }
void TriangleS::Dot::setX(double x) { Dot::x = x; }
void TriangleS::Dot::setY(double y) { Dot::y = y; }


TriangleS::TriangleS(Dot &dot1, Dot &dot2, Dot &dot3) : A(&dot1), B(&dot2), C(&dot3) {}

void TriangleS::ShowSides(TriangleS &tr)
{
	cout << "\nSide #1: " << tr.A->distanceTo(*tr.B);
	cout << "\nSide #2: " << tr.B->distanceTo(*tr.C);
	cout << "\nSide #3: " << tr.C->distanceTo(*tr.A);
}
double TriangleS::Perimetr(TriangleS &tr)
{
	return tr.A->distanceTo(*tr.B) + tr.B->distanceTo(*tr.C) + tr.C->distanceTo(*tr.A);
}
double TriangleS::Square(TriangleS &tr)
{
	double p = Perimetr(tr) / 2;
	return sqrt(p * (p - tr.A->distanceTo(*tr.B)) * (p - tr.B->distanceTo(*tr.C)) * (p - tr.C->distanceTo(*tr.A)));
}
void TriangleS::changeXA(double newX)
{
	A->setX(newX);
}