#include "Stack.h"

Stack::Stack(const int & capacity)
{
    Capacity = capacity;
    Data = new int[Capacity];
    Length = 0;
}

Stack::~Stack()
{
    delete[] Data;
}

void Stack::ResizeStack(const float &growthFactor)
{
    Capacity *= growthFactor;
    int* oldData = Data;
    Data = new int[Capacity];

    for (int i = 0; i < Length; i++)
    {
        Data[i] = oldData[i];
    }
    delete[] oldData;
}

void Stack::Push(const int & value)
{
    if (Length == Capacity)
    {
        ResizeStack(2);
    }
    Data[Length] = value;
    Length++;
}

int Stack::Pop()
{
    Length--;
    int result = Data[Length];

    if (Length <= Capacity / 2 && Length >= 4)
    {
        ResizeStack(0.5f);
    }

    return result;
}

bool Stack::IsEmpty() const
{
    return Length == 0;
}
