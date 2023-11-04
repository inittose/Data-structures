#pragma once

struct StackItem
{
    int Data;
    struct StackItem* Prev;

    StackItem();
    StackItem(const int & data);
};
