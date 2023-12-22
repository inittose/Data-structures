//TODO: перейти на pragma ones
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


/*!
 * \brief Узел двоичного дерева поиска
 */
struct BinaryTreeNode
{
    /*!
     * \brief Значение
     */
    int Data;

    /*!
     * \brief Узел предка
     */
    BinaryTreeNode* Parent;

    /*!
     * \brief Левый узел
     */
    BinaryTreeNode* Left;

    /*!
     * \brief Правый узел
     */
    BinaryTreeNode* Right;

    //TODO: RSDN
    BinaryTreeNode(const int & data = 0, BinaryTreeNode* parent = nullptr, BinaryTreeNode * left = nullptr, BinaryTreeNode * right = nullptr);
};

#endif // BINARYTREENODE_H
