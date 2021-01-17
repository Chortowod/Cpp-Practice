#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
#include <list>
#include <iterator>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Student
{
	public:
		void set_name(string student_name) { name = student_name; }						// Установка имени студента
		string get_name() { return name; }												// Получение имени студента
		void set_last_name(string student_last_name) { last_name = student_last_name; }	// Установка фамилии студента
		string get_last_name() { return last_name; }									// Получение фамилии студента
		void set_scores(int student_scores[])											// Установка промежуточных оценок
		{
			for (int i = 0; i < 5; ++i)
				scores[i] = student_scores[i];
		}
		void set_average_score(double ball) { average_score = ball; }					// Установка среднего балла
		double get_average_score() { return average_score; }							// Получение среднего балла
	private:
		int scores[5];			// Промежуточные оценки
		double average_score;	// Средний балл
		string name;			// Имя
		string last_name;		// Фамилия
};int main() 
{
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
	student01.set_scores(scores);				// Сохранение промежуточных оценок в объект класса Student
	double average_score = sum / 5.0;	student01.set_average_score(average_score);	cout << "Average ball for " << student01.get_name() << " " << student01.get_last_name() << " is " << student01.get_average_score() << endl;}