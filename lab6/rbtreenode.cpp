#include "rbtreenode.h"

RBTreeNode::RBTreeNode(const int &data, RBColor color, RBTreeNode* parent, RBTreeNode* left, RBTreeNode* right)
{
    Data = data;
    Color = color;
    Parent = parent;
    Left = left;
    Right = right;
}
