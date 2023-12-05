#include "queue.h"

Queue::Queue()
{
    _head = nullptr;
    _tail = nullptr;
}

Queue::~Queue()
{
    QueueNode* deleteItem = _head;
    while(deleteItem)
    {
        QueueNode* temp = deleteItem;
        deleteItem = deleteItem->Next;
        delete temp;
    }
}

bool Queue::IsEmpty()
{
    return !_head;
}

BinaryTreeNode* Queue::Pop()
{
    if (!_head)
    {
        return nullptr;
    }

    BinaryTreeNode* popItem = _head->Data;
    if (_head == _tail)
    {
        delete _head;
        _head = _tail = nullptr;
    }
    else
    {
        QueueNode* temp = _head;
        _head = _head->Next;
        delete temp;
    }

    return popItem;
}

void Queue::Push(BinaryTreeNode* item, const int & depth)
{
    QueueNode* newQueueItem = new QueueNode(item, depth);
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

int Queue::GetDepth()
{
    return _head->Depth;
}
