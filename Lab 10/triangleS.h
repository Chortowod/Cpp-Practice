#pragma once
class TriangleS
{

public:
	class Dot
	{
	private:
		double x;
		double y;
	public:
		Dot();
		Dot(double x, double y);
		double distanceTo(Dot point);
		double getX();
		void setX(double);
		double getY();
		void setY(double);
		~Dot() {}
	};
	TriangleS() {}
	TriangleS(Dot&, Dot&, Dot&);
	void changeXA(double);
	static void ShowSides(TriangleS&);
	static double Perimetr(TriangleS&);
	static double Square(TriangleS&);
	~TriangleS() {}
private:
	Dot *A, *B, *C;
};