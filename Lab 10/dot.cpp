#include "dot.h"
#include <math.h>
#include <iostream>

using namespace std;

Dot::Dot() : x(0), y(0) {}
Dot::Dot(double x, double y) : x(x), y(y) {}

double Dot::GetDistanceTo(Dot point) const
{
	return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
}
void Dot::Show() const { cout << "[" << x << "; " << y << "]"; }
double Dot::getX() const { return x; }
double Dot::getY() const { return y; }
void Dot::setX(double x) { this->x = x; }
void Dot::setY(double y) { this->y = y; }
void Dot::Move(double x, double y) { this->x += x; this->y += y; }