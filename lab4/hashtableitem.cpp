#include "hashtableitem.h"

HashTableItem::HashTableItem()
{
    Next = nullptr;
    Prev = nullptr;
}

HashTableItem::HashTableItem(const string  &key, const string &value)
{
    Key = key;
    Value = value;
    Next = nullptr;
    Prev = nullptr;
}

