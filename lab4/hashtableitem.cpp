#include "hashtableitem.h"

/*!
 * \brief Конструктор
 */
HashTableItem::HashTableItem()
{
    Next = nullptr;
    Prev = nullptr;
}

/*!
 * \brief Конструктор с параметрами
 */
HashTableItem::HashTableItem(const string  &key, const string &value, HashTableItem *prev, HashTableItem *next)
{
    Key = key;
    Value = value;
    Next = next;
    Prev = prev;
}

