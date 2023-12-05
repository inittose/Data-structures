#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


struct BinaryTreeNode
{
    int Data;
    int Depth;
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    BinaryTreeNode* Parent;

    BinaryTreeNode(const int & data = 0, const int & depth = 0, BinaryTreeNode * parent = nullptr, BinaryTreeNode * left = nullptr, BinaryTreeNode * right = nullptr);
};

#endif // BINARYTREENODE_H
