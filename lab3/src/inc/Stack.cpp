#include "Stack.h"


Stack::Stack()
{
    _top = nullptr;
    _size = 0;
}

Stack::~Stack()
{
    StackItem *run = _top;
    while(run)
    {
        StackItem *temp = run;
        run = run->Prev;
        delete temp;
    }
}

void Stack::Push(const int & data)
{
    StackItem *newItem = new StackItem(data);
    newItem->Prev = _top;
    _top = newItem;
    _size++;
}

int Stack::Pop()
{
    if (!_top)
    {
        return -1;
    }
    StackItem *temp = _top;
    int result = temp->Data;
    _top = _top->Prev;
    delete temp;
    _size--;
    return result;
}

bool Stack::IsEmpty()
{
    return _top;
}

ostream& operator<<(ostream& os, const Stack& stack)
{
    os << "Stack: [ ";

    StackItem *temp = stack._top;
    while(temp)
    {
        os << temp->Data << " ";
        temp = temp->Prev;
    }
    os << "]" << endl;
    os << "Size: " << stack._size << endl;

    return os;
}