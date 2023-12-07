#include "binarytree.h"

/*!
 * \brief Возведение в степень
 * \param number Число
 * \param power Степень
 * \return Число возведенное в степень
 */
int BinaryTree::Power(const int &number, const int &power)
{
    int result = 1;
    for(int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

/*!
 * \brief Получение количества знаков числа
 * \param number Число
 * \return Количество знаков у числа
 */
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

/*!
 * \brief Конструктор двоичного дерева поиска
 */
BinaryTree::BinaryTree()
{
    _depth = 0;
    _root = nullptr;
}

/*!
 * \brief Деструктор двоичного дерева поиска
 */
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

/*!
 * \brief Нахождение глубины
 * \param node Узел
 * \param depth Глубина узла
 * \return Глубина дерева
 */
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

/*!
 * \brief Установить корректное значение глубины дерева
 */
void BinaryTree::UpdateDepth()
{
    _depth = FindDepth(_root, 0);
}

/*!
 * \brief Добавить узел в поддерево
 * \param node Узел
 * \param data Значение
 */
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

/*!
 * \brief Добавить узел в дерево
 * \param Значение
 */
void BinaryTree::Add(const int & data)
{
    Add(_root, data);
}

/*!
 * \brief Удаление узла из дерева
 * \param data Значение
 * \return Статус удаления
 */
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

/*!
 * \brief Поиск узла дерева по значению
 * \param node Узел поддерева
 * \param data Значение
 * \return Найденный узел
 */
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

/*!
 * \brief Поиск узла дерева по значению
 * \param data Значение
 * \return Найденный узел
 */
BinaryTreeNode* BinaryTree::Search(const int & data)
{
    return Search(_root, data);
}

/*!
 * \brief Вывод дерева
 */
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
    cout << "\nDepth = " << _depth << endl;
}

/*!
 * \brief Вывод деталей конкретного узла
 * \param data Значение узла
 */
void BinaryTree::ShowDetails(const int & data)
{
    BinaryTreeNode* node = Search(data);
    if (!node)
    {
        cout << "There are no element with value " << data << "!\n";
        return;
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

/*!
 * \brief Поиск минимального узла
 * \param node Узел поддерева
 * \return Найденный узел
 */
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

/*!
 * \brief Поиск минимального узла
 * \return Найденный узел
 */
BinaryTreeNode* BinaryTree::SearchMin()
{
    return SearchMin(_root);
}

/*!
 * \brief Поиск максимального узла
 * \param node Узел поддерева
 * \return Найденный узел
 */
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

/*!
 * \brief Поиск максимального узла
 * \return Найденный узел
 */
BinaryTreeNode* BinaryTree::SearchMax()
{
    return SearchMax(_root);
}
