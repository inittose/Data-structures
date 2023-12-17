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
    rightNode->Color = node->Color;
    node->Color = Red;
    return rightNode;
}

RBTreeNode* RBTree::TurnRight(RBTreeNode* node)
{
    RBTreeNode* leftNode = node->Left;
    node->Left = leftNode->Right;
    leftNode->Right = node;
    leftNode->Color = node->Color;
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

RBTreeNode* RBTree::Rebalance(RBTreeNode* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->Left && node->Right)
    {
        if (node->Left->Color == Red && node->Right->Color == Red)
        {
            return Rebalance(Recoloring(node));
        }
    }
    if (node->Right && node->Right->Color == Red)
    {
        return Rebalance(TurnLeft(node));
    }
    if (node->Left && node->Left->Left)
    {
        if (node->Left->Color == Red && node->Left->Left->Color == Red)
        {
            return Rebalance(TurnRight(node));
        }
    }
    //node->Left = Rebalance(node->Left);
    //node->Right = Rebalance(node->Right);
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
    if (data == node->Data)
    {
        return node;
    }
    if (data > node->Data)
    {
        node->Right = AddNode(node->Right, data);
    }
    else
    {
        node->Left = AddNode(node->Left, data);
    }
    return Rebalance(node);
}

void RBTree::AddNode(const int &data)
{
    _root = AddNode(_root, data);
}

RBTreeNode* RBTree::GetMin(RBTreeNode* node)
{
    if (node->Left == nullptr)
    {
        return node;
    }
    else
    {
        return GetMin(node->Left);
    }
}

RBTreeNode* RBTree::GetMax(RBTreeNode* node)
{
    if (node->Right == nullptr)
    {
        return node;
    }
    else
    {
        return GetMax(node->Right);
    }
}

RBTreeNode* RBTree::RemoveMinNode(RBTreeNode* node)
{
    if (node->Left == nullptr)
    {
        return node->Right;
    }
    node->Left = RemoveMinNode(node->Left);
    return Rebalance(node);
}

RBTreeNode* RBTree::RemoveNode(RBTreeNode* node, const int &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->Data == data)
    {
        RBTreeNode* left = node->Left;
        RBTreeNode* right = node->Right;
        RBColor color = node->Color;
        delete node;
        if (left != nullptr && right != nullptr)
        {
            RBTreeNode* swapNode = GetMin(right);
            swapNode->Right = RemoveMinNode(right);
            swapNode->Left = left;
            swapNode->Color = color;
            return Rebalance(swapNode);
        }
        if (left != nullptr)
        {
            left->Color = color;
            return left;
        }
        if (right != nullptr)
        {
            right->Color = color;
            return right;
        }
        return nullptr;
    }
    if (data > node->Data)
    {
        node->Right = RemoveNode(node->Right, data);
    }
    else
    {
        node->Left = RemoveNode(node->Left, data);
    }
    return Rebalance(node);
}

void RBTree::RemoveNode(const int &data)
{
    _root = RemoveNode(_root, data);
}

RBTreeNode* RBTree::SearchNode(RBTreeNode* node, const int &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->Data == data)
    {
        return node;
    }
    if (data > node->Data)
    {
        return SearchNode(node->Right, data);
    }
    else
    {
        return SearchNode(node->Left, data);
    }
}

RBTreeNode* RBTree::SearchNode(const int &data)
{
    return SearchNode(_root, data);
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
