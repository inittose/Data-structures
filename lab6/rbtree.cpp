#include "rbtree.h"

RBTree::RBTree()
{
    _nil = new RBTreeNode(0, Black);
    _root = _nil;
}

RBTree::~RBTree()
{
    DeleteNode(_root);
    delete _nil;
}

void RBTree::DeleteNode(RBTreeNode* node)
{
    if (node == _nil)
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
    if (rightNode->Left != _nil)
    {
        rightNode->Left->Parent = node;
    }

    rightNode->Left = node;
    rightNode->Parent = node->Parent;
    if (node->Parent == _nil)
    {
        _root = rightNode;
    }
    else
    {
        if (node == node->Parent->Left)
        {
            node->Parent->Left = rightNode;
        }
        else
        {
            node->Parent->Right = rightNode;
        }
    }
    node->Parent = rightNode;
    return rightNode;
}

RBTreeNode* RBTree::TurnRight(RBTreeNode* node)
{
    RBTreeNode* leftNode = node->Left;
    node->Left = leftNode->Right;
    if (leftNode->Right != _nil)
    {
        leftNode->Right->Parent = node;
    }

    leftNode->Right = node;
    leftNode->Parent = node->Parent;
    if (node->Parent == _nil)
    {
        _root = leftNode;
    }
    else
    {
        if (node == node->Parent->Left)
        {
            node->Parent->Left = leftNode;
        }
        else
        {
            node->Parent->Right = leftNode;
        }
    }
    node->Parent = leftNode;
    return leftNode;
}

void RBTree::AddNode(const int &data)
{
    RBTreeNode* newNode = new RBTreeNode(data, Red, _nil, _nil);
    if (_root == _nil)
    {
        _root = newNode;
        newNode->Parent = _nil;
    }
    else
    {
        RBTreeNode* bypassNode = _root;
        RBTreeNode* parent = _nil;
        while (bypassNode != _nil)
        {
            parent = bypassNode;
            if (newNode->Data > bypassNode->Data)
            {
                bypassNode = bypassNode->Right;
            }
            else
            {
                bypassNode = bypassNode->Left;
            }
        }
        newNode->Parent = parent;

        if (newNode->Data > parent->Data)
        {
            parent->Right = newNode;
        }
        else
        {
            parent->Left = newNode;
        }
    }
    FixAddNode(newNode);
}

void RBTree::FixAddNode(RBTreeNode* node)
{
    if (node == _root)
    {
        node->Color = Black;
        return;
    }

    while (node->Parent->Color == Red)
    {
        RBTreeNode* parent = node->Parent;
        RBTreeNode* grandparent = parent->Parent;
        if (grandparent != _nil)
        {
            if (node->Parent == grandparent->Left)
            {
                RBTreeNode* uncle = grandparent->Right;
                if (uncle != _nil && uncle->Color == Red)
                {
                    parent->Color = Black;
                    uncle->Color = Black;
                    grandparent->Color = Red;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->Right)
                    {
                        node = parent;
                        TurnLeft(node);
                        parent = node->Parent;
                        grandparent = parent->Parent;
                    }
                    parent->Color = Black;
                    grandparent->Color = Red;
                    TurnRight(grandparent);
                }
            }
            else
            {
                RBTreeNode* uncle = grandparent->Left;
                if (uncle != _nil && uncle->Color == Red)
                {
                    parent->Color = Black;
                    uncle->Color = Black;
                    grandparent->Color = Red;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->Left)
                    {
                        node = parent;
                        TurnRight(node);
                        parent = node->Parent;
                        grandparent = parent->Parent;
                    }
                    parent->Color = Black;
                    grandparent->Color = Red;
                    TurnLeft(grandparent);
                }
            }
        }
    }

    _root->Color = Black;
}

