#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"

class Queue
{
private:
    Stack _stackIn;
    Stack _stackOut;

public:
    void Enqueue(const int & value);
    int Dequeue();

    void ShowStacks();
    char Controller();
};


#endif // QUEUE_H
