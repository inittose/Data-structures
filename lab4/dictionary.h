#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "hashtable.h"

/*!
 * \brief Класс словаря
 */
class Dictionary
{
private:
    /*!
     * \brief Хеш-таблица
     */
    HashTable _hashTable;

public:
    void Add(const string & key, const string & value);
    bool Delete(const string & key);
    string Search(const string & key);

    void Show();
    void ShowHashTable();
    void ShowPearsonTable();
};

#endif // DICTIONARY_H
