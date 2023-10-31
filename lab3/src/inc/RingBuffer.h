#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class RingBuffer
{
private:
    char *_data;
    const int _sizeBuffer = 8;
    int _head;
    int _tail;

public:
    RingBuffer();
    ~RingBuffer();

    int GetFreeSpace();
    int GetOccupiedSpace();

    void Push(const char & value);
    char Pop();

    char Controller();
    friend ostream& operator<<(ostream& os, const RingBuffer& ringBuffer);
};
