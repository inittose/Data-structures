#ifndef QUEUERING_H
#define QUEUERING_H

#include "ringbuffer.h"

/*!
 * \brief Очередь из кольцевого буфера
 */
class QueueRing
{
private:
    /*!
     * \brief Указатель на кольцевой буфер
     */
    RingBuffer* _ringBuffer;

    /*!
     * \brief Размер буфера
     */
    int _sizeBuffer;

    void ResizeBuffer(bool increase);

public:
    QueueRing();
    ~QueueRing();
    void Enqueue(const int & value);
    int Dequeue();

    void ShowQueue();
    char Controller();
};

#endif // QUEUERING_H
