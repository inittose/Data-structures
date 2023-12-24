#include "queuering.h"

QueueRing::QueueRing()
{
    _sizeBuffer = 4;
    _ringBuffer = new RingBuffer(_sizeBuffer);
}

QueueRing::~QueueRing()
{
    delete _ringBuffer;
}

void QueueRing::ResizeBuffer(const float& growthFactor)
{
    _sizeBuffer *= growthFactor;
    RingBuffer* newBuffer = new RingBuffer(_sizeBuffer);

    int occupiedSpace = _ringBuffer->GetOccupiedSpace();
    for (int i = 0; i < occupiedSpace; i++)
    {
        newBuffer->Push(_ringBuffer->Pop());
    }
    delete _ringBuffer;
    _ringBuffer = newBuffer;
}

void QueueRing::Enqueue(const int & value)
{
    if (!_ringBuffer->GetFreeSpace())
    {
        ResizeBuffer(2.0f);
    }
    _ringBuffer->Push(value);
}

int QueueRing::Dequeue()
{
    int result = _ringBuffer->Pop();
    bool ResizeCondition = _ringBuffer->GetFreeSpace() <= _ringBuffer->Capacity / 2;
    ResizeCondition &= _ringBuffer->GetFreeSpace() >= 4;
    if (ResizeCondition)
    {
        ResizeBuffer(0.5f);
    }
    return result;
}

const RingBuffer* QueueRing::GetRingBuffer()
{
    return _ringBuffer;
}