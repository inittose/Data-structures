#pragma once

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

    /*!
     * \brief Конструктор элемента стека
     */
    StackItem(const int & data = 0);
};
