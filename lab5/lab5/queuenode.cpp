#include "queuenode.h"

QueueNode::QueueNode(BinaryTreeNode* data, const int & depth, QueueNode* next)
{
    Data = data;
    Depth = depth;
    Next = next;
}
