#include "Menu.h"
#include <stdlib.h>
#include <iostream>

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
char MenuMessage(const char * message)
{
	char result;
	cout << message;
	ValidInput(result);
	while (cin.get() != '\n');
	ClearConsole();
	return result;
}

/// <summary>
/// Обработка режима работы
/// </summary>
/// <param name="list"> - список</param>
/// <param name="mode"> - режим работы</param>
void ModeControl(Stack& stack, const char& mode)
{
	static int firstValue;
	static int secondValue;
	static int valuesInList;
	switch (mode)
	{
	case '1':
		cout << "Enter value of adding element: ";
		ValidInput(firstValue);
		break;
	case '2':
		cout << "Enter index of deleting element: ";
		ValidInput(firstValue);
		break;
	case '3':
		cout << "Enter value of element inserting into begining: ";
		ValidInput(firstValue);
		break;
	case '4':
		cout << "Enter value of element inserting into end: ";
		ValidInput(firstValue);
		break;
	}
}

/// <summary>
/// Очистить терминал
/// </summary>
void ClearConsole()
{
	system("clear");
}
