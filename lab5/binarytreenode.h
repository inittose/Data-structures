//TODO: перейти на pragma ones
//UPD: Теперь все headers используют pragma once
#pragma once

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

    /*!
    * \brief Конструктор узла двоичного дерева поиска
    * \param data Значение
    * \param parent Предок узла
    * \param left Левый узел
    * \param right Правый узел
    */
    //TODO: RSDN
    //UPD: Укоротил строчку, все комментарии теперь в header
    BinaryTreeNode(const int &data, BinaryTreeNode* parent = nullptr);
};

