#include "binarytreenode.h"

BinaryTreeNode::BinaryTreeNode(const int & data, const int & depth, BinaryTreeNode * parent, BinaryTreeNode * left, BinaryTreeNode * right)
{
    Data = data;
    Depth = depth;
    Left = left;
    Right = right;
    Parent = parent;
}
