#pragma once
#include <string>
using std::string;

/*!
 * \brief Структура элемента хеш-таблицы
 */
struct HashTableItem
{
    /*!
     * \brief Ключ
     */
    string Key;

    /*!
     * \brief Значение
     */
    string Value;

    /*!
     * \brief Указатель на следующий элемент
     */
    HashTableItem* Next;

    /*!
    * \brief Конструктор элемента хэш-таблицы
    * \param key Ключ
    * \param value Значение
    * \param prev Предыдущий элемент
    * \param next Следующий элемент
    */
    HashTableItem(const string &key, const string &value, HashTableItem* next = nullptr);
};
