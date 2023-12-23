#pragma once

#include "dictionary.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

/*!
 * \brief Меню и управление словарем
 */
void MenuController();

/*!
 * \brief Ввод с проверкой
 * \param variable Переменная любого типа данных
 */
template <typename Type>
Type ValidInput();

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char *letter);

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal();

void ShowDictionary(Dictionary* dictionary);
void ShowHashTable(Dictionary* dictionary);
