#ifndef STACKITEM_H
#define STACKITEM_H


struct StackItem
{
    int Data;
    struct StackItem* Prev;

    StackItem();
    StackItem(const int & data);
};

#endif // STACKITEM_H
