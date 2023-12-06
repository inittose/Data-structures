#ifndef QUEUENODE_H
#define QUEUENODE_H

#include "binarytreenode.h"

template <typename type>
struct QueueNode
{
    type* Data;
    QueueNode* Next;
    int Depth;

    QueueNode(type* data = nullptr, const int & depth = 0, QueueNode* next = nullptr)
    {
        Data = data;
        Depth = depth;
        Next = next;
    }
};

#endif // QUEUENODE_H
