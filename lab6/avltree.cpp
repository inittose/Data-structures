#include "avltree.h"

/*!
 * \brief Конструктор АВЛ=дерева
 */
AVLTree::AVLTree()
{
    Rotations = 0;
    _root = nullptr;
}

/*!
 * \brief Деструктор АВЛ-дерева
 */
AVLTree::~AVLTree()
{
    DeleteTree(_root);
}

/*!
 * \brief Рекурсивно удалить поддерево
 * \param node Узел поддерева
 */
void AVLTree::DeleteTree(AVLTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    DeleteTree(node->Left);
    DeleteTree(node->Right);
    delete node;
}

/*!
 * \brief Получить высоту узла
 * \param node Узел
 * \return Высота узла
 */
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

/*!
 * \brief Найти разность высот дочерних узлов
 * \param node Родительский узел
 * \return Разность высот
 */
int AVLTree::GetDeltaHeight(AVLTreeNode* node)
{
    return GetHeight(node->Left) - GetHeight(node->Right);
}

/*!
 * \brief Пересчитать высоту узла
 * \param node Узел
 */
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

/*!
 * \brief Поворот налево
 * \param node Верхний задействованный узел
 * \return Новый верхний узел
 */
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

/*!
 * \brief Поворот направо
 * \param node Верхний задействованный узел
 * \return Новый верхний узел
 */
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

/*!
 * \brief Балансировка поддерева
 * \param node Корень поддерева
 * \return Сбалансированное поддерево
 */
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

/*!
 * \brief Добавить узел в поддерево
 * \param node Корень поддерева
 * \param data Данные нового узла
 * \return Сбалансированное поддерево
 */
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

/*!
 * \brief Добавить узел в дерево
 * \param data Данные узла
 */
void AVLTree::AddNode(const int &data)
{
    Rotations = 0;
    _root = AddNode(_root, data);
}

/*!
 * \brief Найти минимальный узел в поддереве
 * \param node Корень поддерева
 * \return Минимальный узел
 */
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

/*!
 * \brief Найти максимальный узел поддерева
 * \param node Корень поддерева
 * \return Максимальный узел
 */
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

/*!
 * \brief Рекурсивно удалить минимальный узел поддерева
 * \param node Корень поддерева
 * \return Сбалансированное поддерево
 */
AVLTreeNode* AVLTree::RemoveMinNode(AVLTreeNode* node)
{
    if (node->Left == nullptr)
    {
        return node->Right;
    }
    node->Left = RemoveMinNode(node->Left);
    return Rebalance(node);
}

/*!
 * \brief Рекурсивно удалить узел поддерева
 * \param node Корень поддерева
 * \param data Данные узла
 * \return Сбалансированное поддерево
 */
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

/*!
 * \brief Удалить узел дерева
 * \param data Данные узла
 */
void AVLTree::RemoveNode(const int &data)
{
    Rotations = 0;
    _root = RemoveNode(_root, data);
}

/*!
 * \brief Найти узел в поддереве
 * \param node Корень поддерева
 * \param data Данные узла
 * \return Найденный узел
 */
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

/*!
 * \brief Найти узел в дереве
 * \param data Данные узла
 * \return Найденный узел
 */
AVLTreeNode* AVLTree::SearchNode(const int &data)
{
    return SearchNode(_root, data);
}

/*!
 * \brief Обойти дерево в широту
 * \return Очередь узлов по слоям
 */
Queue<AVLTreeNode> AVLTree::GetLayers()
{
    Queue<AVLTreeNode> queue;
    Queue<AVLTreeNode> queueBypass;
    int treeDepth = GetHeight(_root);
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
