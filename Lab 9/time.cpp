#include <string>
#include <iostream>
#include "time.h"

using namespace std;


Time::ExScore::ExScore(string orig) : origin(orig) {}

Time::Time()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}
Time::Time(int hours, int minutes)
{
	days = 0;
	Time::hours = hours;
	Time::minutes = minutes;
	seconds = 0;
	Check();
}
Time::Time(int hours, int minutes, int seconds)
{
	days = 0;
	Time::hours = hours;
	Time::minutes = minutes;
	Time::seconds = seconds;
	Check();
}

void Time::Check()
{
	if (seconds > 59)
	{
		minutes += seconds / 60;
		seconds %= 60;
	}
	if (minutes > 59)
	{
		hours += minutes / 60;
		minutes %= 60;
	}
	if (hours > 23)
	{
		days += hours / 24;
		hours %= 24;
	}
}

void Time::ShowTime() const
{
	cout << endl;
	(hours < 10) ? cout << "0" << hours : cout << hours;
	(minutes < 10) ? cout << ":0" << minutes : cout << ":" << minutes;
	(seconds < 10) ? cout << ":0" << seconds : cout << ":" << seconds;
	if (days > 0)
		cout << " + " << days << " day(s)";
}

Time Time::EnterTime()
{
	string time;
	int values[3]{ 0, 0, 0 };
	cout << "������� ����� � ������� ��:�� ��� ��:��:�� � ������� Enter: ";
	getline(cin, time);

	// ���� ������ �������� ���-�� ������ ���� � ":" --> ����������
	if (time.find_first_not_of("0123456789:") != string::npos)
		throw ExScore("������ �������� ������������ �������");

	// ����� ������� �����, ������� ��� ����������� �� �����
	int n = count(time.begin(), time.end(), ':');

	for (int i = 0; i <= n && i < 3; i++)
	{
		// ��� ������� ������ ���������� pos � �������� ����� ���������
		int pos = time.find(":");
		// �������� �� ������ ������ �� ":" � ����� ����������
		string val = time.substr(0, pos);
		if (val == "")
			// ���� ����� ��������� �������� � ":" ������ ��� --> ����������
			throw ExScore("�������� ���� ����� �� �������");
		if (val.length() > 7)
			// ���� ���� �� �������� ����������� ������� ������� --> ����������
			throw ExScore("��������� �������� ������� ������");
		// ����������� �������� ������� ���������������� � int ������
		values[i] = stoi(val);
		// �������� �� ������ ������ �� ":" ��� ���������� �����
		time.erase(0, pos + 1);
	}
	return Time(values[0], values[1], values[2]);
}

Time Time::Plus(Time t1, Time t2)
{
	Time t;
	t.hours = t1.hours + t2.hours;
	t.minutes = t1.minutes + t2.minutes;
	t.seconds = t1.seconds + t2.seconds;
	t.days = t1.days + t2.days;
	t.Check();
	return t;
}