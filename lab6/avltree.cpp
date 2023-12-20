#include "avltree.h"

AVLTree::AVLTree()
{
    Rotations = 0;
    _root = nullptr;
}

AVLTree::~AVLTree()
{
    DeleteNode(_root);
}

void AVLTree::DeleteNode(AVLTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    DeleteNode(node->Left);
    DeleteNode(node->Right);
    delete node;
}

int AVLTree::GetHeight(AVLTreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return node->Height;
    }
}

int AVLTree::GetDeltaHeight(AVLTreeNode* node)
{
    return GetHeight(node->Left) - GetHeight(node->Right);
}

void AVLTree::RebalanceHeight(AVLTreeNode* node)
{
    int leftHeight = GetHeight(node->Left);
    int rightHeight = GetHeight(node->Right);
    if (leftHeight > rightHeight)
    {
        node->Height = leftHeight + 1;
    }
    else
    {
        node->Height = rightHeight + 1;
    }
}

AVLTreeNode* AVLTree::TurnLeft(AVLTreeNode* node)
{
    AVLTreeNode* rightNode = node->Right;
    node->Right = rightNode->Left;
    rightNode->Left = node;
    RebalanceHeight(node);
    RebalanceHeight(rightNode);
    ++Rotations;
    return rightNode;
}

AVLTreeNode* AVLTree::TurnRight(AVLTreeNode* node)
{
    AVLTreeNode* leftNode = node->Left;
    node->Left = leftNode->Right;
    leftNode->Right = node;
    RebalanceHeight(node);
    RebalanceHeight(leftNode);
    ++Rotations;
    return leftNode;
}

AVLTreeNode* AVLTree::Rebalance(AVLTreeNode* node)
{
    RebalanceHeight(node);
    if (GetDeltaHeight(node) == 2)
    {
        if (GetDeltaHeight(node->Left) < 0)
        {
            node->Left = TurnLeft(node->Left);
        }
        return TurnRight(node);
    }
    if (GetDeltaHeight(node) == -2)
    {
        if (GetDeltaHeight(node->Right) > 0)
        {
            node->Right = TurnRight(node->Right);
        }
        return TurnLeft(node);
    }
    return node;
}

AVLTreeNode* AVLTree::AddNode(AVLTreeNode* node, const int &data)
{
    if (node == nullptr)
    {
        return new AVLTreeNode(data);
    }
    /*if (data == node->Data)
    {
        return node;
    }*/
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

void AVLTree::AddNode(const int &data)
{
    Rotations = 0;
    _root = AddNode(_root, data);
}

AVLTreeNode* AVLTree::GetMin(AVLTreeNode* node)
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

AVLTreeNode* AVLTree::GetMax(AVLTreeNode* node)
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

AVLTreeNode* AVLTree::RemoveMinNode(AVLTreeNode* node)
{
    if (node->Left == nullptr)
    {
        return node->Right;
    }
    node->Left = RemoveMinNode(node->Left);
    return Rebalance(node);
}

AVLTreeNode* AVLTree::RemoveNode(AVLTreeNode* node, const int &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->Data == data)
    {
        AVLTreeNode* left = node->Left;
        AVLTreeNode* right = node->Right;
        delete node;
        if (left != nullptr && right != nullptr)
        {
            AVLTreeNode* swapNode = GetMin(right);
            swapNode->Right = RemoveMinNode(right);
            swapNode->Left = left;
            return Rebalance(swapNode);
        }
        if (left != nullptr)
        {
            return left;
        }
        if (right != nullptr)
        {
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

void AVLTree::RemoveNode(const int &data)
{
    Rotations = 0;
    _root = RemoveNode(_root, data);
}

AVLTreeNode* AVLTree::SearchNode(AVLTreeNode* node, const int &data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (data == node->Data)
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

AVLTreeNode* AVLTree::SearchNode(const int &data)
{
    return SearchNode(_root, data);
}

int AVLTree::GetDepth(AVLTreeNode* node, int currentDepth)
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

Queue<AVLTreeNode> AVLTree::GetLayers()
{
    Queue<AVLTreeNode> queue;
    Queue<AVLTreeNode> queueBypass;
    int treeDepth = GetDepth(_root);
    int depthObserver = 0;
    queue.Push(_root, depthObserver);
    queueBypass.Push(_root, depthObserver);
    depthObserver = queueBypass.GetDepth();
    while(depthObserver < treeDepth)
    {
        AVLTreeNode* node = queueBypass.Pop();
        if (node)
        {
            if (node->Left)
            {
                queue.Push(node->Left, depthObserver + 1);
            }
            else
            {
                queue.Push(node->Left, depthObserver + 1);
            }

            if (node->Right)
            {
                queue.Push(node->Right, depthObserver + 1);
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

int AVLTree::GetRoot()
{
    return _root->Data;
}
