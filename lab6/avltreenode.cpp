#include "avltreenode.h"

/*!
 * \brief Конструктор узла АВЛ-дерева
 * \param data Данные узла
 * \param height Высота узла
 * \param left Левый дочерний узел
 * \param right Правый дочерний узел
 */
AVLTreeNode::AVLTreeNode(const int &data, const char height, AVLTreeNode* left, AVLTreeNode* right)
{
    Data = data;
    Height = height;
    Left = left;
    Right = right;
}
