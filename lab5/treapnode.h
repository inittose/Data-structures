#pragma once

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

    //TODO: RSDN
    //UPD: Все комментарии теперь в header
    /*!
    * \brief Конструктор узла декартова дерева
    * \param key Ключ узла
    */
    TreapNode(const int &key);
};
