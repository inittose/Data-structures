#include "queuestack.h"

QueueStack::QueueStack()
{
    _stackIn = new Stack;
    _stackOut = new Stack;
}

QueueStack::~QueueStack()
{
    delete _stackIn;
    delete _stackOut;
}

void QueueStack::Enqueue(const int & value)
{
    _stackIn->Push(value);
}

int QueueStack::Dequeue()
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

const Stack* QueueStack::GetStackIn()
{
    return _stackIn;
}

const Stack* QueueStack::GetStackOut()
{
    return _stackOut;
}