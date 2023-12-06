#include "treapnode.h"

TreapNode::TreapNode(const int & key)
{
    Key = key;
    Priority = std::rand() % MAX_PRIORITY;
}
