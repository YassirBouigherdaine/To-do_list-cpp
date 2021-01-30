#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<time.h>




class Task
{
	int Day, Mon, Year, Hour, Min;
	std::string description;

public:

	void display_toDay(int, int, int);

	void add_task();

	void display_task();

	void display_all();

	void update_task(std::string);

	void delete_task(std::string);

	bool isExist(std::string);

};

