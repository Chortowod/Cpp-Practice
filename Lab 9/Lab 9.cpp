#include <iostream>
#include <string>
#include "time.h"

using namespace std;

class DivideByZeroError
{
private:
	string message;
public:
//	DivideByZeroError() : message("Деление на нуль") { }
	DivideByZeroError() { message = "Деление на нуль"; }
	void printMessage() const { cout << message << endl; }
};

class Student
{
public:
	class ExScore //класс исключений
	{
	public:
		string origin; //для имени функции
		int iValue; //для хранения ошибочного значения
		ExScore(string orig, int sc)
		{
			origin = orig;
			iValue = sc;
		}
	};
	void set_name(string student_name) { name = student_name; }						// Установка имени студента
	string get_name() { return name; }												// Получение имени студента
	void set_last_name(string student_last_name) { last_name = student_last_name; }	// Установка фамилии студента
	string get_last_name() { return last_name; }									// Получение фамилии студента
	void set_scores(int student_scores[])											// Установка промежуточных оценок
	{
		for (int i = 0; i < 5; ++i)
		{
			if (student_scores[i] > 5)
				throw ExScore("в функции set_scores()", student_scores[i]);
			scores[i] = student_scores[i];
		}
	}
	void set_average_score(double ball) { average_score = ball; }					// Установка среднего балла
	double get_average_score() { return average_score; }							// Получение среднего балла
private:
	int scores[5];			// Промежуточные оценки
	double average_score;	// Средний балл
	string name;			// Имя
	string last_name;		// Фамилия
};

class Triangle
{
private:
	double a, b, c;
public:
	class ExScore // класс исключений
	{
	public:
		string origin; // для имени функции
		double iValue; // для хранения ошибочного значения
		ExScore(string orig, double sc)
		{
			origin = orig;
			iValue = sc;
		}
	};
	Triangle() {};
	Triangle(double a, double b, double c)
	{
		if (a >= b + c)
			//Исключения три для того, чтобы выводить на экран "виновную" сторону
			throw ExScore("в конструкторе с параметрами", a);
		else if (b >= a + c)
			throw ExScore("в конструкторе с параметрами", b);
		else if (c >= a + b)
			throw ExScore("в конструкторе с параметрами", c);
		Triangle::a = a;
		Triangle::b = b;
		Triangle::c = c;
	}
	~Triangle() {};
	static double Sq(Triangle t)
	{
		double p = (t.a + t.b + t.c) / 2;
		return sqrt(p*(p - t.a)*(p - t.b)*(p - t.c));
	}
};

float quotient(int numl, int num2)
{
	if (num2 == 0)
		throw DivideByZeroError();
	return (float)numl / num2;
}

int lab9_1() {
	cout << "Введите два целых числа для расчета их частного:\n";
	int number1, number2;
	cin >> number1;
	cin >> number2;
	try
	{
		float result = quotient(number1, number2);
		cout << "Частное равно " << result << endl;
	}
	catch (DivideByZeroError error)
	{
		cout << "ОШИБКА: ";
		error.printMessage();
		return 1; // завершение программы при ошибке
	}
	return 0; // нормальное завершение программы
}

int lab9_2() {
	cout << "Введите целое число для расчета частного:\n";
	int number1;
	cin >> number1;
	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "Частное равно " << result << endl;
		}
		catch (DivideByZeroError error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
		}
	}
	return 0; // нормальное завершение программы
}

void lab9_3() {
	Student student01;							// Создание объекта класса Student
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";							// Ввод имени с клавиатуры
	getline(cin, name);
	cout << "Last name: ";						// Ввод фамилии
	getline(cin, last_name);
	int sum = 0;								// Сумма всех оценок
	for (int i = 0; i < 5; ++i) {				// Ввод промежуточных оценок
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// суммирование
	}
	student01.set_name(name);					// Сохранение имени
	student01.set_last_name(last_name);			// и фамилии в объект класса Student
	try
	{
		student01.set_scores(scores);				// Сохранение промежуточных оценок в объект класса Student
		double average_score = sum / 5.0;
		student01.set_average_score(average_score);
		cout << "Average ball for " << student01.get_name() << " " << student01.get_last_name() << " is " << student01.get_average_score() << endl;
	}
	catch (Student::ExScore ex)
	{
		cout << "\nОшибка инициализации " << ex.origin;
		cout << "\nВведенное значение оценки [" << ex.iValue << "] является недопустимым\n";
	}
}

void lab9_itog1() {
	double a, b, c;
	cout << "Введите три стороны треугольника: ";
	cin >> a >> b >> c;
	try
	{
		Triangle *tt = new Triangle(a, b, c);
		double q = Triangle::Sq(*tt);
		cout << "Площадь треугольника: " << q;
	}
	catch (Triangle::ExScore ex)
	{
		cout << "\nОшибка инициализации " << ex.origin;
		cout << "\nВведенное значение стороны [" << ex.iValue << "] больше суммы двух других\n";
	}
}

void lab9_itog2() {

	try
	{
		// Просим пользователя ввести данные
		Time time1 = Time::EnterTime();
		Time time2 = Time::EnterTime();
		Time *time3 = new Time(13, 44);
		Time time4 = Time::Plus(time1, time2);
		time1.ShowTime();
		time2.ShowTime();
		time3->ShowTime();
		time4.ShowTime();
		delete time3;
	}
	catch (Time::ExScore ex) { cout << "\nОшибка инициализации: " << ex.origin; }

}

int main()
{
	system("chcp 1251");
	lab9_itog2();
}