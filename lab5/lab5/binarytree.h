#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

/*!
 * \brief Двоичное дерево поиска
 */
class BinaryTree
{
private:
    /*!
     * \brief Корень дерева
     */
    BinaryTreeNode* _root;

    /*!
     * \brief Глубина дерева
     */
    int _depth;

    int Power(const int &number, const int &power);
    int DigitPlace(int number);
    int FindDepth(BinaryTreeNode* node, int depth);
    void UpdateDepth();
    void Add(BinaryTreeNode* node, const int & data);
    bool Remove(BinaryTreeNode* node, const int & data);
    BinaryTreeNode* Search(BinaryTreeNode* node, const int & data);
    BinaryTreeNode* SearchMin(BinaryTreeNode* node);
    BinaryTreeNode* SearchMax(BinaryTreeNode* node);

public:
    BinaryTree();
    ~BinaryTree();

    void Add(const int & data);
    bool Remove(const int & data);
    BinaryTreeNode* Search(const int & data);
    BinaryTreeNode* SearchMin();
    BinaryTreeNode* SearchMax();
    void Show();
    void ShowDetails(const int & data);
};

#endif // BINARYTREE_H
