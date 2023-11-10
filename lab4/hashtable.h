#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashtableitem.h"
#include <random>
#include <ctime>
using std::uint8_t;

class HashTable
{
private:
    static const int BYTE = 256;
    uint8_t _pearsonTable[BYTE];
    HashTableItem** _data;

    void MakePearsonTable();
    int GetHashCode(const string &key);

public:
    HashTable();
    ~HashTable();
};

#endif // HASHTABLE_H
