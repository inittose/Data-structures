#include "rbtreenode.h"


/*!
 * \brief Конструктор узла КЧД
 * \param data Данные узла
 * \param color Цвет узла
 * \param left Левый дочерний узел
 * \param right Правый дочерний узел
 * \param parent Родительский узел
 */
RBTreeNode::RBTreeNode(const int &data, RBColor color, RBTreeNode* left, RBTreeNode* right, RBTreeNode* parent)
{
    Data = data;
    Color = color;
    Parent = parent;
    Left = left;
    Right = right;
}
