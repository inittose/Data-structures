#include "avltreenode.h"

AVLTreeNode::AVLTreeNode(const int &data, const char height)
    : Left{ nullptr }, Right{ nullptr }
{
    Data = data;
    Height = height;
}
