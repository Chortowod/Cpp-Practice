#include <iostream>
#include <string>
#include "student.h"
#include "triangle.h"
#include "triangleComp.h"

void lab10_1()
{
	string name;
	string last_name;
	string status;
	int id;
	int scores[5];
	cout << "Name: ";							// Ввод имени с клавиатуры
	getline(cin, name);
	cout << "Last name: ";						// Ввод фамилии
	getline(cin, last_name);
	cout << "ID: ";								// Ввод имени с клавиатуры
	cin >> id;
	cout << "Status: ";							// Ввод имени с клавиатуры
	cin >> status;
	int sum = 0;								// Сумма всех оценок
	for (int i = 0; i < 5; ++i) {				// Ввод промежуточных оценок
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];						// суммирование
	}

	Student *student02 = new Student(name, last_name, new IdCard(id, status));
	
	student02->set_name(name);					// Сохранение имени
	student02->set_last_name(last_name);		// и фамилии в объект класса Student
	student02->set_scores(scores);				// Сохранение промежуточных оценок в объект класса Student
	double average_score = sum / 5.0;
	student02->set_average_score(average_score);
	cout << "Average ball for " << student02->get_name() << " " << student02->get_last_name() <<
			" is " << student02->get_average_score() << endl;
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	delete student02;
}

void lab10_itog1()
{
	Dot *dot1 = new Dot(-5, 2);
	Dot *dot2 = new Dot(7, -7);
	Dot *dot3 = new Dot(5, 7);
	Triangle *triangle = new Triangle(dot1, dot2, dot3);
	cout << "\nПлощадь: " << triangle->Square();
	triangle->ShowSides();
	cout << "\nТочка dot1 "; dot1->Show();
	cout << "\nТочка A треугольника "; triangle->ShowDotA();
	cout << "\nПериметр: " << triangle->Perimetr();

	triangle->MoveDotA(2, 2);
	cout << "\n\n[Изменили точку A внутри треугольника]";
	cout << "\nТочка dot1 "; dot1->Show(); cout << "\t\t\t<------ осталась без изменений!";
	cout << "\nТочка A треугольника "; triangle->ShowDotA();
	cout << "\nПериметр: " << triangle->Perimetr();

	dot1->Move(5, 5);
	cout << "\n\n[Изменили точку dot1 вне треугольника]";
	cout << "\nТочка dot1 "; dot1->Show();
	cout << "\nТочка A треугольника "; triangle->ShowDotA(); cout << "\t\t<------ осталась без изменений!";
	cout << "\nПериметр: " << triangle->Perimetr();

	cout << "\n\n";
}

void lab10_itog2()
{
	double dots[6];
	for (char i = 'A', j = 0; i < 'D'; i++, j += 2)
	{
		cout << "Введите координаты точки " << i << " для треугольника ABC через пробел: ";
		cin >> dots[j] >> dots[j + 1];
	}

	TriangleComp *triangleComp = new TriangleComp(dots[0], dots[1], dots[2], dots[3], dots[4], dots[5]);
	triangleComp->ShowSides();
	triangleComp->ShowDots();
	cout << "\nПериметр: " << triangleComp->Perimetr();
	cout << "\nПлощадь: " << triangleComp->Square();

	triangleComp->Move(3, -3);
	cout << "\n\n[Передвинули точки треугольника]";
	triangleComp->ShowDots();
	cout << "\nПериметр: " << triangleComp->Perimetr();
	cout << "\nПлощадь: " << triangleComp->Square();
}

int main()
{
	system("chcp 1251");
	lab10_itog1(); // как агрегация
//	lab10_itog2(); // как композиция
}

