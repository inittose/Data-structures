#include <iostream>
#include <chrono>
#include <cmath>
#include "source/List.h"
#include "source/Menu.h"
#include "fstream"

using namespace std;

void MainProgram();
void ResearchTime();

int main()
{
	MainProgram();
	return 0;
}

void MainProgram()
{
	List list;
	char mode = '\0';
	cout << list;
	while (mode != 'q')
	{
		mode = MenuMessage(list);
		ModeControl(list, mode);
	}
}

void ResearchTime()
{
	int listLenght = 100000;
	List list;
	for (int i = 0; i < listLenght; i++)
	{
		list.InsertAtEnd(i);
	}
	ofstream delout;
	ofstream insout;

	delout.open("Delete.txt");
	insout.open("Insert.txt");

	for (int i = 0; i < listLenght; i++)
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();

		list.DeleteElement(i);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		// std::cout << "Delete index = " << i << "\tTime difference = "
		//<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
		delout << i << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

		begin = chrono::steady_clock::now();

		list.InsertBefore(i, i);
		end = chrono::steady_clock::now();

		// std::cout << "Insert index = " << i << "\tTime difference = "
		//<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
		insout << i << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;
	}
	delout.close();
	insout.close();
}