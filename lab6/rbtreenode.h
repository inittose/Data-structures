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
    RBTreeNode* Parent;
    RBColor Color;

    RBTreeNode(const int &data, RBColor color, RBTreeNode* parent = nullptr, RBTreeNode* left = nullptr, RBTreeNode* right = nullptr);
};

#endif // RBTREENODE_H
