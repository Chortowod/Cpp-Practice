#pragma once
#include <string>

using namespace std;

class Point
{
public:
	Point(int, int);
	~Point() {};
	static double Center(Point);
	friend bool operator< (const Point&, const Point&);
	friend ostream &operator<< (ostream&, const Point&);
private:
	double x;
	double y;
};