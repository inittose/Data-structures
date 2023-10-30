#include <iostream>
#include "inc/Stack.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Stack stack;

    stack.Push(5);
    stack.Push(3);

    cout << stack;

    return 0;
}