#pragma once
#include "stack.h"

/*!
 * \brief Класс очереди через 2 стека
 */
class Queue
{
private:
    /*!
     * \brief Стек для элементов вхождения в очередь
     */
    Stack* _stackIn;

    /*!
     * \brief Стек для элементов выхода из очереди
     */
    Stack* _stackOut;

public:
    /*!
     * \brief Конструктор очереди
     */
    Queue();

    /*!
     * \brief Деструктор очереди
     */
    ~Queue();

    /*!
     * \brief Поставить элемент в очередь
     * \param value Значение элемента
     */
    void Enqueue(const int & value);

    /*!
     * \brief Убрать элемент из очереди
     * \return Возвращает значение убранного элемента
     */
    int Dequeue();

    /*!
     * \brief Получить стек вхождения
     * \return Стек вхождения
     */
    const Stack* GetStackIn();

    /*!
    * \brief Получить стек вывода
    * \return Стек вывода
    */
    const Stack* GetStackOut();
};
