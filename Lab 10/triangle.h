#pragma once
#include "dot.h"

class Triangle
{
private:
	Dot A, B, C;
public:
	Triangle() {}
	Triangle(Dot*, Dot*, Dot*);
	void MoveDotA(double, double);
	void ShowSides() const;
	void ShowDots() const;
	void ShowDotA() const;
	double Perimetr() const;
	double Square() const;
	~Triangle() {}
};