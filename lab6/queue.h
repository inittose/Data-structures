#pragma once
#include "queuenode.h"

/*!
 * \brief Очередь
 */
template <typename type>
class Queue
{
private:
    /*!
     * \brief Голова очереди
     */
    QueueNode<type>* _head;

    /*!
     * \brief Хвост очереди
     */
    QueueNode<type>* _tail;

public:

    /*!
     * \brief Конструктор очереди
     */
    Queue()
    {
        _head = nullptr;
        _tail = nullptr;
    }

    /*!
     * \brief Деструктор очереди
     */
    ~Queue()
    {
        QueueNode<type>* deleteItem = _head;
        while(deleteItem)
        {
            QueueNode<type>* temp = deleteItem;
            deleteItem = deleteItem->Next;
            delete temp;
        }
    }

    /*!
     * \brief Извлечение элемента из очереди
     * \return Извлеченный элемент
     */
    type* Pop()
    {
        if (!_head)
        {
            return nullptr;
        }

        type* popItem = _head->Data;
        if (_head == _tail)
        {
            delete _head;
            _head = _tail = nullptr;
        }
        else
        {
            QueueNode<type>* temp = _head;
            _head = _head->Next;
            delete temp;
        }

        return popItem;
    }

    /*!
     * \brief Получить глубину первого элемента в очереди
     * \return Глубина элемента
     */
    int GetDepth()
    {
        return _head->Depth;
    }

    /*!
     * \brief Получить цвет первого элемента в очереди
     * \return Цвет узла
     */
    int GetColor()
    {
        return _head->Color;
    }

    /*!
     * \brief Получить глубину последнего элемента очереди
     * \return Глубина элемента
     */
    int GetMaxDepth()
    {
        return _tail->Depth;
    }

    /*!
     * \brief Добавить элемент в очередь
     * \param item Элемент
     * \param depth Глубина элемента
     * \param color Цвет элемента
     */
    void Push(type* item, const int & depth = 0, char color = 0)
    {
        QueueNode<type>* newQueueItem = new QueueNode(item, depth, color);
        if (_tail)
        {
            _tail->Next = newQueueItem;
            _tail = newQueueItem;
        }
        else
        {
            _head = _tail = newQueueItem;
        }
    }

    /*!
     * \brief Проверка пустая ли очередь
     */
    bool IsEmpty()
    {
        return !_head;
    }
};
