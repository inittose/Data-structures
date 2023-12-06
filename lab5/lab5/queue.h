#ifndef QUEUE_H
#define QUEUE_H

#include "queuenode.h"

template <typename type>
class Queue
{
private:
    QueueNode<type>* _head;
    QueueNode<type>* _tail;

public:
    Queue()
    {
        _head = nullptr;
        _tail = nullptr;
    }

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

    int GetDepth()
    {
        return _head->Depth;
    }

    void Push(type* item, const int & depth = 0)
    {
        QueueNode<type>* newQueueItem = new QueueNode(item, depth);
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

    bool IsEmpty()
    {
        return !_head;
    }
};


#endif // QUEUE_H
