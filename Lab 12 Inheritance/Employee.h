#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS (����� std::localtime �� �������� - ������� ���������, ���� �� ����� ����)
#include <chrono>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

// ����� ������� ��������, �������� ������-������ �������
class Employee
{
private:
	std::string mName;		// ���
	std::string mSurname;	// �������
	std::string mPatname;	// ��������
	std::string mPhone;		// ����� ��������
public:
	Employee() {};
	~Employee() 
	{ 
//		std::cout << "\n���������� ���������"; 
	};
	Employee(std::string name, std::string surname, std::string patname, std::string phone) :
		mName(name), mSurname(surname), mPatname(patname), mPhone(phone) {};
	// �������� ������ � ���
	std::string GetName()
	{
		return mSurname + " " + mName + " " + mPatname;
	}
	// ���������� ��������� ������ ��� ���������� ������
	friend std::ostream &operator<< (std::ostream &out, const Employee &emp)
	{
		out << emp.mSurname << " " << emp.mName << " " << emp.mPatname << " | �������: " << emp.mPhone << std::endl;
		return out;
	}
	// ���������� ��������� ���������
	friend bool operator== (const Employee emp1, const Employee &emp2)
	{
		if (emp1.mName == emp2.mName && emp1.mSurname == emp2.mSurname && emp1.mPatname == emp2.mPatname && emp1.mPhone == emp2.mPhone)
			return true;
		else
			return false;
	}
};

// ��������, ������� ����� � ���������� ��������� ������� ����������, 
// ������� �� ����� �������� � ���� ����� � ���������
class Manager : public Employee
{
private:
	std::vector<Employee> mSubordinates;	// ������ ���������� � ����������
public:
	Manager() {};
	~Manager() 
	{ 
//		std::cout << "\n���������� ���������"; 
	};
	Manager(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	// �������� ������ ���� ���������� � ����������
	std::vector<Employee> GetAllSubordinates()
	{
		return mSubordinates;
	}
	// ������� ��������� � �����
	void ReceiveEmployee(Employee emp)
	{
		mSubordinates.push_back(emp);
	}
	// ������� ��������� �� ������
	void FireEmployee(Employee emp)
	{
		bool isFired = false;
		// ���� ���������
		for (unsigned int i = 0; i < mSubordinates.size(); i++)
		{
			if (mSubordinates[i] == emp) //��� ����� ����������� �������� ���������
			{
				// ��������� ��� ��� ����������� ���� �� ��������
				std::string fired_person = mSubordinates[i].GetName(); 
				// �������
				mSubordinates.erase(mSubordinates.begin() + i);
				// ���� �� ������
				std::cout << "\n�������� [" << fired_person << "] ������� ������!" << std::endl;
				isFired = true;
				break;
			}
		}
		if (!isFired) // ���� �������� �� �������, �� ��������
			std::cout << "\n�������� [" << emp.GetName() << "] �� ������!" << std::endl;
	}
};

// ����������, � �������� ���� ��������� ��� ������, ������� �� ����� �������,
// � ����� ������ ���, ��� �������� � ���� ��������
class Instructor : public Employee
{
private:
	std::vector<Employee> mListeners; // ������ ���� ���������� �����������
	std::vector<Employee> mGraduated; // ������ ���� ����������� �����������
public:
	Instructor() {};
	~Instructor() 
	{
//		std::cout << "\n���������� �����������";
	};
	Instructor(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	// �������� ������ ���� ���������� �����������
	std::vector<Employee> GetAllListeners()
	{
		return mListeners;
	}
	// �������� ������ ���� ����������� �����������
	std::vector<Employee> GetAllGraduated()
	{
		return mGraduated;
	}
	// ������� ���������
	void ReceiveListener(Employee emp)
	{
		mListeners.push_back(emp);
	}
	// ���������� ���������
	void DeleteListener(Employee emp)
	{
		bool isDeleted = false;
		for (unsigned int i = 0; i < mListeners.size(); i++)
		{
			if (mListeners[i] == emp)
			{
				std::string deleted_person = mListeners[i].GetName();
				mListeners.erase(mListeners.begin() + i);
				std::cout << "\n��������� " << deleted_person << " ������� ���������!" << std::endl;
				isDeleted = true;
				break;
			}
		}
		if (!isDeleted)
			std::cout << "\n��������� [" << emp.GetName() << "] �� ������!" << std::endl;
	}
	// ��������� ��������� � ������ ���������
	void GraduateListener(Employee emp)
	{
		bool isGraduated = false;
		for (unsigned int i = 0; i < mListeners.size(); i++)
		{
			if (mListeners[i] == emp)
			{
				std::string graduated_person = mListeners[i].GetName();
				// ���� �������, �� ������� �� ���������� � ��������� � ���������
				mGraduated.push_back(emp);
				mListeners.erase(mListeners.begin() + i);
				std::cout << "\n��������� " << graduated_person << " ������� �������� ��������!" << std::endl;
				isGraduated = true;
				break;
			}
		}
		if (!isGraduated)
			std::cout << "\n��������� [" << emp.GetName() << "] �� ������!" << std::endl;
	}

};

// ������ �������� � ����� ������� �������, ������� �������� ������������ ��� ��������
class Scientist : public Employee
{
public:
	// ����� ��� �������� ���������� �� ������������
	class Experiment
	{
	public:
		Experiment() {}
		~Experiment() 
		{
//			std::cout << "\n���������� ������������"; 		
		}
		Employee subject;	// ����������
		std::string date;	// ����� � ���� ������������
		bool result;		// ��������� ������������
		// ���������� ��������� ������ ���������� �� ������������
		friend std::ostream &operator<< (std::ostream &out, Experiment &exp)
		{
			out << "\n����������: " << exp.subject.GetName();
			out << "\n���� ������������: " << exp.date;
			out << "\n���������: ";
			if (exp.result) out << "�����";
			else out << "������";
			return out;
		}
	};
	Scientist(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	~Scientist() 
	{
//		std::cout << "\n���������� �������"; 		
	};
	// ������� �����������, ��������� ���������� �������, ������������� ������� �����
	void NewExperiment(Employee subject, bool result)
	{
		Experiment new_one;
		new_one.subject = subject;
		new_one.result = result;
		// ���� � �� ���������� �� �������� � C++, ����� ��������� ������� ��� �������� ����
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		std::stringstream ss;
		ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
		new_one.date = ss.str();
		mExperiments.push_back(new_one);	// ���������� � ������ ���� ������������� �������
	}
	// �������� ������ ���� ������������� �������
	std::vector<Experiment> GetAllExperiments()
	{
		return mExperiments;
	}
private:
	std::vector<Experiment> mExperiments; // ������ ���� ������������� �������
};