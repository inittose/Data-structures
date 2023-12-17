#include "avltreenode.h"

AVLTreeNode::AVLTreeNode(const int &data, const int height, AVLTreeNode* left, AVLTreeNode* right)
{
    Data = data;
    Height = height;
    Left = left;
    Right = right;
}
