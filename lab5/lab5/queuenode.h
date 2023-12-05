#ifndef QUEUENODE_H
#define QUEUENODE_H

#include "binarytreenode.h"

struct QueueNode
{
    BinaryTreeNode* Data;
    QueueNode* Next;
    int Depth;

    QueueNode(BinaryTreeNode* data = nullptr, const int & depth = 0, QueueNode* Next = nullptr);
};

#endif // QUEUENODE_H
