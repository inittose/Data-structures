#ifndef RBTREE_H
#define RBTREE_H

#include "rbtreenode.h"
#include "queue.h"

class RBTree
{
private:
    RBTreeNode* _nil;
    RBTreeNode* _root;

    void DeleteNode(RBTreeNode* node);
    RBTreeNode* TurnLeft(RBTreeNode* node);
    RBTreeNode* TurnRight(RBTreeNode* node);
    int GetDepth(RBTreeNode* node, int currentDepth = 0);
    void FixAddNode(RBTreeNode* node);
    void FixRemoveNode(RBTreeNode* node);
    RBTreeNode* GetMin(RBTreeNode* node);
    void Swap(RBTreeNode* old, RBTreeNode* swop);

public:
    RBTree();
    ~RBTree();

    Queue<RBTreeNode> GetLayers();
    void AddNode(const int &data);
    void RemoveNode(const int &data);
    RBTreeNode* SearchNode(const int &data);

};

#endif // RBTREE_H
