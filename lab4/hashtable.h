#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashtableitem.h"
#include <random>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

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
    void ResolveCollision(HashTableItem* item, const string & key, const string & value);

public:
    HashTable(const int & capacity = 4);
    ~HashTable();

    void Add(const string & key, const string & value);
    bool Delete(const string & key);
    HashTableItem * Search(const string & key, const int & hashCode);
    void ShowPearsonTable();
    void Show();
};

#endif // HASHTABLE_H
