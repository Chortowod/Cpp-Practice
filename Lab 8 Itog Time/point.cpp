#include <iostream>
#include "point.h"

using namespace std;

Point::Point(int x, int y)
{
	Point::x = x;
	Point::y = y;
}
double Point::Center(Point point)
{
	return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

bool operator<(const Point &p1, const Point &p2)
{
	return Point::Center(p1) < Point::Center(p2);
}

ostream &operator<<(ostream &out, const Point &point)
{
	out << "Point(" << point.x << ", " << point.y << ")\t| Расстояние до центра: " << Point::Center(point);
	return out;
}
