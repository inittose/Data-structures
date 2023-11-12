#ifndef HASHTABLEITEM_H
#define HASHTABLEITEM_H

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
    HashTableItem *Next;

    /*!
     * \brief Указатель на предыдущий элемент
     */
    HashTableItem *Prev;

    HashTableItem();
    HashTableItem(const string &key, const string &value, HashTableItem *prev = nullptr, HashTableItem *next = nullptr);
};

#endif // HASHTABLEITEM_H
