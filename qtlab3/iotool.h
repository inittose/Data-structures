#ifndef IOTOOL_H
#define IOTOOL_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/**
 *  Ввод с проверкой
 *
 *  @param "var" - переменная стандартного типа данных
 */
template <typename Type>
void ValidInput(Type & var)
{
    cin >> var;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter correct value: ";
        cin >> var;
    }
}

void ClearTerminal();

#endif // IOTOOL_H
