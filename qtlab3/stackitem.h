#ifndef STACKITEM_H
#define STACKITEM_H

/*!
 * \brief Элемент стека
 */
struct StackItem
{
    /*!
     * \brief Значение
     */
    int Data;

    /*!
     * \brief Предыдущий элемент стека
     */
    struct StackItem* Prev;

    StackItem();
    StackItem(const int & data);
};

#endif // STACKITEM_H
