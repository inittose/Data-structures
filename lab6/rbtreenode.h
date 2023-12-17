#ifndef RBTREENODE_H
#define RBTREENODE_H

enum RBColor
{
    Black,
    Red
};

struct RBTreeNode
{
    int Data;
    RBTreeNode* Left;
    RBTreeNode* Right;
    RBColor Color;

    RBTreeNode(const int &data, RBColor color, RBTreeNode* left = nullptr, RBTreeNode* right = nullptr);
};

#endif // RBTREENODE_H
