#ifndef QUEUERING_H
#define QUEUERING_H

#include "ringbuffer.h"

class QueueRing
{
private:
    RingBuffer* _ringBuffer;
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
