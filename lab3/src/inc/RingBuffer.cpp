#include "RingBuffer.h"

RingBuffer::RingBuffer()
{
    _data = new int[_sizeBuffer];
    _head = -1;
    _tail = 0;
}

RingBuffer::~RingBuffer()
{
    delete[] _data;
}

int RingBuffer::GetFreeSpace()
{
    if (_head == -1)
    {
        return _sizeBuffer;
    }
    return _tail > _head ? _sizeBuffer - _tail + _head : _head - _tail;
}

int RingBuffer::GetOccupiedSpace()
{
    return _sizeBuffer - GetFreeSpace();
}

void RingBuffer::Push(const int & value)
{
    if (_head == _tail)
    {
        _head++;
        _head %= _sizeBuffer;
    }

    _data[_tail++] = value;
    _tail %= _sizeBuffer;

    if (_head == -1)
    {
        _head = _tail - 1;
    }
}

int RingBuffer::Pop()
{
    int result;
    if (_head == -1)
    {
        return 0;
    }
    result = _data[_head];
    _data[_head++] = 0;

    if (_head == _tail)
    {
        _head = -1;
    }
    return result;
}

ostream& operator<<(ostream& os, const RingBuffer& ringBuffer)
{
    int head = ringBuffer._head;
    int tail = ringBuffer._tail;
    int size = ringBuffer._sizeBuffer;
    os << "Ring Buffer: [ ";
    for (int i = 0; i < ringBuffer._sizeBuffer; i++)
    {
        bool range = i >= head && i < tail;
        bool reverseRange = i >= head && i < size || i >= 0 && i < tail;
        if (tail > head && range || !(tail > head) && reverseRange)
        {
            os << ringBuffer._data[i] << " ";
        }
        else
        {
            os << "* ";
        }
        
    }
    os << "]" << endl;

    return os;
}