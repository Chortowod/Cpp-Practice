#include <string>
#include <sstream>
#include <vector>

#pragma once /* ������ �� �������� ����������� ������������� ����� */

class Human {
public:
	// ����������� ������ human
	Human() {}
	Human(std::string last_name, std::string name, std::string second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	// ��������� ��� ��������
	virtual void GetFullInfo()
	{
		cout << "\n" << last_name << " " << name << " " << second_name;
	}
private:
	std::string name; // ���
	std::string last_name; // �������
	std::string second_name; // ��������
};
class Student : public Human
{
public:
	// ����������� ������ Student
	Student() {}
	Student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores) :
		Human(last_name, name, second_name)
	{
		this->scores = scores;
	}
	void GetFullInfo()
	{
		Human::GetFullInfo();
		cout << " | ������� ���� ��������: " << get_average_score();
	}

	// ��������� �������� ����� ��������
	float get_average_score()
	{
		// ����� ���������� ������
		unsigned int count_scores = this->scores.size();
		if (count_scores == 0) return 0.0F;
		// ����� ���� ������ ��������
		unsigned int sum_scores = 0;
		// ������� ����
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i)
		{
			sum_scores += this->scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		return average_score;
	}
private:
	// ������ ��������
	std::vector<int> scores;
};
class Teacher : public Human {
public:
	Teacher() {}
	// ����������� ������ teacher
	Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time) :
		Human(last_name, name, second_name)
	{
		this->work_time = work_time;
	}

	void GetFullInfo()
	{
		Human::GetFullInfo();
		cout << " | ���������� ������� ����� �� �������: " << get_work_time();
	}
	// ��������� ���������� ������� �����
	unsigned int get_work_time()
	{
		return this->work_time;
	}
private:
	// ���������� ������� ����� �� ������� � �������������
	unsigned int work_time;
};