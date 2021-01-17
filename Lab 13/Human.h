#include <string>
#include <sstream>
#include <vector>

#pragma once /* Защита от двойного подключения заголовочного файла */

class Human {
public:
	// Конструктор класса human
	Human() {}
	Human(std::string last_name, std::string name, std::string second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	// Получение ФИО человека
	virtual void GetFullInfo()
	{
		cout << "\n" << last_name << " " << name << " " << second_name;
	}
private:
	std::string name; // имя
	std::string last_name; // фамилия
	std::string second_name; // отчество
};
class Student : public Human
{
public:
	// Конструктор класса Student
	Student() {}
	Student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores) :
		Human(last_name, name, second_name)
	{
		this->scores = scores;
	}
	void GetFullInfo()
	{
		Human::GetFullInfo();
		cout << " | Средний балл студента: " << get_average_score();
	}

	// Получение среднего балла студента
	float get_average_score()
	{
		// Общее количество оценок
		unsigned int count_scores = this->scores.size();
		if (count_scores == 0) return 0.0F;
		// Сумма всех оценок студента
		unsigned int sum_scores = 0;
		// Средний балл
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i)
		{
			sum_scores += this->scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		return average_score;
	}
private:
	// Оценки студента
	std::vector<int> scores;
};
class Teacher : public Human {
public:
	Teacher() {}
	// Конструктор класса teacher
	Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time) :
		Human(last_name, name, second_name)
	{
		this->work_time = work_time;
	}

	void GetFullInfo()
	{
		Human::GetFullInfo();
		cout << " | Количество учебных часов за семестр: " << get_work_time();
	}
	// Получение количества учебных часов
	unsigned int get_work_time()
	{
		return this->work_time;
	}
private:
	// Количество учебных часов за семестр у преподавателя
	unsigned int work_time;
};