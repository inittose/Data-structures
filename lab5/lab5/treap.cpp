#include "treap.h"

/*!
 * \brief Конструктор дерамиды (декартово дерево)
 */
Treap::Treap()
{
    _depth = 0;
    _root = nullptr;
}

/*!
 * \brief Удаление поддерева
 * \param node Узел поддерева
 */
void Treap::DeleteTreap(TreapNode* node)
{
    if (node)
    {
        DeleteTreap(node->Left);
        DeleteTreap(node->Right);
        delete node;
    }
}

/*!
 * \brief Деструктор дерамиды (декартово дерево)
 */
Treap::~Treap()
{
    DeleteTreap(_root);
}

/*!
 * \brief Возведение в степень
 * \param number Число
 * \param power Степень
 * \return Число возведенное в степень
 */
int Treap::Power(const int &number, const int &power)
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

/*!
 * \brief Нахождение глубины
 * \param node Узел
 * \param depth Глубина узла
 * \return Глубина дерева
 */
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

/*!
 * \brief Установить корректное значение глубины дерева
 */
void Treap::UpdateDepth()
{
    _depth = FindDepth(_root, 0);
}

/*!
 * \brief Слияние двух дерамид (где все ключи левой дерамиды меньше, чем у правой)
 * \param left Левая дерамида
 * \param right Правая дерамида
 * \return Одно дерево
 */
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

/*!
 * \brief Разделить дерамиду по ключу
 * \param node Узел поддерева
 * \param key Ключ
 * \param left Полученная левая дерамида
 * \param right Полученная правая дерамида
 */
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

/*!
 * \brief Поиск узла по ключу
 * \param key Ключ
 * \return Найденный узел
 */
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

/*!
 * \brief Добавление узла
 * \param key Ключ
 * \return Статус добавления
 */
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
        UpdateDepth();
    }
}

void Treap::LightAdd(const int & key)
{
    if (!Search(key))
    {
        LightAdd(_root, new TreapNode(key), nullptr);
    }
}

/*!
 * \brief Удаление узла по ключу
 * \param key Ключ
 * \return Статус удаления
 */
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

bool Treap::LightRemove(TreapNode* node, const int & key, TreapNode* parent)
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
        UpdateDepth();
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

bool Treap::LightRemove(const int & key)
{
    return LightRemove(_root, key);
}

/*!
 * \brief Вывод дерамиды
 */
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

/*!
 * \brief Вывод деталей узла дерамиды
 * \param data Ключ
 */
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