void RBTree::Swap(RBTreeNode* old, RBTreeNode* swop)
{
    if (old->Parent == _nil)
    {
        _root = swop;
    }
    else
    {
        if (old == old->Parent->Left)
        {
            old->Parent->Left = swop;
        }
        else
        {
            old->Parent->Right = swop;
        }
    }
    swop->Parent = old->Parent;
}

void RBTree::RemoveNode(const int &data)
{
    RBTreeNode* removeNode = SearchNode(data);
    if (removeNode == nullptr)
    {
        return;
    }

    RBTreeNode* fixNode;
    RBColor fixFactor = removeNode->Color;

    if (removeNode->Left == _nil)
    {
        fixNode = removeNode->Right;
        Swap(removeNode, removeNode->Right);
    }
    else
    {
        if (removeNode->Right == _nil)
        {
            fixNode = removeNode->Left;
            Swap(removeNode, removeNode->Left);
        }
        else
        {
            RBTreeNode* swop = GetMin(removeNode->Right);
            fixFactor = swop->Color;
            fixNode = swop->Left;
            if (removeNode == swop->Parent)
            {
                fixNode->Parent = swop; // Без комментариев (Кормен 357 стр.)
            }
            else
            {
                Swap(swop, swop->Right);
                swop->Right = removeNode->Right;
                swop->Right->Parent = swop;
            }
            Swap(removeNode, swop);
            swop->Left = removeNode->Left;
            swop->Left->Parent = swop;
            swop->Color = removeNode->Color;
        }
    }
    delete removeNode;
    if (fixFactor == Black)
    {
        FixRemoveNode(fixNode);
    }
}

void RBTree::FixRemoveNode(RBTreeNode* node)
{
    while (node != _root && node->Color == Black)
    {
        RBTreeNode* parent = node->Parent;
        if (node == parent->Left)
        {
            RBTreeNode* brother = parent->Right;
            if (brother != _nil && brother->Color == Red)
            {
                brother->Color = Black;
                parent->Color = Red;
                TurnLeft(parent);
                brother = parent->Right;
            }
            if (brother->Left->Color == Black && brother->Right->Color == Black)
            {
                brother->Color = Red;
                node = node->Parent;
            }
            else
            {
                if (brother->Right->Color == Black)
                {
                    brother->Left->Color = Black;
                    brother->Color = Red;
                    TurnRight(brother);
                    brother = parent->Right;
                }
                brother->Color = parent->Color;
                parent->Color = Black;
                brother->Right->Color = Black;
                TurnLeft(parent);
                node = _root;
            }
        }
        else
        {
            RBTreeNode* brother = parent->Left;
            if (brother->Color == Red)
            {
                brother->Color = Black;
                parent->Color = Red;
                TurnRight(parent);
                brother = parent->Left;
            }
            if (brother->Left->Color == Black && brother->Right->Color == Black)
            {
                brother->Color = Red;
                node = node->Parent;
            }
            else
            {
                if (brother->Left->Color == Black)
                {
                    brother->Right->Color = Black;
                    brother->Color = Red;
                    TurnLeft(brother);
                    brother = parent->Left;
                }
                brother->Color = parent->Color;
                parent->Color = Black;
                brother->Left->Color = Black;
                TurnRight(parent);
                node = _root;
            }
        }
    }
    node->Color = Black;
}

RBTreeNode* RBTree::GetMin(RBTreeNode* node)
{
    while (node->Left != _nil)
    {
        node = node->Left;
    }
    return node;
}

RBTreeNode* RBTree::SearchNode(const int &data)
{
    RBTreeNode* bypassNode = _root;
    while (bypassNode != _nil)
    {
        if (data == bypassNode->Data)
        {
            return bypassNode;
        }
        if (data > bypassNode->Data)
        {
            bypassNode = bypassNode->Right;
        }
        else
        {
            bypassNode = bypassNode->Left;
        }
    }
    return nullptr;
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
    if (_root != nullptr)
    {
        queue.Push(_root, depthObserver, _root->Color);
    }
    else
    {
        queue.Push(_root, depthObserver);
    }
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
