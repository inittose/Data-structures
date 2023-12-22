#include "binarytree.h"

BinaryTree::BinaryTree()
{
    _root = nullptr;
}

BinaryTree::~BinaryTree()
{
    if (!_root)
    {
        return;
    }
    Queue<BinaryTreeNode> queue;
    queue.Push(_root);
    while(!queue.IsEmpty())
    {
        BinaryTreeNode* temp = queue.Pop();
        if (temp->Left)
        {
            queue.Push(temp->Left);
        }
        if (temp->Right)
        {
            queue.Push(temp->Right);
        }
        delete temp;
    }
}

int BinaryTree::FindDepth(BinaryTreeNode* node, int depth)
{
    if (!node)
    {
        return depth;
    }
    depth++;
    int leftDepth = FindDepth(node->Left, depth);
    int rightDepth = FindDepth(node->Right, depth);
    return leftDepth > rightDepth ? leftDepth : rightDepth;
}

void BinaryTree::Add(BinaryTreeNode* node, const int &data)
{
    if (!node)
    {
        _root = new BinaryTreeNode(data);
        return;
    }
    if (data == node->Data)
    {
        return;
    }
    if (data < node->Data)
    {
        if (node->Left)
        {
            Add(node->Left, data);
        }
        else
        {
            node->Left = new BinaryTreeNode(data, node);
        }
    }
    else
    {
        if (node->Right)
        {
            Add(node->Right, data);
        }
        else
        {
            node->Right = new BinaryTreeNode(data, node);
        }
    }
}

void BinaryTree::Add(const int &data)
{
    Add(_root, data);
}

bool BinaryTree::Remove(const int &data)
{
    BinaryTreeNode* removeElement = Search(data);
    BinaryTreeNode* swapElement = nullptr;
    if (!removeElement)
    {
        return false;
    }
    if (removeElement->Left && removeElement->Right)
    {
        swapElement = SearchMin(removeElement->Right);
        removeElement->Left->Parent = swapElement;
        if (swapElement->Parent != removeElement)
        {
            swapElement->Parent->Parent = swapElement;
            swapElement->Parent->Left = swapElement->Right;
            if (swapElement->Right)
            {
                swapElement->Right->Parent = swapElement->Parent;
            }
        }
        else
        {
            removeElement->Right = swapElement->Right;
        }
        swapElement->Left = removeElement->Left;
        swapElement->Right = removeElement->Right;
    }
    else if (removeElement->Left)
    {
        swapElement = removeElement->Left;
    }
    else if (removeElement->Right)
    {
        swapElement = removeElement->Right;
    }
    if (removeElement->Parent)
    {
        if (removeElement->Parent->Left == removeElement)
        {
            removeElement->Parent->Left = swapElement;
        }
        else
        {
            removeElement->Parent->Right = swapElement;
        }
    }
    else
    {
        _root = swapElement;
        if (swapElement)
        {
            swapElement->Parent = nullptr;
        }
    }
    delete removeElement;
    return true;
}

BinaryTreeNode* BinaryTree::Search(BinaryTreeNode* node, const int &data)
{
    if (!node)
    {
        return nullptr;
    }
    if (data == node->Data)
    {
        return node;
    }
    if (data < node->Data)
    {
        return Search(node->Left, data);
    }
    else
    {
        return Search(node->Right, data);
    }
}

BinaryTreeNode* BinaryTree::Search(const int &data)
{
    return Search(_root, data);
}

//TODO: убрать из СД операциии IO должны быть отдельно от СД

//TODO: убрать из СД операциии IO должны быть отдельно от СД

//UPD: Перенёс все методы вывода в соответствующий файл

BinaryTreeNode* BinaryTree::SearchMin(BinaryTreeNode* node)
{
    if (!node)
    {
        return nullptr;
    }
    if (node->Left)
    {
        return SearchMin(node->Left);
    }
    else
    {
        return node;
    }
}

BinaryTreeNode* BinaryTree::SearchMin()
{
    return SearchMin(_root);
}

BinaryTreeNode* BinaryTree::SearchMax(BinaryTreeNode* node)
{
    if (!node)
    {
        return nullptr;
    }
    if (node->Right)
    {
        return SearchMax(node->Right);
    }
    else
    {
        return node;
    }
}

BinaryTreeNode* BinaryTree::SearchMax()
{
    return SearchMax(_root);
}

Queue<BinaryTreeNode>* BinaryTree::GetLayers()
{
    Queue<BinaryTreeNode>* queue = new Queue<BinaryTreeNode>();
    Queue<BinaryTreeNode>* queueBypass = new Queue<BinaryTreeNode>();
    int treeDepth = FindDepth(_root, 0);
    int depthObserver = 0;
    queue->Push(_root, depthObserver);
    queueBypass->Push(_root, depthObserver);
    depthObserver = queueBypass->GetDepth();
    while(depthObserver < treeDepth)
    {
        BinaryTreeNode* node = queueBypass->Pop();
        if (node)
        {
            queue->Push(node->Left, depthObserver + 1);
            queue->Push(node->Right, depthObserver + 1);
            queueBypass->Push(node->Left, depthObserver + 1);
            queueBypass->Push(node->Right, depthObserver + 1);
        }
        else
        {
            queue->Push(nullptr, depthObserver + 1);
            queue->Push(nullptr, depthObserver + 1);
            queueBypass->Push(nullptr, depthObserver + 1);
            queueBypass->Push(nullptr, depthObserver + 1);
        }
        depthObserver = queueBypass->GetDepth();
    }
    delete queueBypass;
    return queue;
}
