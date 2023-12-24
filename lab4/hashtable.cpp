#include "hashtable.h"

int* HashTable::MakePearsonTable()
{
    int* pearsonTable = new int[_capacity];
    std::srand(std::time(nullptr));
    for(int i = 0; i < _capacity; i++)
    {
        pearsonTable[i] = i;
    }
    for(int i = 0; i < _capacity; i++)
    {
        int swapIndex = rand() % _capacity;
        int temp = pearsonTable[i];
        pearsonTable[i] = pearsonTable[swapIndex];
        pearsonTable[swapIndex] = temp;
    }
    return pearsonTable;
}

HashTable::HashTable(const int & capacity)
{
    _capacity = capacity;
    _length = 0;
    _pearsonTable = MakePearsonTable();
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
        HashTableItem *enumerate = _data[i];
        while(enumerate)
        {
            HashTableItem *temp = enumerate;
            enumerate = enumerate->Next;
            delete temp;
        }
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

void HashTable::Rehashig(const int &capacity)
{
    int prevCapacity = _capacity;
    HashTableItem** oldData = _data;
    _capacity = capacity;
    delete[] _pearsonTable;
    _pearsonTable = MakePearsonTable();
    _data = new HashTableItem*[_capacity];
    for (int i = 0; i < _capacity; i++)
    {
        _data[i] = nullptr;
    }
    _length = 0;
    for (int i = 0; i < prevCapacity; i++)
    {
        HashTableItem *enumerate = oldData[i];
        while (enumerate)
        {
            HashTableItem *temp = enumerate;
            int hashCode = GetHashCode(enumerate->Key);
            _data[hashCode] = AddRightOrder(_data[hashCode], enumerate->Key, enumerate->Value);
            enumerate = enumerate->Next;
            delete temp;
            _length++;
        }
    }
    delete[] oldData;
}

HashTableItem* HashTable::AddRightOrder(HashTableItem* item, const string &key, const string &value)
{
    if (item == nullptr)
    {
        return new HashTableItem(key, value);
    }
    item->Next = AddRightOrder(item->Next, key, value);
    return item;
}

HashTableItem* HashTable::ResolveCollision(HashTableItem* item, const string &key, const string &value)
{
    if (item == nullptr)
    {
        return new HashTableItem(key, value);
    }
    if (key == item->Key)
    {
        return new HashTableItem(key, value, item);
    }
    else
    {
        item->Next = ResolveCollision(item->Next, key, value);
        return item;
    }
}

void HashTable::Add(const string &key, const string &value)
{
    int hashCode = GetHashCode(key);
    if (_data[hashCode] == nullptr)
    {
        _data[hashCode] = new HashTableItem(key, value);
    }
    else
    {
        _data[hashCode] = ResolveCollision(_data[hashCode], key, value);
    }
    _length++;
    if (_length >= _capacity)
    {
        Rehashig(_capacity * 2);
    }
}

HashTableItem* HashTable::Delete(HashTableItem* item, const string &key)
{
    if (item == nullptr)
    {
        return nullptr;
    }
    if (item->Key == key)
    {

        HashTableItem* nextItem = item->Next;
        delete item;
        _length--;
        return Delete(nextItem, key);
    }
    else
    {
        item->Next = Delete(item->Next, key);
        return item;
    }
}

void HashTable::Delete(const string &key)
{
    int hashCode = GetHashCode(key);
    HashTableItem *temp = _data[hashCode];
    _data[hashCode] = Delete(temp, key);
    if (_length <= _capacity && _capacity > _minCapacity)
    {
        Rehashig(_capacity / 2);
    }
}

HashTableItem * HashTable::Search(const string & key, int hashCode)
{
    if (hashCode == -1)
    {
        hashCode = GetHashCode(key);
    }
    HashTableItem *temp = _data[hashCode];
    while (temp)
    {
        if (temp->Key == key)
        {
            return temp;
        }
        temp = temp->Next;
    }
    return nullptr;
}

const int *HashTable::GetPearsonTable() const
{
    return _pearsonTable;
}

HashTableItem** HashTable::GetData() const
{
    return _data;
}

int HashTable::GetCapacity() const
{
    return _capacity;
}

int HashTable::GetLenght() const
{
    return _length;
}
