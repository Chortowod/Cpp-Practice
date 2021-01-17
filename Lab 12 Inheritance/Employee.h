#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS (иначе std::localtime не работает - решение временное, пока не пойму суть)
#include <chrono>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

// Самый обычный работник, которого только-только приняли
class Employee
{
private:
	std::string mName;		// имя
	std::string mSurname;	// фамилия
	std::string mPatname;	// отчество
	std::string mPhone;		// номер телефона
public:
	Employee() {};
	~Employee() 
	{ 
//		std::cout << "\nДеструктор Работника"; 
	};
	Employee(std::string name, std::string surname, std::string patname, std::string phone) :
		mName(name), mSurname(surname), mPatname(patname), mPhone(phone) {};
	// получить строку с ФИО
	std::string GetName()
	{
		return mSurname + " " + mName + " " + mPatname;
	}
	// перегрузка оператора вывода для экземпляра класса
	friend std::ostream &operator<< (std::ostream &out, const Employee &emp)
	{
		out << emp.mSurname << " " << emp.mName << " " << emp.mPatname << " | Телефон: " << emp.mPhone << std::endl;
		return out;
	}
	// перегрузка оператора сравнения
	friend bool operator== (const Employee emp1, const Employee &emp2)
	{
		if (emp1.mName == emp2.mName && emp1.mSurname == emp2.mSurname && emp1.mPatname == emp2.mPatname && emp1.mPhone == emp2.mPhone)
			return true;
		else
			return false;
	}
};

// Менеджер, который имеет в подчинении несколько обычных работников, 
// которых он может нанимать в свой отдел и увольнять
class Manager : public Employee
{
private:
	std::vector<Employee> mSubordinates;	// список работников в подчинении
public:
	Manager() {};
	~Manager() 
	{ 
//		std::cout << "\nДеструктор Менеджера"; 
	};
	Manager(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	// получить список всех работников в подчинении
	std::vector<Employee> GetAllSubordinates()
	{
		return mSubordinates;
	}
	// принять работника в отдел
	void ReceiveEmployee(Employee emp)
	{
		mSubordinates.push_back(emp);
	}
	// уволить работника из отдела
	void FireEmployee(Employee emp)
	{
		bool isFired = false;
		// ищем работника
		for (unsigned int i = 0; i < mSubordinates.size(); i++)
		{
			if (mSubordinates[i] == emp) //для этого перегружали оператор сравнения
			{
				// сохраняем ФИО для отображения инфы об удалении
				std::string fired_person = mSubordinates[i].GetName(); 
				// удаляем
				mSubordinates.erase(mSubordinates.begin() + i);
				// инфа об успехе
				std::cout << "\nРаботник [" << fired_person << "] успешно уволен!" << std::endl;
				isFired = true;
				break;
			}
		}
		if (!isFired) // если работник не нашелся, то сообщаем
			std::cout << "\nРаботник [" << emp.GetName() << "] не найден!" << std::endl;
	}
};

// Инструктор, у которого есть слушатели его лекций, которых он может выгнать,
// а также список тех, кто закончил у него обучение
class Instructor : public Employee
{
private:
	std::vector<Employee> mListeners; // список всех слушателей инструктора
	std::vector<Employee> mGraduated; // список всех выпускников инструктора
public:
	Instructor() {};
	~Instructor() 
	{
//		std::cout << "\nДеструктор Инструктора";
	};
	Instructor(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	// получить список всех слушателей инструктора
	std::vector<Employee> GetAllListeners()
	{
		return mListeners;
	}
	// получить список всех выпускников инструктора
	std::vector<Employee> GetAllGraduated()
	{
		return mGraduated;
	}
	// принять слушателя
	void ReceiveListener(Employee emp)
	{
		mListeners.push_back(emp);
	}
	// вычеркнуть слушателя
	void DeleteListener(Employee emp)
	{
		bool isDeleted = false;
		for (unsigned int i = 0; i < mListeners.size(); i++)
		{
			if (mListeners[i] == emp)
			{
				std::string deleted_person = mListeners[i].GetName();
				mListeners.erase(mListeners.begin() + i);
				std::cout << "\nСлушатель " << deleted_person << " успешно вычеркнут!" << std::endl;
				isDeleted = true;
				break;
			}
		}
		if (!isDeleted)
			std::cout << "\nСлушатель [" << emp.GetName() << "] не найден!" << std::endl;
	}
	// перенести слушателя в список обученных
	void GraduateListener(Employee emp)
	{
		bool isGraduated = false;
		for (unsigned int i = 0; i < mListeners.size(); i++)
		{
			if (mListeners[i] == emp)
			{
				std::string graduated_person = mListeners[i].GetName();
				// если находим, то удаляем из слушателей и добавляем в обученных
				mGraduated.push_back(emp);
				mListeners.erase(mListeners.begin() + i);
				std::cout << "\nСлушатель " << graduated_person << " успешно закончил обучение!" << std::endl;
				isGraduated = true;
				break;
			}
		}
		if (!isGraduated)
			std::cout << "\nСлушатель [" << emp.GetName() << "] не найден!" << std::endl;
	}

};

// Вместо рабочего я решил сделать ученого, который проводит эксперименты над рабочими
class Scientist : public Employee
{
public:
	// класс для хранения информации об эксперименте
	class Experiment
	{
	public:
		Experiment() {}
		~Experiment() 
		{
//			std::cout << "\nДеструктор Эксперимента"; 		
		}
		Employee subject;	// подопытный
		std::string date;	// время и дата эксперимента
		bool result;		// результат эксперимента
		// перегрузка оператора вывода информации об эксперименте
		friend std::ostream &operator<< (std::ostream &out, Experiment &exp)
		{
			out << "\nИспытуемый: " << exp.subject.GetName();
			out << "\nДата эксперимента: " << exp.date;
			out << "\nРезультат: ";
			if (exp.result) out << "успех";
			else out << "провал";
			return out;
		}
	};
	Scientist(std::string name, std::string surname, std::string patname, std::string phone) :
		Employee(name, surname, patname, phone) {};
	~Scientist() 
	{
//		std::cout << "\nДеструктор Ученого"; 		
	};
	// создаем эксперимент, заполняем введенными данными, устанавливаем текущее время
	void NewExperiment(Employee subject, bool result)
	{
		Experiment new_one;
		new_one.subject = subject;
		new_one.result = result;
		// пока я не разобрался со временем в C++, нашел временное решение для хранения даты
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		std::stringstream ss;
		ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
		new_one.date = ss.str();
		mExperiments.push_back(new_one);	// отправляем в список всех экспериментов ученого
	}
	// получаем список всех экспериментов ученого
	std::vector<Experiment> GetAllExperiments()
	{
		return mExperiments;
	}
private:
	std::vector<Experiment> mExperiments; // список всех экспериментов ученого
};