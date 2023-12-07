#include "binarytreenode.h"

/*!
 * \brief Конструктор узла двоичного дерева поиска
 * \param data Значение
 * \param parent Предок узла
 * \param left Левый узел
 * \param right Правый узел
 */
BinaryTreeNode::BinaryTreeNode(const int & data, BinaryTreeNode* parent, BinaryTreeNode * left, BinaryTreeNode * right)
{
    Data = data;
    Parent = parent;
    Left = left;
    Right = right;
}
