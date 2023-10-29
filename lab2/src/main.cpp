#include <iostream>
#include <chrono>
#include <cmath>
#include "inc/List.h"
#include "inc/Menu.h"
#include "fstream"

using namespace std;

void MainProgram();
void ResearchTime();

int main()
{
	ResearchTime();
	return 0;
}

void MainProgram()
{
	List list;
	char mode = '\0';
	while (mode != 'q')
	{
		cout << list;
		mode = MenuMessage();
		ModeControl(list, mode);
	}
}

void ResearchTime()
{
	int numberOfLists = 9;
	ofstream delout;
	ofstream insout;

	delout.open("output/Delete.txt");
	insout.open("output/Insert.txt");

	for (int i = 1; i < numberOfLists; i++)
	{
		List list;
		int maxElement = pow(10, i);
		for (int j = 0; j < maxElement; j++)
		{
			list.InsertAtEnd(j);
		}
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();

		list.DeleteElement(maxElement);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		// std::cout << "Delete index = " << i << "\tTime difference = "
		//<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
		delout << maxElement << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

		begin = chrono::steady_clock::now();

		list.InsertAfter(maxElement, maxElement - 1);
		end = chrono::steady_clock::now();

		// std::cout << "Insert index = " << i << "\tTime difference = "
		//<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
		insout << maxElement << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;
	}
	delout.close();
	insout.close();
}
