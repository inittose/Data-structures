#pragma once

#include "hashtableitem.h"
#include <random>
#include <ctime>

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
    int _length;

    /*!
     * \brief Таблицы Пирсона
     */
    int* _pearsonTable;

    /*!
     * \brief Данные таблицы
     */
    HashTableItem** _data;

    /*!
    * \brief Создание новой таблицы Пирсона
    */
    int* MakePearsonTable();

    /*!
    * \brief Найти хеш-код
    * \param key Ключ
    * \return Хеш-код
    */
    int GetHashCode(const string &key);

    /*!
    * \brief Перехеширование
    * \param capacity Новая мощность хеш-таблицы
    */
    void Rehashig(const int & capacity);

    /*!
    * \brief Разрешение коллизии
    * \param item Конфликтный элемент
    * \param key Ключ
    * \param value Значение
    */
    HashTableItem* ResolveCollision(HashTableItem* item, const string &key, const string &value);

    HashTableItem* Delete(HashTableItem* item, const string &key);

public:

    /*!
    * \brief Конструктор
    * \param capacity Мощность хеш-таблицы
    */
    HashTable(const int &capacity = 4);

    /*!
    * \brief Деструктор
    */
    ~HashTable();

    /*!
    * \brief Добавление ключ-значения в таблицу
    * \param key Ключ
    * \param value Значение
    */
    void Add(const string &key, const string &value);

    /*!
    * \brief Удаление ключ-значения из таблицы
    * \param key Ключ
    * \return Статус удаления
    */
    bool Delete(const string &key);

    /*!
    * \brief Поиск значения по ключу
    * \param key Ключ
    * \return Нужный элемент хеш-таблицы
    */
    HashTableItem* Search(const string &key, int hashCode = -1);

    /*!
    * \brief Взятие данных хеш-таблицы из класса
    * \return Данные хеш-таблицы
    */
    HashTableItem **GetData() const;

    /*!
    * \brief Взятие мощности хеш-таблицы
    * \return Мощность
    */
    int GetCapacity() const;

    /*!
    * \brief Взятие занятого пространства хеш-таблицы
    * \return длина хеш-таблицы
    */
    int GetLenght() const;

    /*!
     * \brief Взятие таблицы Пирсона
     * \return Указатель на таблицу Пирсона
     */
    const int *GetPearsonTable() const;
};
