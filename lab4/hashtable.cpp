#include "hashtable.h"

void HashTable::MakePearsonTable()
{
    std::srand(std::time(nullptr));
    for(int i = 0; i < BYTE; i++)
    {
        _pearsonTable[i] = i;
    }
    for(int i = 0; i < BYTE; i++)
    {
        int swapIndex = std::rand() % BYTE;
        _pearsonTable[i] = (_pearsonTable[swapIndex] ^ _pearsonTable[i]);
        _pearsonTable[swapIndex] = (_pearsonTable[swapIndex] ^ _pearsonTable[i]);
        _pearsonTable[i] = (_pearsonTable[swapIndex] ^ _pearsonTable[i]);
    }
}

HashTable::HashTable()
{
    MakePearsonTable();
    _data = new HashTableItem*[BYTE];
    for (int i = 0; i < BYTE; i++)
    {
        _data[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < BYTE; i++)
    {
        delete _data[i];
    }
    delete[] _data;
}

int HashTable::GetHashCode(const string &key)
{
    uint8_t hash = key.length();
    for (int i = 0; i < key.length(); i++)
    {
        hash = _pearsonTable[hash ^ key[i]];
    }
    return hash;
}
