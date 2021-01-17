#pragma once
#include <string>

using namespace std;

class Time
{
public:
	class ExScore //����� ����������
	{
	public:
		string origin;
		ExScore(string);
	};
	Time();
	Time(int, int);
	Time(int, int, int);
	static Time EnterTime();
	void Check(); //�������� �� ������������ ���������� ������� � ����������� ��������������
	void ShowTime() const;
	static Time Plus(Time, Time);
	~Time() { cout << "\n������ Time ���������"; }
private:
	int days;
	int hours;
	int minutes;
	int seconds;
};