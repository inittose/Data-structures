#ifndef HASHTABLEITEM_H
#define HASHTABLEITEM_H

#include <string>
using std::string;

struct HashTableItem
{
    string Key;
    string Value;
    HashTableItem *Next;
    HashTableItem *Prev;

    HashTableItem();
    HashTableItem(const string &key, const string &value);
};

#endif // HASHTABLEITEM_H
