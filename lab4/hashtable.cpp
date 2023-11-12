#include "hashtable.h"

void HashTable::MakePearsonTable()
{
    std::srand(std::time(nullptr));
    for(int i = 0; i < _capacity; i++)
    {
        _pearsonTable[i] = i;
    }
    for(int i = 0; i < _capacity; i++)
    {
        int swapIndex = std::rand() % _capacity;
        int temp = _pearsonTable[i];
        _pearsonTable[i] = _pearsonTable[swapIndex];
        _pearsonTable[swapIndex] = temp;
    }
}

HashTable::HashTable(const int & capacity)
{
    _capacity = capacity;
    _lenght = 0;
    _pearsonTable = new int[_capacity];
    MakePearsonTable();
    _data = new HashTableItem*[_capacity];
    for (int i = 0; i < _capacity; i++)
    {
        _data[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < _capacity; i++)
    {
        delete _data[i];
    }
    delete[] _data;
    delete[] _pearsonTable;
}

int HashTable::GetHashCode(const string &key)
{
    int hash = key.length();
    for (int i = 0; i < key.length(); i++)
    {
        hash = _pearsonTable[(hash + key[i]) % _capacity];
    }
    return hash;
}

void HashTable::Add(const string & key, const string & value)
{
    int hashCode = GetHashCode(key);
    if (!_data[hashCode])
    {
        _data[hashCode] = new HashTableItem(key, value);
        _lenght++;
    }
    else
    {
        if (_data[hashCode]->Key == key)
        {

        }
        else
        {

        }
    }
}

void HashTable::Delete(const string & key)
{
    int hashCode = GetHashCode(key);
    if (_data[hashCode])
    {
        HashTableItem *temp = _data[hashCode];
        while (temp)
        {
            if (temp->Key == key)
            {
                delete _data[hashCode];
                _data[hashCode] = nullptr;
                _lenght--;
            }
            temp = temp->Next;
        }
    }
}

string HashTable::Search(const string & key)
{

    return "a";
}










