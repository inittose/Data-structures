#include "binarytreenode.h"

//TODO: RSDN
//UPD: Укоротил строчку
BinaryTreeNode::BinaryTreeNode(const int &data, BinaryTreeNode* parent)
    : Left{nullptr}, Right{nullptr}
{
    Data = data;
    Parent = parent;
}

