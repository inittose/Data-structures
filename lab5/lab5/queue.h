#ifndef QUEUE_H
#define QUEUE_H

#include "queuenode.h"

class Queue
{
private:
    QueueNode* _head;
    QueueNode* _tail;

public:
    Queue();
    ~Queue();
    BinaryTreeNode* Pop();
    int GetDepth();
    void Push(BinaryTreeNode* item, const int & depth = 0);
    bool IsEmpty();
};

#endif // QUEUE_H
