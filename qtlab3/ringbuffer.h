#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class RingBuffer
{
private:
    int **_data;
    int _sizeBuffer;
    int _head;
    int _tail;

public:
    RingBuffer(const int &size = 8);
    ~RingBuffer();

    int GetFreeSpace() const;
    int GetOccupiedSpace() const;

    void Push(const int & value);
    int Pop();

    char Controller();
    friend ostream& operator<<(ostream& os, const RingBuffer& ringBuffer);
};

#endif // RINGBUFFER_H
