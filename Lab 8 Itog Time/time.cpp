#include <string>
#include <iostream>
#include "time.h"

using namespace std;

Time::Time()
{
	days = 0;	hours = 0;	minutes = 0;	seconds = 0;
}
Time::Time(int hours, int minutes)
{
	days = 0;	Time::hours = hours;	Time::minutes = minutes;
	seconds = 0;
	Check();
}
Time::Time(int hours, int minutes, int seconds)
{
	days = 0;	Time::hours = hours;	Time::minutes = minutes;
	Time::seconds = seconds;
	Check();
}

void Time::Check(){	if (seconds > 59)	{		minutes += seconds / 60;		seconds %= 60;	}	if (minutes > 59)	{		hours += minutes / 60;		minutes %= 60;	}	if (hours > 23)	{		days += hours / 24;		hours %= 24;	}}void Time::ShowTime() const{	cout << endl;	(hours < 10) ? cout << "0" << hours : cout << hours;	(minutes < 10) ? cout << ":0" << minutes : cout << ":" << minutes;	(seconds < 10) ? cout << ":0" << seconds : cout << ":" << seconds;	if (days > 0)		cout << " + " << days << " day(s)";}Time Time::Plus(Time t1, Time t2){	Time t;	t.hours = t1.hours + t2.hours;	t.minutes = t1.minutes + t2.minutes;	t.seconds = t1.seconds + t2.seconds;	t.days = t1.days + t2.days;	t.Check();	return t;}