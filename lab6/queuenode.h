#pragma once

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
     * \brief Цвет узла
     */
    char Color;

    /*!
     * \brief Конструктор узла очереди
     * \param data Значение узла
     * \param depth Глубина узла
     * \param color Цвет узла
     * \param next Следующий элемент
     */
    QueueNode(type* data = nullptr, const int & depth = 0, char color = 0)
    {
        Data = data;
        Depth = depth;
        Color = color;
        Next = nullptr;
    }
};
