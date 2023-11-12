#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashtableitem.h"
#include <random>
#include <ctime>

class HashTable
{
private:
    int _capacity;
    int _lenght;
    int *_pearsonTable;
    HashTableItem** _data;

    void MakePearsonTable();
    int GetHashCode(const string &key);
    void Rehashig(const int & capacity);
    void ResolveCollision(HashTableItem* item);

public:
    HashTable(const int & capacity = 8);
    ~HashTable();

    void Add(const string & key, const string & value);
    void Delete(const string & key);
    string Search(const string & key);

};

#endif // HASHTABLE_H
