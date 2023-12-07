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

TreapNode* Treap::Search(const int & key)
{
    TreapNode* less;
    TreapNode* equal;
    TreapNode* greater;
    Split(_root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    _root = Merge(Merge(less, equal), greater);
    return equal;
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
    cout << "Treap:" << endl;
    Queue<TreapNode> queue;
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
            cout << "    ";
        }
        if (temp)
        {
            if (temp->Key < 0)
            {
                cout << '\b';
            }
            cout << "(" << temp->Key << " " << temp->Priority << ")";
            backspaceCounter = 3 + DigitPlace(temp->Key) + DigitPlace(temp->Priority);
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
            cout << "    ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
    }
    cout << "\nDepth = " << _depth << endl;
}

void Treap::ShowDetails(const int & data)
{
    TreapNode* node = Search(data);
    if (!node)
    {
        cout << "There are no element with value " << data << "!\n";
        return;
    }
    cout << "_root: " << _root <<"\nValue: " << data << "\tPointer: " << node;
    cout << "\nLeft: ";
    if (node->Left)
    {
        cout << node->Left << " | " << node->Left->Key << "; " << node->Left->Priority;
    }
    else
    {
        cout << "nullptr";
    }
    cout << "\nRight: ";
    if (node->Right)
    {
        cout << node->Right << " | " << node->Right->Key << "; " << node->Right->Priority;
    }
    else
    {
        cout << "nullptr";
    }
    cout << endl;
}
