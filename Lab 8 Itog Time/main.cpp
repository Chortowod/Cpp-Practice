#include "time.h"
#include "point.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	system("chcp 1251");
	Time *time1 = new Time(54, 52, 15);
	Time *time2 = new Time(13, 44);
	Time time3 = Time::Plus(*time1, *time2);
	time1->ShowTime();
	time2->ShowTime();
	time3.ShowTime();
	delete time1;
	delete time2;

	Point *point1 = new Point(-5, 13);
	cout << endl << *point1 << "\n\n";

	vector<Point> vectorPoints;
	vectorPoints.push_back(*point1);
	vectorPoints.push_back(Point(1, 2));
	vectorPoints.push_back(Point(10, 12));
	vectorPoints.push_back(Point(21, 7));
	vectorPoints.push_back(Point(4, 8));
	sort(vectorPoints.begin(), vectorPoints.end());
	for (Point value : vectorPoints)
		std::cout << value << '\n';
	for (Point &value : vectorPoints)
		std::cout << value << '\n';
	delete point1;

}