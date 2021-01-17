#pragma once
class Dot
{
private:
	double x;
	double y;
public:
	Dot();
	Dot(double x, double y);
	double GetDistanceTo(Dot point) const;
	void Show() const;
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
	void Move(double, double);
	~Dot() {}
};