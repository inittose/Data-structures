#include "hashtableitem.h"

HashTableItem::HashTableItem(const string &key, const string &value, HashTableItem* next)
{
    Key = key;
    Value = value;
    Next = next;
}

