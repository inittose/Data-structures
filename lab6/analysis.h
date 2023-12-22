#pragma once
#include <string.h>
#include <iostream>

/*!
 * \brief Проанализировать деревья и получить таблицы
 * \param startPower Начальная степень десяти
 * \param measureCount Количество измерений
 */
void AnalyzeTrees(const int &startPower = 5, const int &measureCount = 3);

/*!
 * \brief Сравнение на максимальное число
 * \param max Максимальное число
 * \param value Новое число
 */
void SetMax(int &max, const int &value);

/*!
 * \brief Перевести значение в строку
 * \param value Значение
 */
template <typename Type>
std::string to_string(const Type& value);

/*!
 * \brief Получить случайное число в диапазоне
 * \param min Нижний диапазон
 * \param max Верхний диапазон
 * \return Случайное число
 */
int GetRandomNumber(const int &min, const int &max);

/*!
 * \brief Добавить в дерево элементы
 * \param tree Дерево
 * \param maxNodes Количество добавляемых элементов
 * \param seed Число для задания случайной генерации
 */
template <typename Tree>
void SetTree(Tree &tree, const long long &maxNodes, const int &seed = 0);

/*!
 * \brief Получить данные измерения вставки
 * \param tree Дерево
 * \param maxNodes Количество вставляемых узлов
 * \param seed Число для задания случайной генерации
 * \return Две строки с данными
 */
template <typename Tree>
std::pair<std::string, std::string> GetAddingMeasures(Tree &tree, const long long &maxNodes, const int &seed = 0);

/*!
 * \brief Получить данные измерения удаления
 * \param tree Дерево
 * \param maxNodes Количество удаляемых узлов
 * \param seed Число для задания случайной генерации
 * \return Две строки с данными
 */
template <typename Tree>
std::pair<std::string, std::string> GetRemovingMeasures(Tree &tree, const long long &maxNodes, const int &seed = 0);
