#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Item
{
private:
	string title;
	double price;
public:
	virtual void getdata()
	{
		cout << "\nВведите заголовок: ";
		cin >> title;
		cout << "Введите цену: ";
		cin >> price;
	}
	virtual void putdata()
	{
		cout << "\nЗаголовок: " << title;
		cout << "\nЦена:" << price;
	}
};
class Paperbook : public Item
{
private:
	int pages;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Введите число страниц: ";
		cin >> pages;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nСтраниц: " << pages;
	}
};
class AudioBook : public Item
{
private:
	double time;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Введите время звучания: ";
		cin >> time;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nВремя звучания: " << time;
	}
};