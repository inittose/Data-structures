#ifndef AVLTREENODE_H
#define AVLTREENODE_H

/*!
 * \brief Узел АВЛ-дерева
 */
struct AVLTreeNode
{
    /*!
     * \brief Данные узла
     */
    int Data;

    /*!
     * \brief Высота узла
     */
    char Height;

    /*!
     * \brief Левый дочерний узел
     */
    AVLTreeNode* Left;

    /*!
     * \brief Правый дочерний узле
     */
    AVLTreeNode* Right;

    AVLTreeNode(const int &data, const char height = 1, AVLTreeNode* left = nullptr, AVLTreeNode* right = nullptr);
};

#endif // AVLTREENODE_H
