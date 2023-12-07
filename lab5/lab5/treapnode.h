#ifndef TREAPNODE_H
#define TREAPNODE_H

#include <cstdlib>
#include <ctime>

struct TreapNode
{
    static const int MAX_PRIORITY = 100;
    int Key;
    int Priority;
    TreapNode* Left;
    TreapNode* Right;

    TreapNode(const int & key);
};

#endif // TREAPNODE_H
