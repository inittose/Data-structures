#include "rbtree.h"

RBTree::RBTree()
{
    _root = nullptr;
}

RBTree::~RBTree()
{
    DeleteNode(_root);
}

void RBTree::DeleteNode(RBTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    DeleteNode(node->Left);
    DeleteNode(node->Right);
    delete node;
}

RBTreeNode* RBTree::TurnLeft(RBTreeNode* node)
{
    RBTreeNode* rightNode = node->Right;
    node->Right = rightNode->Left;
    rightNode->Left = node;
    rightNode->Color = Black;
    node->Color = Red;
    return rightNode;
}

RBTreeNode* RBTree::TurnRight(RBTreeNode* node)
{
    RBTreeNode* leftNode = node->Left;
    node->Left = leftNode->Right;
    leftNode->Right = node;
    leftNode->Color = Black;
    node->Color = Red;
    return leftNode;
}

RBTreeNode* RBTree::Recoloring(RBTreeNode* node)
{
    if (node != _root)
    {
        node->Color = Red;
    }
    node->Left->Color = Black;
    node->Right->Color = Black;
    return node;
}

RBTreeNode* RBTree::Rebalance(RBTreeNode* node, bool &isDisbalanced)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->Left && node->Right)
    {
        if (node->Left->Color == Red && node->Right->Color == Red)
        {
            isDisbalanced = true;
            return Rebalance(Recoloring(node), isDisbalanced);
        }
    }
    if (node->Right && node->Right->Color == Red)
    {
        isDisbalanced = true;
        return Rebalance(TurnLeft(node), isDisbalanced);
    }
    if (node->Left && node->Left->Left)
    {
        if (node->Left->Color == Red && node->Left->Left->Color == Red)
        {
            isDisbalanced = true;
            return Rebalance(TurnRight(node), isDisbalanced);
        }
    }
    node->Left = Rebalance(node->Left, isDisbalanced);
    node->Right = Rebalance(node->Right, isDisbalanced);
    return node;
}

RBTreeNode* RBTree::AddNode(RBTreeNode* node, const int &data)
{
    if (_root == nullptr)
    {
        return new RBTreeNode(data, Black);
    }
    if (node == nullptr)
    {
        return new RBTreeNode(data, Red);
    }
    if (data > node->Data)
    {
        node->Right = AddNode(node->Right, data);
    }
    else
    {
        node->Left = AddNode(node->Left, data);
    }
    return node;
}

void RBTree::AddNode(const int &data)
{
    _root = AddNode(_root, data);
    bool isDisbalanced = true;
    while(isDisbalanced)
    {
        isDisbalanced = false;
        _root = Rebalance(_root, isDisbalanced);
    }
}

int RBTree::GetDepth(RBTreeNode* node, int currentDepth)
{
    if (node == nullptr)
    {
        return currentDepth;
    }
    currentDepth++;
    int leftDepth = GetDepth(node->Left, currentDepth);
    int rightDepth = GetDepth(node->Right, currentDepth);
    if (leftDepth > rightDepth)
    {
        return leftDepth;
    }
    else
    {
        return rightDepth;
    }
}

Queue<RBTreeNode> RBTree::GetLayers()
{
    Queue<RBTreeNode> queue;
    Queue<RBTreeNode> queueBypass;
    int treeDepth = GetDepth(_root);
    int depthObserver = 0;
    queue.Push(_root, depthObserver);
    queueBypass.Push(_root, depthObserver);
    depthObserver = queueBypass.GetDepth();
    while(depthObserver < treeDepth)
    {
        RBTreeNode* node = queueBypass.Pop();
        if (node)
        {
            if (node->Left)
            {
                queue.Push(node->Left, depthObserver + 1, node->Left->Color);
            }
            else
            {
                queue.Push(node->Left, depthObserver + 1);
            }

            if (node->Right)
            {
                queue.Push(node->Right, depthObserver + 1, node->Right->Color);
            }
            else
            {
                queue.Push(node->Right, depthObserver + 1);
            }
            queueBypass.Push(node->Left, depthObserver + 1);
            queueBypass.Push(node->Right, depthObserver + 1);
        }
        else
        {
            queue.Push(nullptr, depthObserver + 1);
            queue.Push(nullptr, depthObserver + 1);
            queueBypass.Push(nullptr, depthObserver + 1);
            queueBypass.Push(nullptr, depthObserver + 1);
        }
        depthObserver = queueBypass.GetDepth();
    }
    return queue;
}
