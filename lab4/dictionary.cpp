#include "dictionary.h"

void Dictionary::Add(const string & key, const string & value)
{
    _hashTable.Add(key, value);
}

bool Dictionary::Delete(const string & key)
{
    return _hashTable.Delete(key);
}

string Dictionary::Search(const string & key)
{
    HashTableItem *temp = _hashTable.Search(key);
    return temp ? temp->Value : "";
}

void Dictionary::Show()
{
    if (!_hashTable.GetLenght())
    {
        cout << "Dictionary is empty\n";
        return;
    }

    HashTableItem **data = _hashTable.GetData();
    int capacity = _hashTable.GetCapacity();
    int counter = 0;

    cout << "Dictionary:\t{ ";
    for (int i = 0; i < capacity; i++)
    {
        HashTableItem *temp = data[i];
        while (temp)
        {
            counter++;
            if (counter % 3 == 0)
            {
                cout << "\n->\t\t  ";
            }
            cout << "\"" << temp->Key << "\" : \"" << temp->Value << "\", ";
            temp = temp->Next;
        }
    }
    cout << "\b\b }  \n";
}

void Dictionary::ShowHashTable()
{
    _hashTable.Show();
}

void Dictionary::ShowPearsonTable()
{
    _hashTable.ShowPearsonTable();
}
