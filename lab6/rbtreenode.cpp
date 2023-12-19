#include "rbtreenode.h"

RBTreeNode::RBTreeNode(const int &data, RBColor color, RBTreeNode* left, RBTreeNode* right, RBTreeNode* parent)
{
    Data = data;
    Color = color;
    Parent = parent;
    Left = left;
    Right = right;
}
