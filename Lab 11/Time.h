#pragma once
#include <string>
#include <iostream>

using namespace std;

class Time
{
public:
	class ExScore // Класс исключений
	{
	public:
		string origin;
		ExScore(string);
	};
	Time();						// Конструктор по умолчанию
	Time(int);					// Часы
	Time(double);				// Часы
	Time(int, int);				// Часы и минуты
	Time(int, int, int);		// Часы, минуты и секунды
	operator double() const;	// Преобразование из Time в double
	void Check();				// Проверка на правильность введенного времени и необходимые преобразования
	int ToSeconds() const;		// Преобразование в секунды
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

