#include "RingBuffer.h"

RingBuffer::RingBuffer(const int &capacity)
{
    Capacity = capacity;
    Data = new int*[Capacity];
    Head = -1;
    Tail = 0;
    for (int i = 0; i < Capacity; i++)
    {
        Data[i] = nullptr;
    }
}

RingBuffer::~RingBuffer()
{
    for (int i = 0; i < Capacity; i++)
    {
        if (Data[i] != nullptr)
        {
            delete Data[i];
        }
    }
    delete[] Data;
}

int RingBuffer::GetFreeSpace() const
{
    if (Head == -1)
    {
        return Capacity;
    }
    return Tail > Head ? Capacity - Tail + Head : Head - Tail;
}

int RingBuffer::GetOccupiedSpace() const
{
    return Capacity - GetFreeSpace();
}

void RingBuffer::Push(const int &value)
{
    if (Head == Tail)
    {
        Head++;
        Head %= Capacity;
    }

    Data[Tail] = new int(value);
    Tail++;
    Tail %= Capacity;

    if (Head == -1)
    {
        if (Tail == 0)
        {
            Head = Capacity - 1;
        }
        else
        {
            Head = Tail - 1;
        }
    }
}

int RingBuffer::Pop()
{
    int result;
    result = *Data[Head];
    delete Data[Head];
    Data[Head] = nullptr;
    Head++;

    Head %= Capacity;
    if (Head == Tail)
    {
        Head = -1;
    }
    return result;
}
