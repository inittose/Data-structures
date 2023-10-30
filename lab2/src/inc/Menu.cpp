#include "Menu.h"
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

/// <summary>
/// Ввод с проверкой
/// </summary>
/// <typeparam name="T">любой тип данных</typeparam>
/// <param name="variable"> - вводимая переменная</param>
template <typename T>
void ValidInput(T& variable)
{
	cin >> variable;
	while (cin.fail())
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Please enter correct value: ";
		cin >> variable;
	}
}

/// <summary>
/// Меню 
/// </summary>
/// <param name="list"> - список</param>
/// <returns>Режим работы
/// </returns>
char MenuMessage()
{
	char result;
	cout << "\nChoose one of activity: \n1 - Add element \n2 - Delete element \n3 - Insert element into begining \n"
		<< "4 - Insert element into End \n5 - Insert element after given index \n6 - Insert element before given index \n7 - Sort array \n"
		<< "8 - Linear search element \nq - Quit \nYour choice: ";
	ValidInput(result);
	while (cin.get() != '\n');
	ClearMenu();
	return result;
}

/// <summary>
/// Обработка режима работы
/// </summary>
/// <param name="list"> - список</param>
/// <param name="mode"> - режим работы</param>
void ModeControl(List& list, const char& mode)
{
	static int firstValue;
	static int secondValue;
	static int valuesInList;
	switch (mode)
	{
	case '1':
		cout << "Enter value of adding element: ";
		ValidInput(firstValue);
		list.InsertAtEnd(firstValue);
		break;
	case '2':
		cout << "Enter index of deleting element: ";
		ValidInput(firstValue);
		list.DeleteElement(firstValue);
		break;
	case '3':
		cout << "Enter value of element inserting into begining: ";
		ValidInput(firstValue);
		list.InsertAtBeginning(firstValue);
		break;
	case '4':
		cout << "Enter value of element inserting into end: ";
		ValidInput(firstValue);
		list.InsertAtEnd(firstValue);
		break;
	case '5':
		cout << "Enter value of element: ";
		ValidInput(firstValue);
		cout << "Enter the index after which to insert the element: ";
		ValidInput(secondValue);
		list.InsertAfter(firstValue, secondValue);
		break;
	case '6':
		cout << "Enter value of element: ";
		ValidInput(firstValue);
		cout << "Enter the index before which to insert the element: ";
		ValidInput(secondValue);
		list.InsertBefore(firstValue, secondValue);
		break;
	case '7':
		cout << "Array sorted" << endl;
		list.Sort();
		break;
	case '8':
		cout << "Enter value of element needed to linear search: ";
		ValidInput(firstValue);
		valuesInList = list.LinearSearch(firstValue);
		cout << "In list " << valuesInList << " occurrences" << endl;
		break;
	default:
		break;
	}
}

/// <summary>
/// Очистить меню
/// </summary>
void ClearMenu()
{
	system("clear");
}
