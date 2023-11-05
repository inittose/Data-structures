#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.h"

class Queue
{
private:
    Stack S1;
    Stack S2;

public:
    void Enqueue(const int & value);
    int Dequeue();

    char Controller();
    friend ostream &operator<<(ostream & os, Queue stack);
};


#endif // QUEUE_H
