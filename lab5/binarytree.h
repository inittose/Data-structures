//TODO: перейти на pragma ones
//UPD: Теперь все headers используют pragma once
#pragma once

#include "queue.h"
#include "binarytreenode.h"
//TODO: убрать из СД операциии IO должны быть отдельно от СД
//UPD: Удалил все методы вывода внутри СД
//UPD2: Создал метод GetLayers, чтобы получить очередь узлов по слоям для вывода

/*!
 * \brief Двоичное дерево поиска
 */
class BinaryTree
{
private:
    /*!
     * \brief Корень дерева
     */
    BinaryTreeNode* _root;

    //TODO: считается некорректно, как максимальная глубина левого или правого пути дерева. 
    //TODO: На самом деле - один из центральных узлов может иметь более длинный путь

    // UPD: Удалил глубину
    // int _depth; DELETED

    /*!
    * \brief Нахождение глубины
    * \param node Узел
    * \param depth Глубина узла
    * \return Глубина дерева
    */
    int FindDepth(BinaryTreeNode* node, int depth);

    /*!
    * \brief Добавить узел в поддерево
    * \param node Узел
    * \param data Значение
    */
    void Add(BinaryTreeNode* node, const int &data);

    /*!
    * \brief Поиск узла дерева по значению
    * \param node Узел поддерева
    * \param data Значение
    * \return Найденный узел
    */
    BinaryTreeNode* Search(BinaryTreeNode* node, const int &data);

    /*!
    * \brief Поиск минимального узла
    * \param node Узел поддерева
    * \return Найденный узел
    */
    BinaryTreeNode* SearchMin(BinaryTreeNode* node);

    /*!
    * \brief Поиск максимального узла
    * \param node Узел поддерева
    * \return Найденный узел
    */
    BinaryTreeNode* SearchMax(BinaryTreeNode* node);

public:
    /*!
    * \brief Конструктор двоичного дерева поиска
    */
    BinaryTree();

    /*!
    * \brief Деструктор двоичного дерева поиска
    */
    ~BinaryTree();

    /*!
    * \brief Добавить узел в дерево
    * \param Значение
    */
    void Add(const int &data);

    /*!
    * \brief Удаление узла из дерева
    * \param data Значение
    * \return Статус удаления
    */
    bool Remove(const int &data);

    /*!
    * \brief Поиск узла дерева по значению
    * \param data Значение
    * \return Найденный узел
    */
    BinaryTreeNode* Search(const int &data);

    /*!
    * \brief Поиск минимального узла
    * \return Найденный узел
    */
    BinaryTreeNode* SearchMin();

    /*!
    * \brief Поиск максимального узла
    * \return Найденный узел
    */
    BinaryTreeNode* SearchMax();

    /*!
    * \brief Обойти дерево в широту
    * \return Очередь узлов по слоям
    */
    Queue<BinaryTreeNode>* GetLayers();
};
