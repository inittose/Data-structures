#ifndef AVLTREE_H
#define AVLTREE_H

#include "avltreenode.h"
#include "queue.h"

class AVLTree
{
public:
    int Rotations;

private:
    AVLTreeNode* _root;

    void DeleteNode(AVLTreeNode* node);
    void RebalanceHeight(AVLTreeNode* node);
    int GetDepth(AVLTreeNode* node, int currentDepth = 0);
    int GetHeight(AVLTreeNode* node);
    int GetDeltaHeight(AVLTreeNode* node);
    AVLTreeNode* TurnLeft(AVLTreeNode* node);
    AVLTreeNode* TurnRight(AVLTreeNode* node);
    AVLTreeNode* Rebalance(AVLTreeNode* node);
    AVLTreeNode* AddNode(AVLTreeNode* node, const int &data);
    AVLTreeNode* GetMin(AVLTreeNode* node);
    AVLTreeNode* GetMax(AVLTreeNode* node);
    AVLTreeNode* RemoveMinNode(AVLTreeNode* node);
    AVLTreeNode* RemoveNode(AVLTreeNode* node, const int &data);
    AVLTreeNode* SearchNode(AVLTreeNode* node, const int &data);

public:
    AVLTree();
    ~AVLTree();
    void AddNode(const int &data);
    void RemoveNode(const int &data);
    AVLTreeNode* SearchNode(const int &data);
    Queue<AVLTreeNode> GetLayers();
    int GetRoot();
};

#endif // AVLTREE_H
