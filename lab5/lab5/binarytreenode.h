#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


struct BinaryTreeNode
{
    int Data;
    BinaryTreeNode* Parent;
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;

    BinaryTreeNode(const int & data = 0, BinaryTreeNode* parent = nullptr, BinaryTreeNode * left = nullptr, BinaryTreeNode * right = nullptr);
};

#endif // BINARYTREENODE_H
