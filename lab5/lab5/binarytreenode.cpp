#include "binarytreenode.h"

BinaryTreeNode::BinaryTreeNode(const int & data, BinaryTreeNode* parent, BinaryTreeNode * left, BinaryTreeNode * right)
{
    Data = data;
    Parent = parent;
    Left = left;
    Right = right;
}
