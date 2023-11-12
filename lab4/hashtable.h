#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashtableitem.h"
#include <random>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

/*!
 * \brief Класс хеш-таблицы
 */
class HashTable
{
private:
    /*!
     * \brief Мощность
     */
    int _capacity;

    /*!
     * \brief Длина
     */
    int _lenght;

    /*!
     * \brief Таблицы Пирсона
     */
    int *_pearsonTable;

    /*!
     * \brief Данные таблицы
     */
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
    HashTableItem * Search(const string & key, int hashCode = -1);
    void ShowPearsonTable() const;
    void Show() const;

    HashTableItem** GetData() const;
    int GetCapacity() const;
    int GetLenght() const;
};

#endif // HASHTABLE_H
