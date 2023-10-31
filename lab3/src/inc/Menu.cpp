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
/// Очистить терминал
/// </summary>
void ClearConsole()
{
	system("clear");
}
