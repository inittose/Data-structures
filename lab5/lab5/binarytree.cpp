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
    Queue queue;
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

void BinaryTree::Add(BinaryTreeNode* node, const int& data, int depth)
{
    if (!node)
    {
        _root = new BinaryTreeNode(data, depth);
        _depth = 1;
        return;
    }
    depth++;
    if (depth > _depth)
    {
        _depth = depth;
    }
    if (data < node->Data)
    {
        if (node->Left)
        {
            Add(node->Left, data, depth);
        }
        else
        {
            node->Left = new BinaryTreeNode(data, depth, node);
        }
    }
    else
    {
        if (node->Right)
        {
            Add(node->Right, data, depth);
        }
        else
        {
            node->Right = new BinaryTreeNode(data, depth, node);
        }
    }
}

void BinaryTree::Add(const int & data)
{
    Add(_root, data, 1);
}

void BinaryTree::Show()
{
    if (!_root)
    {
        return;
    }
    Queue queue;
    queue.Push(_root, _root->Depth);
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

            if (temp->Left)
            {
                queue.Push(temp->Left, temp->Depth + 1);
            }
            else
            {
                queue.Push(nullptr, temp->Depth + 1);
            }
            if (temp->Right)
            {
                queue.Push(temp->Right, temp->Depth + 1);
            }
            else
            {
                queue.Push(nullptr, temp->Depth + 1);
            }
        }
        else
        {
            if (depthObserver < _depth)
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
