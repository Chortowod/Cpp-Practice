#include <string>
#include <fstream>
#include "student.h"

Student::Student() { }
Student::Student(string name, string last_name, IdCard *id)
{
	set_name(name);
	set_last_name(last_name);
	setIdCard(id);
}
void Student::setIdCard(IdCard *c) { iCard = c; }
IdCard Student::getIdCard() { return *iCard; }
void Student::set_name(string student_name) { name = student_name; }						// Установка имени студента
string Student::get_name() { return name; }													// Получение имени студента
void Student::set_last_name(string student_last_name) { last_name = student_last_name; }	// Установка фамилии студента
string Student::get_last_name() { return last_name; }										// Получение фамилии студента
void Student::set_scores(int student_scores[])												// Установка промежуточных оценок
{
	for (int i = 0; i < 5; ++i)
		scores[i] = student_scores[i];
}
void Student::set_average_score(double ball) { average_score = ball; }						// Установка среднего балла
double Student::get_average_score() { return average_score; }								// Получение среднего балла

Student::~Student() { save(); }
void Student::save()
{
	ofstream fout("students.txt", ios::app);
	fout << Student::get_name() << " " << Student::get_last_name() << " ";
	for (int i = 0; i < 5; ++i)
		fout << Student::scores[i] << " ";
	fout << "| ID: " << Student::getIdCard().getNumber() << " [" << Student::getIdCard().getCategory() << "]";
	fout << endl;
	fout.close();
}

