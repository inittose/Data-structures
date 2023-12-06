#include "treap.h"

Treap::Treap()
{
    _depth = 0;
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

int Treap::Power(const int &number, const int &power)
{
    int result = 1;
    for(int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

int Treap::DigitPlace(int number)
{
    int i = 1;
    number /= 10;
    while(number)
    {
        number /= 10;
        i++;
    }
    return i;
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

void Treap::UpdateDepth()
{
    _depth = FindDepth(_root, 0);
}

// Все ключи из a должны быть меньше ключей из b
TreapNode* Treap::Merge(TreapNode* a, TreapNode* b)
{
    if (!a || !b)
    {
        return a ? a : b;
    }
    if (a->Priority > b->Priority)
    {
        a->Right = Merge(a->Left, b);
        return a;
    }
    else
    {
        b->Left = Merge(a, b->Right);
        return b;
    }
}

void Treap::Split(TreapNode* node, int key, TreapNode*& a, TreapNode*& b)
{
    if (!node)
    {
        a = b = nullptr;
        return;
    }
    if (node->Key < key)
    {
        Split(node->Right, key, node->Right, b);
        a = node;
    }
    else
    {
        Split(node->Left, key, a, node->Left);
        b = node;
    }
}

bool Treap::Search(const int & key)
{
    TreapNode* less;
    TreapNode* equal;
    TreapNode* greater;
    Split(_root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    bool result = equal;
    _root = Merge(Merge(less, equal), greater);
    return result;
}

bool Treap::Add(const int & key)
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
    UpdateDepth();
    return true;
}

bool Treap::Remove(const int & key)
{
    TreapNode* less;
    TreapNode* equal;
    TreapNode* greater;
    Split(_root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    _root = Merge(less, greater);
    bool result = equal;
    delete equal;
    UpdateDepth();
    return result;
}

void Treap::Show()
{
    if (!_root)
    {
        cout << "Treap is empty..." << endl;
        return;
    }
    cout << "Treap is... " << endl;
    /*Queue<TreapNode> queue;
    queue.Push(_root, 1);
    int depthObserver = 1;
    while(!queue.IsEmpty())
    {
        int depth = queue.GetDepth();
        if (depthObserver != depth)
        {
            depthObserver = depth;
            cout << endl;
        }
        TreapNode* temp = queue.Pop();
        int spaceCounter = Power(2, _depth - depth + 1);
        int backspaceCounter = 0;
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << "  ";
        }
        if (temp)
        {
            if (temp->Key < 0)
            {
                cout << '\b';
            }
            cout << temp->Key << "; " << temp->Priority;
            backspaceCounter = DigitPlace(temp->Key);
        }
        if (depthObserver < _depth)
        {
            if (temp)
            {
                queue.Push(temp->Left, depthObserver + 1);
                queue.Push(temp->Right, depthObserver + 1);
            }
            else
            {
                queue.Push(nullptr, depthObserver + 1);
                queue.Push(nullptr, depthObserver + 1);
            }
        }
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << "  ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
    }*/
    cout << "\nDepth = " << FindDepth(_root, 0) << endl;
}
