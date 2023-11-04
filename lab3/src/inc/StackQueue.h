#pragma once
#include "Stack.h"

class StackQueue
{
private:
    Stack S1;
    Stack S2;

public:
    void Enqueue(const int & value);
    int Dequeue();

    char Controller();
    friend ostream &operator<<(ostream & os, StackQueue stack);
};
