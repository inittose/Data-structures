#pragma once

#include "avltreenode.h"
#include "queue.h"

/*!
 * \brief АВЛ-дерево
 */
class AVLTree
{
public:
    /*!
     * \brief Количество повороты
     */
    int Rotations;

private:
    /*!
     * \brief Корень дерева
     */
    AVLTreeNode* _root;


    /*!
     * \brief Рекурсивно удалить поддерево
     * \param node Узел поддерева
     */
    void DeleteTree(AVLTreeNode* node);

    /*!
     * \brief Пересчитать высоту узла
     * \param node Узел
     */
    void RebalanceHeight(AVLTreeNode* node);

    /*!
     * \brief Получить высоту узла
     * \param node Узел
     * \return Высота узла
     */
    int GetHeight(AVLTreeNode* node);

    /*!
     * \brief Найти разность высот дочерних узлов
     * \param node Родительский узел
     * \return Разность высот
     */
    int GetDeltaHeight(AVLTreeNode* node);

    /*!
     * \brief Поворот налево
     * \param node Верхний задействованный узел
     * \return Новый верхний узел
     */
    AVLTreeNode* TurnLeft(AVLTreeNode* node);

    /*!
     * \brief Поворот направо
     * \param node Верхний задействованный узел
     * \return Новый верхний узел
     */
    AVLTreeNode* TurnRight(AVLTreeNode* node);

    /*!
     * \brief Балансировка поддерева
     * \param node Корень поддерева
     * \return Сбалансированное поддерево
     */
    AVLTreeNode* Rebalance(AVLTreeNode* node);

    /*!
     * \brief Добавить узел в поддерево
     * \param node Корень поддерева
     * \param data Данные нового узла
     * \return Сбалансированное поддерево
     */
    AVLTreeNode* AddNode(AVLTreeNode* node, const int &data);

    /*!
     * \brief Найти минимальный узел в поддереве
     * \param node Корень поддерева
     * \return Минимальный узел
     */
    AVLTreeNode* GetMin(AVLTreeNode* node);

    /*!
     * \brief Найти максимальный узел поддерева
     * \param node Корень поддерева
     * \return Максимальный узел
     */
    AVLTreeNode* GetMax(AVLTreeNode* node);

    /*!
     * \brief Рекурсивно удалить минимальный узел поддерева
     * \param node Корень поддерева
     * \return Сбалансированное поддерево
     */
    AVLTreeNode* RemoveMinNode(AVLTreeNode* node);

    /*!
     * \brief Рекурсивно удалить узел поддерева
     * \param node Корень поддерева
     * \param data Данные узла
     * \return Сбалансированное поддерево
     */
    AVLTreeNode* RemoveNode(AVLTreeNode* node, const int &data);

    /*!
     * \brief Найти узел в поддереве
     * \param node Корень поддерева
     * \param data Данные узла
     * \return Найденный узел
     */
    AVLTreeNode* SearchNode(AVLTreeNode* node, const int &data);

public:
    /*!
     * \brief Конструктор АВЛ=дерева
     */
    AVLTree();

    /*!
     * \brief Деструктор АВЛ-дерева
     */
    ~AVLTree();

    /*!
     * \brief Добавить узел в дерево
     * \param data Данные узла
     */
    void AddNode(const int &data);

    /*!
     * \brief Удалить узел дерева
     * \param data Данные узла
     */
    void RemoveNode(const int &data);

    /*!
     * \brief Найти узел в дереве
     * \param data Данные узла
     * \return Найденный узел
     */
    AVLTreeNode* SearchNode(const int &data);

    /*!
     * \brief Обойти дерево в широту
     * \return Очередь узлов по слоям
     */
    Queue<AVLTreeNode>* GetLayers();
};
