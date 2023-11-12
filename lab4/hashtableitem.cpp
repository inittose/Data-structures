#include "hashtableitem.h"

HashTableItem::HashTableItem()
{
    Next = nullptr;
    Prev = nullptr;
}

HashTableItem::HashTableItem(const string  &key, const string &value, HashTableItem *prev, HashTableItem *next)
{
    Key = key;
    Value = value;
    Next = next;
    Prev = prev;
}

