#include "task.h"




void Task::display_toDay(int d, int m, int y)
{
	std::ifstream listFile;
	listFile.open("List.txt", std::ios::in);

	if (listFile.is_open())
	{
		std::cout << "\n-----------------------------------------------TASKS--------------------------------------------------------\n\n";
		std::cout << "--------------------------------------------------------------------------------------------------------\n";
		std::cout << "\t\t\tDATE \t\t TIME \t\t  DISCREPTION\n";
		std::cout << "--------------------------------------------------------------------------------------------------------\n";

		while (listFile.read((char*)this, sizeof(Task)))   
		{
			if (d == Day && Mon == m+1 && Year == y)
			{
				std::cout.fill('0');
				std::cout << "\t\t\t" << std::setw(2) << Day << "-" << std::setw(2) << Mon << "-" << Year << " \t " << std::setw(2) << Hour << ":" << std::setw(2) << Min << " \t\t  " << description << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------\n";
			}
		}
	}

	else
	{
		std::cout << "\n\t\t\t  Failed to open file\n\n";
		return;
	}

	listFile.close();
}


void Task::add_task()
{
	system("cls");

	std::ofstream listFile;
	listFile.open("List.txt", std::ios::app);

	std::cout << "\t---------------------------\n";
	std::cout << "\n\t\t TASK DETAILS\n";
	std::cout << "\t---------------------------\n\n";

	std:: cout << "\t Date : ";
	std::cin >> Day >> Mon >> Year;
	std::cout << "\n\t Time : ";
	std::cin >> Hour >> Min;
	std::cout << "\n\t Description : ";
	std::cin.ignore();
    std::getline(std::cin, description);

	listFile.write((char*)this, sizeof(Task));
    
	system("cls");

	std::cout << "\n\n\t\t Task saved successfully";
	_getch();

	listFile.close();
}

void Task::display_all()
{
	std::ifstream listFile;
	listFile.open("List.txt", std::ios::in);

	listFile.read((char*)this, sizeof(Task));

	if (listFile.is_open())
	{
		system("cls");
		std::cout << "\n---------------------------------------------TASKS-------------------------------------------------\n\n";
		std::cout << "--------------------------------------------------------------------------------------------------------\n";
		std::cout << "\t\t\tDATE \t\t TIME \t\t  DISCREPTION\n\n";
		std::cout << "--------------------------------------------------------------------------------------------------------\n";

		while (!listFile.eof())
		{
			std::cout.fill('0');
			std::cout << "\t\t\t" << std::setw(2) << Day << "-" << std::setw(2) << Mon << "-" << Year << " \t " << std::setw(2) << Hour << ":" << std::setw(2) << Min << " \t\t  " << description << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------\n";
			
			listFile.read((char*)this, sizeof(Task));
		}

		std::cout << "\n\t\t Press any key to continue\n";
		_getch();
	}
	else
	{
		std::cout << "\n\t\tFailed to open file\n";
		_getch();
		return;
	}

	listFile.close();
}


void Task::display_task()
{
	std::ifstream listFile;
	listFile.open("List.txt", std::ios::in);

	int op;

	std::string tmp;
	std::cout << "\n\n\t\t Enter task desciption : ";
	std::cin >> tmp;

	if (!isExist(tmp))
	{
		system("cls");
		std::cout << "\n\t\t Task not found\n";
		_getch();
	}
	else
	{
		while (!listFile.eof())
		{
			listFile.read((char*)this, sizeof(Task));

			if (description == tmp)
			{
				system("cls");
				std::cout << "\n-----------------------------------------------TASKS--------------------------------------------------------\n\n";
				std::cout << "--------------------------------------------------------------------------------------------------------\n";
				std::cout << "\t\t\tDATE \t\t TIME \t\t  DISCREPTION\n";
				std::cout << "--------------------------------------------------------------------------------------------------------\n";
				std::cout.fill('0');
				std::cout << "\t\t\t" << std::setw(2) << Day << "-" << std::setw(2) << Mon << "-" << Year << " \t " << std::setw(2) << Hour << ":" << std::setw(2) << Min << " \t\t  " << description << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------\n";
				break;
			}
		}

		listFile.close();

		std::cout << "\n\t\t\t[1] Edit \t [2] Delete \t [3] Exit\n";

		std::cout << "\n\t\t\t>Choice: ";
		std::cin >> op;

		switch (op)
		{
		case 1: update_task(tmp);
			break;

		case 2: delete_task(tmp);
			break;

		case 3: break;
			break;

		default: std::cout << "\n\t\t\t Invalid choice";
			_getch();
			break;
		}
	}
}

bool Task::isExist(std::string tmp)
{
	std::ifstream listFile;
	listFile.open("List.txt", std::ios::in);

	while (!listFile.eof())
	{
		listFile.read((char*)this, sizeof(Task));

		if (description == tmp)
		{
			return true;
		}
	}

	listFile.close();

	return false;
}


void Task::update_task(std::string tmp)
{
	std::fstream listFile;
	listFile.open("List.txt", std::ios::in | std::ios::out);

	if (listFile.is_open())
	{
		while (listFile.read((char*)this, sizeof(Task)))
		{
			if (description == tmp)
			{
				system("cls");

				std::cout << "\n\n\t\t Enter new details :\n\n";
				std::cout << "\t\t Date : ";
				std::cin >> Day >> Mon >> Year;
				std::cout << "\n\t\t Time : ";
				std::cin >> Hour >> Min;
				std::cin.ignore();
				std::cout << "\n\t\t Description : ";
				std::cin.ignore();
				std::getline(std::cin, description);

				int pos = -1 * static_cast<int>(sizeof(Task));
				listFile.seekp(pos, std::ios::cur);
				listFile.write((char*)this, sizeof(Task));

				std::cout << "\n\t\t\t Task modified successfully\n";
				_getch();

				break;
			}
		}
	}
	else
	{
		std::cout << "\n\t\tFailed to open file\n";
		exit(-1);
	}

	listFile.close();
	system("cls");
}


void Task::delete_task(std::string tmp)
{
	std::fstream listFile("List.txt", std::ios::in);
	std::fstream newFile("tempFile.txt", std::ios::app);

	while (listFile.read((char*)this, sizeof(Task)))
	{
		if (description != tmp)
		{
			newFile.write((char*)this, sizeof(Task));
		}
	}

	listFile.close();
	newFile.close();
	remove("List.txt");
	rename("tempFile.txt", "List.txt");
	
	system("cls");

	std::cout << "\n\t\t\t Task was deleted successfully\n";
	_getch();
	return;
}


void Task::reminder(int hour, int min)
{
	std::ifstream listFile;
	listFile.open("List.txt", std::ios::in);

	if (Hour == hour && Min == min)
	{
		std::cout << "\n\t\t        ------------------------------------------------------\n";
		std::cout << "\t\t        --------------------  REMINDER  ----------------------\n";
		std::cout << "\t\t        ------------------------------------------------------\n";

		std::cout << "\n \t\t\t\t  It's time to : " << description;
		std::cout << "\n\n\t\t----------------------------------------------------------------------------\n\n";
	}

	listFile.close();
}