#include <iostream>
#include "inc/Stack.h"
#include "inc/RingBuffer.h"
#include "inc/Menu.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    const char *mainMenu = "\nChoose one of structures: \n1 - Stack \n2 - Ring buffer \n3 - Queue (Ring) \n4 - Queue \nq - Quit \nYour choice: ";
    Stack stack;
    RingBuffer ringBuffer;

    ClearConsole();

    stack.Push(5);
    stack.Push(3);

    ringBuffer.Push(5);
    ringBuffer.Push(4);
    ringBuffer.Push(3);
    ringBuffer.Push(2);
    ringBuffer.Push(1);
    ringBuffer.Push(0);
    ringBuffer.Push(-1);
    ringBuffer.Push(-2);
    ringBuffer.Push(-3);
    ringBuffer.Pop();
    ringBuffer.Pop();

    cout << ringBuffer;

    return 0;
}