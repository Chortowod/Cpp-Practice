#pragma once
#include <string>
struct StudentGrade
{
	std::string name;
	char grade;
	StudentGrade() {}
	StudentGrade(std::string name, char grade)
	{
		StudentGrade::name = name;
		StudentGrade::grade = grade;
	}
	
};
