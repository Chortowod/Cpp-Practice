#pragma once
#include <string>
#include <iostream>

using namespace std;

class Time
{
public:
	class ExScore // ����� ����������
	{
	public:
		string origin;
		ExScore(string);
	};
	Time();						// ����������� �� ���������
	Time(int);					// ����
	Time(double);				// ����
	Time(int, int);				// ���� � ������
	Time(int, int, int);		// ����, ������ � �������
	operator double() const;	// �������������� �� Time � double
	void Check();				// �������� �� ������������ ���������� ������� � ����������� ��������������
	int ToSeconds() const;		// �������������� � �������
	~Time();
	Time operator= (const Time &t2);
	friend Time operator+ (const Time&, const Time&);
	friend Time operator+ (const Time&, const double&);
	friend Time operator+ (const double&, const Time&);
	friend Time operator- (const Time&, const Time&);
	friend Time operator- (const double&, const Time&);
	friend Time operator- (const Time&, const double&);
	friend bool operator> (const Time&, const Time&);
	friend bool operator< (const Time &t1, const Time &t2);
	friend bool operator>= (const Time &t1, const Time &t2);
	friend bool operator<= (const Time &t1, const Time &t2);
	friend ostream &operator<< (ostream &out, const Time &t);
	friend istream &operator>> (istream &in, Time &t);
private:
	int days;
	int hours;
	int minutes;
	int seconds;
};

