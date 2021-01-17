#include "Item.h"
#include "Human.h"

void lab13_1()
{
	Item* pubarr[100];
	int n = 0;
	char choice;
	do
	{
		cout << "\nВводить данные для книги или звукового файла (b / a)?";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new Paperbook;
		else
			pubarr[n] = new AudioBook;
		pubarr[n++]->getdata();
		cout << "Продолжать (у / n)?";
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)	// цикл по всем объектам
		pubarr[j]->putdata();	// вывести данные о публикации
	cout << endl;
}

void lab13_itog()
{
	Human *human[20];
	int n = 0;
	char choice;
	string surname, name, patname;
	do
	{
		cout << "\nЗарегистрировать нового студента или преподавателя (s / t)? ";
		cin >> choice;
		cout << "\nВведите фамилию: "; cin >> surname;
		cout << "\nВведите имя: "; cin >> name;
		cout << "\nВведите отчество: "; cin >> patname;
		if (choice == 's')
		{
			std::vector<int> scores;
			human[n] = new Student(surname, name, patname, scores);
		}
		else
		{
			int hours;
			cout << "\nВведите количество учебных часов за семестр: "; cin >> hours;
			human[n] = new Teacher(surname, name, patname, hours);
		}
		n++;
		cout << "\nПродолжать (у / n)?";
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)		// цикл по всем объектам
		human[j]->GetFullInfo();	// вывести данные человеке
	cout << endl;
}



int main()
{
	SetConsoleOutputCP(1251);
	lab13_itog();
}
