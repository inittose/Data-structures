#ifndef IOTOOL_H
#define IOTOOL_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*!
 * \brief Ввод с проверкой
 * \param var Переменная стандартного типа данных
 */
template <typename Type>
void ValidInput(Type & var, bool bWrongInput = false)
{
    if (bWrongInput)
    {
        cout << "\nPlease enter correct value: ";
    }

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
