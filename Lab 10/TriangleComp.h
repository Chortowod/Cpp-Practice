#pragma once
#include "dot.h"
class TriangleComp
{

public:
	TriangleComp();
	TriangleComp(double, double, double, double, double, double);
	void Move(double, double);
	void ShowSides() const;
	void ShowDots() const;
	double Perimetr() const;
	double Square() const;
	~TriangleComp();
private:
	Dot *A, *B, *C;
};