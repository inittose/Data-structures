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
    os << "Stack: \t\t" << "Size: " << stack._size << endl;

    StackItem *temp = stack._top;
    while(temp)
    {
        os << "\t| " << temp->Data << " |" << endl;
        temp = temp->Prev;
    }
    os << "\t`````" << endl;

    return os;
}