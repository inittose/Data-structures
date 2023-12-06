#include "binarytree.h"

int BinaryTree::Power(const int &number, const int &power)
{
    int result = 1;
    for(int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

int BinaryTree::DigitPlace(int number)
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

BinaryTree::BinaryTree()
{
    _depth = 0;
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

void BinaryTree::UpdateDepth()
{
    _depth = FindDepth(_root, 0);
}

void BinaryTree::Add(BinaryTreeNode* node, const int& data)
{
    if (!node)
    {
        _root = new BinaryTreeNode(data);
        _depth = 1;
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
    UpdateDepth();
}

void BinaryTree::Add(const int & data)
{
    Add(_root, data);
}

bool BinaryTree::Remove(const int & data)
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
    UpdateDepth();
    return true;
}

BinaryTreeNode* BinaryTree::Search(BinaryTreeNode* node, const int & data)
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

BinaryTreeNode* BinaryTree::Search(const int & data)
{
    return Search(_root, data);
}

void BinaryTree::Show()
{
    if (!_root)
    {
        cout << "Binary tree is empty..." << endl;
        return;
    }
    cout << "Binary tree:" << endl;
    Queue<BinaryTreeNode> queue;
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
        BinaryTreeNode* temp = queue.Pop();
        int spaceCounter = Power(2, _depth - depth + 1);
        int backspaceCounter = 0;
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << " ";
        }
        if (temp)
        {
            if (temp->Data < 0)
            {
                cout << '\b';
            }
            cout << temp->Data;
            backspaceCounter = DigitPlace(temp->Data);
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
            cout << " ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
    }
    cout << "\nDepth = " << FindDepth(_root, 0) << endl;
}

void BinaryTree::ShowDetails(const int & data)
{
    BinaryTreeNode* node = Search(data);
    if (!node)
    {
        cout << "There are no element with value " << data << "!\n";
    }
    cout << "_root: " << _root <<"\nValue: " << data << "\tPointer: " << node;
    cout << "\nParent: ";
    if (node->Parent)
    {
        cout << node->Parent << " | " << node->Parent->Data;
    }
    else
    {
        cout << "nullptr";
    }
    cout << "\nLeft: ";
    if (node->Left)
    {
        cout << node->Left << " | " << node->Left->Data;
    }
    else
    {
        cout << "nullptr";
    }
    cout << "\nRight: ";
    if (node->Right)
    {
        cout << node->Right << " | " << node->Right->Data;
    }
    else
    {
        cout << "nullptr";
    }
    cout << endl;
}

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
        return SearchMin(node->Right);
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
