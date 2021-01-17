#include "human.h"
#include <string>

class teacher : public human {
public:
	// Конструктор класса teacher
	teacher( std::string last_name, std::string name, std::string second_name, unsigned int work_time) : 
		human(last_name, name, second_name) 
	{
		this->work_time = work_time;
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