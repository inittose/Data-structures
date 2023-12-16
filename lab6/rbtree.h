#ifndef RBTREE_H
#define RBTREE_H

#include "rbtreenode.h"
#include "queue.h"

class RBTree
{
private:
    RBTreeNode* _root;

    void DeleteNode(RBTreeNode* node);
    RBTreeNode* TurnLeft(RBTreeNode* node);
    RBTreeNode* TurnRight(RBTreeNode* node);
    RBTreeNode* Recoloring(RBTreeNode* node);
    RBTreeNode* Rebalance(RBTreeNode* node);
    RBTreeNode* AddNode(RBTreeNode* node, const int &data);
    int GetDepth(RBTreeNode* node, int currentDepth = 0);

public:
    RBTree();
    ~RBTree();

    void AddNode(const int &data);
    Queue<RBTreeNode> GetLayers();
};

#endif // RBTREE_H
