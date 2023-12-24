#include "queue.h"

Queue::Queue()
{
    _stackIn = new Stack;
    _stackOut = new Stack;
}

Queue::~Queue()
{
    delete _stackIn;
    delete _stackOut;
}

void Queue::Enqueue(const int & value)
{
    _stackIn->Push(value);
}

int Queue::Dequeue()
{
    if (_stackOut->IsEmpty())
    {
        if (!_stackIn->IsEmpty())
        {
            while (!_stackIn->IsEmpty())
            {
                _stackOut->Push(_stackIn->Pop());
            }
        }
        else
        {
            return 0;
        }
    }
    int result = _stackOut->Pop();
    return result;
}

const Stack* Queue::GetStackIn()
{
    return _stackIn;
}

const Stack* Queue::GetStackOut()
{
    return _stackOut;
}