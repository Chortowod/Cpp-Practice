#pragma once
#include <string>

using namespace std;

class Student
{
public:
	Student();		// Конструктор по умолчанию
	Student(string, string);		// Конструктор
	void set_name(string);			// Установка имени студента
	string get_name();				// Получение имени студента
	void set_last_name(string);		// Установка фамилии студента
	string get_last_name();			// Получение фамилии студента
	void set_scores(int[]);			// Установка промежуточных оценок
	void set_average_score(double);	// Установка среднего балла
	double get_average_score();		// Получение среднего балла
	void save();
	~Student();
private:
	int scores[5];					// Промежуточные оценки
	double average_score;			// Средний балл
	string name;					// Имя
	string last_name;				// Фамилия
};
