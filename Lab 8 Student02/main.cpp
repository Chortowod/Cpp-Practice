#include <iostream>
#include <string>
#include "student.h"

using namespace std;

void lab8_2()
{
	Student student01;							// �������� ������� ������ Student
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";							// ���� ����� � ����������
	getline(cin, name);
	cout << "Last name: ";						// ���� �������
	getline(cin, last_name);
	int sum = 0;								// ����� ���� ������
	for (int i = 0; i < 5; ++i) {				// ���� ������������� ������
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// ������������
	}
	student01.set_name(name);					// ���������� �����
	student01.set_last_name(last_name);			// � ������� � ������ ������ Student
	student01.set_scores(scores);				// ���������� ������������� ������ � ������ ������ Student
	double average_score = sum / 5.0;
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";							// ���� ����� � ����������
	getline(cin, name);
	cout << "Last name: ";						// ���� �������
	getline(cin, last_name);
	int sum = 0;								// ����� ���� ������
	for (int i = 0; i < 5; ++i) {				// ���� ������������� ������
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// ������������
	}
	student01->set_name(name);					// ���������� �����
	student01->set_last_name(last_name);		// � ������� � ������ ������ Student
	student01->set_scores(scores);				// ���������� ������������� ������ � ������ ������ Student
	double average_score = sum / 5.0;
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";									// ���� ����� � ����������
	getline(cin, name);
	cout << "Last name: ";								// ���� �������
	getline(cin, last_name);
	Student *student01 = new Student(name, last_name);	// �������� ���������� ������������
	int sum = 0;										// ����� ���� ������
	for (int i = 0; i < 5; ++i) {						// ���� ������������� ������
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];								// ������������
	}
	student01->set_scores(scores);						// ���������� ������������� ������ � ������ ������ Student
	double average_score = sum / 5.0;
	system("chcp 1251");