#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"

void lab12()
{
	// Оценки студента
	std::vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	student *stud = new student("Петров", "Иван", "Алексеевич", scores);
	std::cout << stud->get_full_name() << std::endl;
	std::cout << "Средний балл: " << stud->get_average_score() << std::endl;

	teacher *tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", 40);
	std::cout << tch->get_full_name() << std::endl;
	std::cout << "Количество часов: " << tch->get_work_time() << std::endl;
}

void lab12_itog() 
{
	// создаем обычных работников (чтобы проще было отличать, у имени каждого - разное число)
	Employee *emp1 = new Employee("Афанасий1", "Кекеров", "Витальевич", "8-966-433-24-00");
	Employee *emp2 = new Employee("Афанасий2", "Кекеров", "Витальевич", "8-966-433-24-00");
	Employee *emp3 = new Employee("Афанасий3", "Кекеров", "Витальевич", "8-966-433-24-00");
	Employee *emp4 = new Employee("Афанасий4", "Кекеров", "Витальевич", "8-966-433-24-00");
	Employee *emp5 = new Employee("Афанасий5", "Кекеров", "Витальевич", "8-966-433-24-00");
	Employee *emp6 = new Employee("Афанасий6", "Кекеров", "Витальевич", "8-966-433-24-00");

	// создаем менеджера
	Manager *empManager = new Manager("Василий", "Попов", "Александрович", "8-965-424-23-54");
	std::cout << "\nМенеджер: " << *empManager;

	// добавляем работников в отдел менеджера
	empManager->ReceiveEmployee(*emp1);
	empManager->ReceiveEmployee(*emp2);
	empManager->ReceiveEmployee(*emp3);
	empManager->ReceiveEmployee(*emp4);
	empManager->ReceiveEmployee(*emp5);
	// удаляем работника 3
	empManager->FireEmployee(*emp3);
	// пробуем удалить работника 6, которого нет в отделе
	empManager->FireEmployee(*emp6);

	std::cout << "\nСписок всех работников менеджера:\n";
	for (auto &value : empManager->GetAllSubordinates())
		std::cout << value;

	std::cout << "\n---------------------------------------------------------------------\n";

	// создаем инструктора
	Instructor *empInstructor = new Instructor("Никита", "Волколамский", "Осипович", "8-922-554-11-23");
	std::cout << "\nИнструктор: " << *empInstructor;

	// записываем слушателей к инструктору
	empInstructor->ReceiveListener(*emp1);
	empInstructor->ReceiveListener(*emp2);
	empInstructor->ReceiveListener(*emp3);
	empInstructor->ReceiveListener(*emp4);
	empInstructor->ReceiveListener(*emp5);
	// удаляем слушателя 2
	empInstructor->DeleteListener(*emp2);
	// сотрудники 4 и 5 закончили обучение и являются выпускниками инструктора
	empInstructor->GraduateListener(*emp4);
	empInstructor->GraduateListener(*emp5);

	std::cout << "\nСписок всех слушателей инструктора:\n";
	for (auto &value : empInstructor->GetAllListeners())
		std::cout << value;

	std::cout << "\nСписок всех выпускников инструктора:\n";
	for (auto &value : empInstructor->GetAllGraduated())
		std::cout << value;

	std::cout << "\n---------------------------------------------------------------------\n";

	// создаем ученого
	Scientist *empScientist = new Scientist("Андрей", "Сахаров", "Константинович", "8-933-545-23-99");
	std::cout << "\nУченый: " << *empScientist;

	// добавляем экспериментов
	empScientist->NewExperiment(*empManager, false);
	empScientist->NewExperiment(*emp2, false);
	empScientist->NewExperiment(*emp3, true);

	// смотрим все эксперименты
	for (auto &value : empScientist->GetAllExperiments())
		std::cout << value << std::endl;

	// высвобождаем память
	delete emp1;
	delete emp2;
	delete emp3;
	delete emp4;
	delete emp5;
	delete emp6;
	delete empManager;
	delete empInstructor;
	delete empScientist;
}

int main()
{
	system("chcp 1251");
	lab12_itog();
}