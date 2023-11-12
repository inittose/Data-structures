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
        int swapIndex = arc4random() % _capacity;
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

void HashTable::Rehashig(const int & capacity)
{
    int prevCapacity = _capacity;
    HashTableItem **oldData = _data;
    _capacity = capacity;
    delete[] _pearsonTable;
    _pearsonTable = new int[_capacity];
    MakePearsonTable();
    _data = new HashTableItem*[_capacity];
    for (int i = 0; i < prevCapacity; i++)
    {
        HashTableItem *enumerate = oldData[i];
        while (enumerate)
        {
            HashTableItem *temp = enumerate;
            Add(enumerate->Key, enumerate->Value);
            enumerate = enumerate->Next;
            delete temp;
        }
    }
    delete[] oldData;
}

void HashTable::ResolveCollision(HashTableItem* item, const string & key, const string & value)
{
    HashTableItem *enumerate = item;
    HashTableItem *temp = item;
    while (enumerate)
    {
        if (enumerate->Key == key)
        {
            enumerate->Value = value;
            return;
        }
        temp = enumerate;
        enumerate = enumerate->Next;
    }
    temp->Next = new HashTableItem(key, value, item);
    _lenght++;
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
        ResolveCollision(_data[hashCode], key, value);
    }

    if (_lenght == _capacity)
    {
        Rehashig(_capacity * 2);
    }
}

bool HashTable::Delete(const string & key)
{
    int hashCode = GetHashCode(key);
    HashTableItem *temp = Search(key, hashCode);
    if (temp)
    {
        HashTableItem *prev = temp->Prev;
        HashTableItem *next = temp->Next;
        if (prev)
        {
            prev->Next = next;
        }
        else
        {
            _data[hashCode] = next;
        }
        if (next)
        {
            next->Prev = prev;
        }
        delete temp;
        return true;
    }
    return false;
}

HashTableItem * HashTable::Search(const string & key, const int & hashCode)
{
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

void HashTable::ShowPearsonTable()
{
    cout << "Pearson table: ";
    for (int i = 0; i < _capacity; i++)
    {
        cout << _pearsonTable[i] << " ";
    }
    cout << endl;
}

void HashTable::Show()
{
    for (int i = 0; i < _capacity; i++)
    {
        cout << "ID " << i << ": " << endl;
        if (_data[i])
        {
            HashTableItem *temp = _data[i];
            while (temp)
            {
                cout << "\t" << temp->Key << " : " << temp->Value << endl;
                temp = temp->Next;
            }
        }
        else
        {
            cout << "\tNone\n";
        }
    }
}






