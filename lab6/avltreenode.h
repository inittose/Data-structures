#ifndef AVLTREENODE_H
#define AVLTREENODE_H


struct AVLTreeNode
{
    int Data;
    int Height;
    AVLTreeNode* Left;
    AVLTreeNode* Right;

    AVLTreeNode(const int &data, const int height = 1, AVLTreeNode* left = nullptr, AVLTreeNode* right = nullptr);
};

#endif // AVLTREENODE_H
