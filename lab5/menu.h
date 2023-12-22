#pragma once
#include "binarytree.h"
#include "treap.h"
#include <iostream>
#include <string>
using std::string, std::endl, std::cout, std::cin;

/*!
 * \brief Меню и управление бинарным деревом поиска
 */
void ControllerBinaryTree();

/*!
 * \brief Меню и управление дерамидой (Декартово дерево)
 */
void ControllerTreap();

/*!
 * \brief Главное меню и выбор структур данных для работы
 */
void MainController();

/*!
 * \brief Получение количества знаков числа
 * \param number Число
 * \return Количество знаков у числа
 */
int DigitPlace(int number);

/*!
 * \brief Возведение в степень
 * \param number Число
 * \param power Степень
 * \return Число возведенное в степень
 */
int Power(const int &number, const int &power);

/*!
 * \brief Вывод бинарного дерева поиска
 * \param tree Бинарное дерево
 */
void ShowBinaryTree(BinaryTree* tree);

/*!
 * \brief Вывод дерамиды
 * \param tree Декартово дерево
 */
void ShowTreap(Treap* tree);

/*!
 * \brief Ввод с проверкой
 * \return Введенное значение
 */
template <typename T>
T ValidInput();

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char* letter);

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal();
