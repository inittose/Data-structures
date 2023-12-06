#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

class BinaryTree
{
private:
    BinaryTreeNode* _root;
    int _depth;

    int Power(const int &number, const int &power);
    int DigitPlace(int number);
    int FindDepth(BinaryTreeNode* node, int depth);
    void UpdateDepth();

public:
    BinaryTree();
    ~BinaryTree();
    void Add(BinaryTreeNode* node, const int & data);
    void Add(const int & data);
    bool Remove(BinaryTreeNode* node, const int & data);
    bool Remove(const int & data);
    BinaryTreeNode* Search(BinaryTreeNode* node, const int & data);
    BinaryTreeNode* Search(const int & data);
    BinaryTreeNode* SearchMin(BinaryTreeNode* node);
    BinaryTreeNode* SearchMin();
    BinaryTreeNode* SearchMax(BinaryTreeNode* node);
    BinaryTreeNode* SearchMax();
    void Show();
    void ShowDetails(const int & data);
};

#endif // BINARYTREE_H
