#pragma once

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

    /*!
     * \brief Конструктор узла АВЛ-дерева
     * \param data Данные узла
     * \param height Высота узла
     */
    AVLTreeNode(const int &data, const char height = 1);
};
