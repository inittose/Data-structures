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

public:
    BinaryTree();
    ~BinaryTree();
    void Add(BinaryTreeNode* node, const int & data, int depth);
    void Add(const int & data);
    void Remove(const int & data);
    bool Search(const int & data);
    BinaryTreeNode* SearchMin(BinaryTreeNode* node);
    BinaryTreeNode* SearchMax(BinaryTreeNode* node);
    void Show();
};

#endif // BINARYTREE_H
