#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "stackitem.h"
using std::cout;
using std::cin;
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

    char Controller();
    friend ostream& operator<<(ostream& os, const Stack& stack);
};

template <typename T>
void ValidInput(T &variable);

#endif // STACK_H
