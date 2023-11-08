#ifndef QUEUE_H
#define QUEUE_H
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
    Stack _stackIn;

    /*!
     * \brief Стек для элементов выхода из очереди
     */
    Stack _stackOut;

public:
    void Enqueue(const int & value);
    int Dequeue();

    void ShowStacks();
    char Controller();
};


#endif // QUEUE_H
