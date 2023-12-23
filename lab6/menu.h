#pragma once
#include <string>
#include <iostream>

using std::string, std::cin, std::cout, std::endl;

/*!
 * \brief Меню и управление красно-черным деревом
 */
void ControllerRBTree();

/*!
 * \brief Меню и управление АВЛ-деревом
 */
void ControllerAVLTree();

/*!
 * \brief Главное меню и выбор структур данных для работы
 */
void MainController();

/*!
 * \brief Ввод с проверкой
 * \param variable Переменная любого типа данных
 */
template <typename T>
void ValidInput(T& variable);


/*!
 * \brief Вывод дерева
 * \param tree Указатель на дерево
 */
template <typename Tree, typename Node>
void ShowTree(Tree* tree);

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char* letter);

/*!
 * \brief Конвертация typename в название дерева
 * \param name Строка typename
 * \return Строка название дерева
 */
string GetTreeName(const std::type_info& type);

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal();

/*!
 * \brief Возведение в степень
 * \param number Число
 * \param power Степень
 * \return Число возведенное в степень
 */
int Power(const int& number, const int& power);

/*!
 * \brief Получение количества знаков числа
 * \param number Число
 * \return Количество знаков у числа
 */
int DigitPlace(int number);
