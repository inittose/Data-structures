#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "iotool.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

struct Stack
{
    int* _data;
    int _sizeBuffer;
    int _lenght;

    void ResizeStack(bool increase);

    Stack(const int & size = 4);
    ~Stack();

    void Push(const int & value);
    int Pop();
    bool IsEmpty();

    char Controller();
    friend ostream& operator<<(ostream& os, const Stack& stack);
};

#endif // STACK_H
