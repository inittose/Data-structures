#ifndef RBTREENODE_H
#define RBTREENODE_H

/*!
 * \brief Цветовой набор для КЧД
 */
enum RBColor
{
    Black,
    Red
};

/*!
 * \brief Узел красно-черного дерева
 */
struct RBTreeNode
{
    /*!
     * \brief Данные КЧД
     */
    int Data;

    /*!
     * \brief Указатель на левого ребенка
     */
    RBTreeNode* Left;

    /*!
     * \brief Указатель на правого ребенка
     */
    RBTreeNode* Right;

    /*!
     * \brief Указатель на родителя
     */
    RBTreeNode* Parent;

    /*!
     * \brief Цвет узла
     */
    RBColor Color;

    RBTreeNode(const int &data, RBColor color, RBTreeNode* left = nullptr, RBTreeNode* right = nullptr, RBTreeNode* parent = nullptr);
};

#endif // RBTREENODE_H
