#include "treapnode.h"

TreapNode::TreapNode(const int & key)
{
    Key = key;
    std::srand(std::time(nullptr));
    Priority = std::rand() % MAX_PRIORITY;
}
