#pragma once
#include <ostream>
using std::endl;
using std::ostream;

class RingBuffer
{
private:
    int *_data;
    const int _sizeBuffer = 8;
    int _head;
    int _tail;

public:
    RingBuffer();
    ~RingBuffer();

    int GetFreeSpace();
    int GetOccupiedSpace();

    void Push(const int & value);
    int Pop();

    friend ostream& operator<<(ostream& os, const RingBuffer& ringBuffer);
};
