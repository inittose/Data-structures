#pragma once
#include "StackItem.h"
#include <ostream>
using std::endl;
using std::ostream;

class Stack
{
private:
    StackItem* _top;
    int _size;

public:
    Stack();
    ~Stack();

    void Push(const int & data);
    int Pop();
    bool IsEmpty();

    friend ostream& operator<<(ostream& os, const Stack& stack);
};
