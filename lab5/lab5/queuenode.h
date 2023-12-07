#ifndef QUEUENODE_H
#define QUEUENODE_H

#include "binarytreenode.h"

/*!
 * \brief Узел очереди
 */
template <typename type>
struct QueueNode
{
    /*!
     * \brief Значение узла
     */
    type* Data;

    /*!
     * \brief Следующий узел
     */
    QueueNode* Next;

    /*!
     * \brief Глубина узла
     */
    int Depth;

    /*!
     * \brief Конструктор узла очереди
     * \param data Значение узла
     * \param depth Глубина узла
     * \param next Следующий элемент
     */
    QueueNode(type* data = nullptr, const int & depth = 0, QueueNode* next = nullptr)
    {
        Data = data;
        Depth = depth;
        Next = next;
    }
};

#endif // QUEUENODE_H
