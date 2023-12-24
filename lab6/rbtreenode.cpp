#include "rbtreenode.h"

RBTreeNode::RBTreeNode(const int &data, RBColor color, RBTreeNode* left, RBTreeNode* right)
    : Parent{ nullptr }
{
    Data = data;
    Color = color;
    Left = left;
    Right = right;
}
