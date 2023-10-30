#include "StackItem.h"

StackItem::StackItem()
{
    Data = 0;
    Prev = nullptr;
}

StackItem::StackItem(const int & data)
{
    Data = data;
    Prev = nullptr;
}