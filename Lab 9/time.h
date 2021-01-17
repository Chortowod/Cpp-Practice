#pragma once
#include <string>

using namespace std;

class Time
{
public:
	class ExScore //класс исключений
	{
	public:
		string origin;
		ExScore(string);
	};
	Time();
	Time(int, int);
	Time(int, int, int);
	static Time EnterTime();
	void Check(); //Проверка на правильность введенного времени и необходимые преобразования
	void ShowTime() const;
	static Time Plus(Time, Time);
	~Time() { cout << "\nОбъект Time уничтожен"; }
private:
	int days;
	int hours;
	int minutes;
	int seconds;
};