#include"ToDo_func.h"


Task task;

void options();



void main_menu()
{
	time_t now = time(NULL);

	char dt[26] = {};

	ctime_s(dt, 26, &now);

	tm lt = {};

	localtime_s(&lt, &now);

	asctime_s(dt, 26, &lt);

	int h = lt.tm_hour;
	int m = lt.tm_min;

	int year = 1900 + lt.tm_year;
	int mon = lt.tm_mon;
	int day = lt.tm_mday;

	std::string months[] = { "JAN", "FEB", "MAR","APR","MAY","JUN","JUL",
							"AUG","SEP","OCT","NOV","DEC" };

	do
	{
		system("cls");
		std::cout << "--------------------------------------------------------------------------------------------------------\n";
		std::cout << "\t\t\t------------------------------------------------------\n";
		std::cout << "\t\t\t------      *   * *   *  **      **   *   * \t------\n";
		std::cout << "\t\t\t---         * * *  * *   *  *   *  *   * *     \t   ---\n";
		std::cout << "\t\t\t---         *   *   *    *   * ******   *      \t   ---\n";
		std::cout << "\t\t\t---         *   *   *    *  *  *    *   *      \t   ---\n";
		std::cout << "\t\t\t------      *   *   *    **    *    *   *   \t------\n";
		std::cout << "\t\t\t------------------------------------------------------\n";
		std::cout << "\t\t\t------------------------------------------------------\n";
		std::cout << "\n\t\t\t\t\t    " << day << " " << months[mon] << " " << year;
		std::cout << "\n\t\t\t------------------------------------------------------\n";

		task.display_toDay(day, mon, year);

		std::cout << "\n\t\t\t\t Press [O] for options \n";

		// deleting switch 

		if (_kbhit())
		{
			char ch = _getch();

			if (ch == 'o')
			{
				options();
			}
		}
		
	} while (true);
}

void options()
{
	int choice;

	system("cls");

	std::cout << "\t*--------------------------------------------------*\n";
	std::cout << "\t*--------------------------------------------------*\n";
	std::cout << "\t**\t\t\t OPTIONS  \t\t  **\n";
	std::cout << "\t*--------------------------------------------------*\n";
	std::cout << "\t*--------------------------------------------------*\n";

	std::cout << "\n\t\t\t [1] New To-Do\n";
	std::cout << "\n\t\t\t [2] Search\n";
	std::cout << "\n\t\t\t [3] View all\n";
	std::cout << "\n\t\t\t [4] Exit\n";
	std::cout << "\n\t\t\t >Choice : ";

	std::cin >> choice;

	switch (choice)
	{
	case 1: creat_new_task();
		break;

	case 2: view_task();
		break;

	case 3: view_all();
		break;

	case 4: break;
		break;

	default: std::cout << "\n\t\t\t Invalid choice";
		_getch();
	}
}


void creat_new_task()
{
	task.add_task();
}

void view_task()
{
	task.display_task();
}

void view_all()
{
	task.display_all();
}
