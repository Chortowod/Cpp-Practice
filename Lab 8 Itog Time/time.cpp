#include <string>
#include <iostream>
#include "time.h"

using namespace std;

Time::Time()
{
	days = 0;
}
Time::Time(int hours, int minutes)
{
	days = 0;
	seconds = 0;
	Check();
}
Time::Time(int hours, int minutes, int seconds)
{
	days = 0;
	Time::seconds = seconds;
	Check();
}

void Time::Check()