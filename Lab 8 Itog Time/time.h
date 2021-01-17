#pragma once
#include <string>

using namespace std;

class Time
{
public:
	Time();
	Time(int, int);
	Time(int, int, int);
	void Check(); //�������� �� ������������ ���������� ������� � ����������� ��������������
	void ShowTime() const;
	static Time Plus(Time, Time);
	~Time() {};
private:
	int days;
	int hours;
	int minutes;
	int seconds;
};