#include <iostream>
#include <string>
#include "student.h"

using namespace std;

void lab8_2()
{
	Student student01;							// —оздание объекта класса Student
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";							// ¬вод имени с клавиатуры
	getline(cin, name);
	cout << "Last name: ";						// ¬вод фамилии
	getline(cin, last_name);
	int sum = 0;								// —умма всех оценок
	for (int i = 0; i < 5; ++i) {				// ¬вод промежуточных оценок
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// суммирование
	}
	student01.set_name(name);					// —охранение имени
	student01.set_last_name(last_name);			// и фамилии в объект класса Student
	student01.set_scores(scores);				// —охранение промежуточных оценок в объект класса Student
	double average_score = sum / 5.0;	student01.set_average_score(average_score);	cout << "Average ball for " << student01.get_name() << " " << student01.get_last_name() << " is " << student01.get_average_score() << endl;}void lab8_3(){	Student *student01 = new Student;			// —оздание объекта класса Student
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";							// ¬вод имени с клавиатуры
	getline(cin, name);
	cout << "Last name: ";						// ¬вод фамилии
	getline(cin, last_name);
	int sum = 0;								// —умма всех оценок
	for (int i = 0; i < 5; ++i) {				// ¬вод промежуточных оценок
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// суммирование
	}
	student01->set_name(name);					// —охранение имени
	student01->set_last_name(last_name);		// и фамилии в объект класса Student
	student01->set_scores(scores);				// —охранение промежуточных оценок в объект класса Student
	double average_score = sum / 5.0;	student01->set_average_score(average_score);	cout << "Average ball for " << student01->get_name() << " " << student01->get_last_name() << " is " << student01->get_average_score() << endl;	delete student01;}void lab8_4(){
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";									// ¬вод имени с клавиатуры
	getline(cin, name);
	cout << "Last name: ";								// ¬вод фамилии
	getline(cin, last_name);
	Student *student01 = new Student(name, last_name);	// ѕередача параметров конструктору
	int sum = 0;										// —умма всех оценок
	for (int i = 0; i < 5; ++i) {						// ¬вод промежуточных оценок
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];								// суммирование
	}
	student01->set_scores(scores);						// —охранение промежуточных оценок в объект класса Student
	double average_score = sum / 5.0;	student01->set_average_score(average_score);	cout << "Average ball for " << student01->get_name() << " " << student01->get_last_name() << " is " << student01->get_average_score() << endl;	delete student01;}int main(){
	system("chcp 1251");	lab8_4();}