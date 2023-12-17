#include "rbtreenode.h"

RBTreeNode::RBTreeNode(const int &data, RBColor color, RBTreeNode* left, RBTreeNode* right)
{
    Data = data;
    Color = color;
    Left = left;
    Right = right;
}
