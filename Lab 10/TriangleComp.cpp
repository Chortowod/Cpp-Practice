#include "TriangleComp.h"
#include "dot.h"
#include <math.h>
#include <iostream>

using namespace std;

TriangleComp::TriangleComp()
{
	TriangleComp::A = new Dot();
	TriangleComp::B = new Dot();
	TriangleComp::C = new Dot();
}

TriangleComp::TriangleComp(double x1, double y1, double x2, double y2, double x3, double y3) 
{
	A = new Dot(x1, y1);
	B = new Dot(x2, y2);
	C = new Dot(x3, y3);
}

void TriangleComp::Move(double x, double y)
{
	A->Move(x, y);
	B->Move(x, y);
	C->Move(x, y);
}

void TriangleComp::ShowSides() const
{
	cout << "\nSide #1: " << A->GetDistanceTo(*B);
	cout << "\nSide #2: " << B->GetDistanceTo(*C);
	cout << "\nSide #3: " << C->GetDistanceTo(*A);
}

void TriangleComp::ShowDots() const
{
	cout << "\nDot A [" << A->getX() << "; " << A->getY() << "]";
	cout << "\nDot B [" << B->getX() << "; " << B->getY() << "]";
	cout << "\nDot C [" << C->getX() << "; " << C->getY() << "]";
}

double TriangleComp::Perimetr() const
{
	return A->GetDistanceTo(*B) + B->GetDistanceTo(*C) + C->GetDistanceTo(*A);
}
double TriangleComp::Square() const
{
	double p = Perimetr() / 2;
	return sqrt(p * (p - A->GetDistanceTo(*B)) * (p - B->GetDistanceTo(*C)) * (p - C->GetDistanceTo(*A)));
}

TriangleComp::~TriangleComp() { delete A, B, C; }