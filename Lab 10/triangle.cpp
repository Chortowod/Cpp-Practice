#include <iostream>
#include "triangle.h"

using namespace std;

Triangle::Triangle(Dot *dot1, Dot *dot2, Dot *dot3)
{
	A = *dot1;
	B = *dot2;
	C = *dot3;
}

void Triangle::MoveDotA(double newX, double newY)
{
	A.setX(A.getX() + newX);
	A.setY(B.getY() + newY);
}


void Triangle::ShowSides() const
{
	cout << "\nSide #1: " << A.GetDistanceTo(B);
	cout << "\nSide #2: " << B.GetDistanceTo(C);
	cout << "\nSide #3: " << C.GetDistanceTo(A);
}
void Triangle::ShowDots() const
{
	cout << "\nDot A [" << A.getX() << "; " << A.getY() << "]";
	cout << "\nDot B [" << B.getX() << "; " << B.getY() << "]";
	cout << "\nDot C [" << C.getX() << "; " << C.getY() << "]";
}

void Triangle::ShowDotA() const
{
	cout << "[" << A.getX() << "; " << A.getY() << "]";
}

double Triangle::Perimetr() const
{
	return A.GetDistanceTo(B) + B.GetDistanceTo(C) + C.GetDistanceTo(A);
}
double Triangle::Square() const
{
	double p = Perimetr() / 2;
	return sqrt(p * (p - A.GetDistanceTo(B)) * (p - B.GetDistanceTo(C)) * (p - C.GetDistanceTo(A)));
}