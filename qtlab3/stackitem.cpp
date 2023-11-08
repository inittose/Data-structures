#include "stackitem.h"

/*!
 * \brief Конструктор стек элемента
 */
StackItem::StackItem()
{
    Data = 0;
    Prev = nullptr;
}

/*!
 * \brief Конструктор стек элемента
 */
StackItem::StackItem(const int & data)
{
    Data = data;
    Prev = nullptr;
}
