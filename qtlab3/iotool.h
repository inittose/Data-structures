#ifndef IOTOOL_H
#define IOTOOL_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*!
 * \brief Ввод с проверкой
 * \param var Переменная стандартного типа данных
 * \param bWrongInput Верен ли предыдущий ввод
 * \return Статус ввода
 */
template <typename Type>
bool ValidInput(Type & var, bool bWrongInput = false)
{
    if (bWrongInput)
    {
        cout << "\nPlease enter the correct menu item: ";
    }

    cin >> var;
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        var = '\0';
        return true;
    }
    else
    {
        return false;
    }
}

void ClearTerminal();

#endif // IOTOOL_H
