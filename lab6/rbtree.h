#pragma once

#include "rbtreenode.h"
#include "queue.h"

/*!
 * \brief Красно-черное дерево
 */
class RBTree
{
public:
    /*!
     * \brief Количество поворотов
     */
    int Rotations;

private:
    /*!
     * \brief Фиктивный лист
     */
    RBTreeNode* _nil;

    /*!
     * \brief Корень дерева
     */
    RBTreeNode* _root;

    /*!
     * \brief Удаление всех узлов
     * \param node Удаляемый узел
     */
    void DeleteTree(RBTreeNode* node);

    /*!
     * \brief Поворот влево
     * \param node Верхний задействованный узел
     * \return Новый верхний узел
     */
    RBTreeNode* TurnLeft(RBTreeNode* node);

    /*!
     * \brief Поворот вправо
     * \param node Верхний задействованный узел
     * \return Новый верхний узел
     */
    RBTreeNode* TurnRight(RBTreeNode* node);

    /*!
     * \brief Найти высоту дерева
     * \param node Узел поддерева
     * \param currentDepth высота поддерева
     * \return Высота дерева
     */
    int GetDepth(RBTreeNode* node, int currentDepth = 0);

    /*!
     * \brief Балансировка после добавления узла
     * \param node Балансируемый узел
     */
    void FixAddNode(RBTreeNode* node);

    /*!
     * \brief Часть балансировки вставки, когда отец находится слева
     * \param node Балансируемый узел
     * \param parent Отец node
     * \param grandparent Дедушка node
     */
    void FixAddLeft(RBTreeNode*& node, RBTreeNode* parent, RBTreeNode* grandparent);

    /*!
     * \brief Часть балансировки вставка, когда отец находится справа
     * \param node Балансируемый узел
     * \param parent Отец node
     * \param grandparent Дедушка node
     */
    void FixAddRight(RBTreeNode*& node, RBTreeNode* parent, RBTreeNode* grandparent);

    /*!
     * \brief Часть балансировки удаления, когда узел находится слева
     * \param node Балансируемый узел
     * \param parent Отец node
     */
    void RBTree::FixRemoveLeft(RBTreeNode*& node, RBTreeNode* parent);

    /*!
     * \brief Часть балансировки удаления, когда узел находится справа
     * \param node Балансируемый узел
     * \param parent Отец node
     */
    void RBTree::FixRemoveRight(RBTreeNode*& node, RBTreeNode* parent);

    /*!
     * \brief Балансировка после удаления узла
     * \param node Балансируемый узел
     */
    void FixRemoveNode(RBTreeNode* node);

    /*!
     * \brief Найти минимальный узел в поддереве
     * \param node Узел поддерева
     * \return Минимальный узел
     */
    RBTreeNode* GetMin(RBTreeNode* node);

    /*!
     * \brief Обмен двух узлов в дереве
     * \param old Узел, который заменят
     * \param swop Узел, на который заменят
     */
    void Swap(RBTreeNode* old, RBTreeNode* swop);

public:
    /*!
     * \brief Конструктор КЧД
     */
    RBTree();

    /*!
     * \brief Деструктор КЧД
     */
    ~RBTree();

    /*!
     * \brief Обойти дерево в широту
     * \return Очередь узлов по слоям
     */
    Queue<RBTreeNode>* GetLayers();

    /*!
     * \brief Добавление узла
     * \param data Данные узла
     */
    void AddNode(const int &data);

    /*!
     * \brief Удаление узла
     * \param data Данные узла
     */
    void RemoveNode(const int &data);

    /*!
     * \brief Поиск узла
     * \param data Данные узла
     * \return Найденный узел
     */
    RBTreeNode* SearchNode(const int &data);
};
