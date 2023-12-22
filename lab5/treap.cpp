#include "treap.h"

Treap::Treap()
{
    _root = nullptr;
}

void Treap::DeleteTreap(TreapNode* node)
{
    if (node)
    {
        DeleteTreap(node->Left);
        DeleteTreap(node->Right);
        delete node;
    }
}

Treap::~Treap()
{
    DeleteTreap(_root);
}

int Treap::FindDepth(TreapNode* node, int depth)
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

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
    if (!right)
    {
        return left;
    }
    if (!left)
    {
        return right;
    }
    if (left->Priority > right->Priority)
    {
        left->Right = Merge(left->Right, right);
        return left;
    }
    else
    {
        right->Left = Merge(left, right->Left);
        return right;
    }
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (!node)
    {
        left = right = nullptr;
        return;
    }
    if (node->Key < key)
    {
        Split(node->Right, key, node->Right, right);
        left = node;
    }
    else
    {
        Split(node->Left, key, left, node->Left);
        right = node;
    }
}

TreapNode* Treap::Search(const int &key)
{
    TreapNode* less;
    TreapNode* equal;
    TreapNode* greater;
    Split(_root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    _root = Merge(Merge(less, equal), greater);
    return equal;
}

bool Treap::Add(const int &key)
{
    if (Search(key))
    {
        return false;
    }
    TreapNode* less;
    TreapNode* greater;
    Split(_root, key, less, greater);
    less = Merge(less, new TreapNode(key));
    _root = Merge(less, greater);
    return true;
}

void Treap::LightAdd(TreapNode* node, TreapNode* newNode, TreapNode* parent)
{
    if (node && newNode->Priority < node->Priority)
    {
        if (newNode->Key == node->Key)
        {
            return;
        }
        if (newNode->Key < node->Key)
        {
            LightAdd(node->Left, newNode, node);
        }
        else
        {
            LightAdd(node->Right, newNode, node);
        }
    }
    else
    {
        TreapNode* left;
        TreapNode* right;
        Split(node, newNode->Key, left, right);
        newNode->Left = left;
        newNode->Right = right;
        if (parent)
        {
            if (newNode->Key < parent->Key)
            {
                parent->Left = newNode;
            }
            else
            {
                parent->Right = newNode;
            }
        }
        else
        {
            _root = newNode;
        }
    }
}

void Treap::LightAdd(const int &key)
{
    if (!Search(key))
    {
        LightAdd(_root, new TreapNode(key), nullptr);
    }
}

bool Treap::Remove(const int &key)
{
    TreapNode* less;
    TreapNode* equal;
    TreapNode* greater;
    Split(_root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    _root = Merge(less, greater);
    bool result = equal;
    delete equal;
    return result;
}

bool Treap::LightRemove(TreapNode* node, const int &key, TreapNode* parent)
{
    if (!node)
    {
        return false;
    }
    if (key == node->Key)
    {
        TreapNode* newNode = Merge(node->Left, node->Right);
        if (parent)
        {
            if (node == parent->Left)
            {
                parent->Left = newNode;
            }
            else
            {
                parent->Right = newNode;
            }
        }
        else
        {
            _root = newNode;
        }
        delete node;
        return true;
    }
    if (key < node->Key)
    {
        return LightRemove(node->Left, key, node);
    }
    else
    {
        return LightRemove(node->Right, key, node);
    }
}

bool Treap::LightRemove(const int &key)
{
    return LightRemove(_root, key);
}

//TODO: убрать из СД операциии IO должны быть отдельно от СД

//TODO: убрать из СД операциии IO должны быть отдельно от СД


Queue<TreapNode> Treap::GetLayers()
{
    Queue<TreapNode> queue;
    Queue<TreapNode> queueBypass;
    int treeDepth = FindDepth(_root, 0);
    int depthObserver = 0;
    if (_root != nullptr)
    {
        queue.Push(_root, depthObserver);
    }
    else
    {
        queue.Push(_root, depthObserver);
    }
    queueBypass.Push(_root, depthObserver);
    depthObserver = queueBypass.GetDepth();
    while(depthObserver < treeDepth)
    {
        TreapNode* node = queueBypass.Pop();
        if (node)
        {
            queue.Push(node->Left, depthObserver + 1);
            queue.Push(node->Right, depthObserver + 1);
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
