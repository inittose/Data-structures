#ifndef TREAPNODE_H
#define TREAPNODE_H

#include <cstdlib>
#include <ctime>

/*!
 * \brief Узел декартова дерева
 */
struct TreapNode
{
    /*!
     * \brief Максимальное значение приоритета узла
     */
    static const int MAX_PRIORITY = 100;

    /*!
     * \brief Ключ
     */
    int Key;

    /*!
     * \brief Приоритет
     */
    int Priority;

    /*!
     * \brief Левый узел
     */
    TreapNode* Left;

    /*!
     * \brief Правый узел
     */
    TreapNode* Right;

    TreapNode(const int & key);
};

#endif // TREAPNODE_H
