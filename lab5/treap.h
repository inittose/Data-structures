//TODO: перейти на pragma ones
//UPD: Теперь все headers используют pragma once
#pragma once

#include "treapnode.h"
#include "queue.h"
//TODO: убрать из СД операциии IO должны быть отдельно от СД
//UPD: Удалил все методы вывода внутри СД
//UPD2: Создал метод GetLayers, чтобы получить очередь узлов по слоям для вывода

/*!
 * \brief Декартово дерево
 */
class Treap
{
private:
    /*!
     * \brief Корень дерамиды
     */
    TreapNode* _root;

    //TODO: RSDN naming - названия a и b не очень хорошо отражают назначение аргументов
    //UPD: Поменял a и b на left и right, чем они и являются

    /*!
    * \brief Слияние двух дерамид (где все ключи левой дерамиды меньше, чем у правой)
    * \param left Левая дерамида
    * \param right Правая дерамида
    * \return Одно дерево
    */
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    /*!
    * \brief Разделить дерамиду по ключу
    * \param node Узел поддерева
    * \param key Ключ
    * \param left Полученная левая дерамида
    * \param right Полученная правая дерамида
    */
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    /*!
    * \brief Удаление поддерева
    * \param node Узел поддерева
    */
    void DeleteTreap(TreapNode* node);

    /*!
    * \brief Оптимизированный метод добавления
    * \param node Узел поддерева
    * \param newNode Новый узел
    * \param parent Предок
    */
    void LightAdd(TreapNode* node, TreapNode* newNode, TreapNode* parent = nullptr);

    /*!
    * \brief Оптимизированный метод удаления узла
    * \param node Узел поддерева
    * \param key Ключ
    * \param parent Предок
    * \return Статус удаления
    */
    bool LightRemove(TreapNode* node, const int &key, TreapNode* parent = nullptr);

    /*!
    * \brief Нахождение глубины
    * \param node Узел
    * \param depth Глубина узла
    * \return Глубина дерева
    */
    int FindDepth(TreapNode* node, int depth);

public:
    /*!
    * \brief Конструктор дерамиды (декартово дерево)
    */
    Treap();

    /*!
    * \brief Деструктор дерамиды (декартово дерево)
    */
    ~Treap();

    /*!
    * \brief Добавление узла
    * \param key Ключ
    * \return Статус добавления
    */
    bool Add(const int &key);

    /*!
    * \brief Оптимизированный метод добавления
    * \param key Ключ
    */
    void LightAdd(const int &key);

    /*!
    * \brief Удаление узла по ключу
    * \param key Ключ
    * \return Статус удаления
    */
    bool Remove(const int &key);

    /*!
    * \brief Оптимизированный метод удаления узла
    * \param key Ключ
    * \return Статус удаления
    */
    bool LightRemove(const int &key);

    /*!
    * \brief Поиск узла по ключу
    * \param key Ключ
    * \return Найденный узел
    */
    TreapNode* Search(const int &key);

    /*!
    * \brief Обойти дерево в широту
    * \return Очередь узлов по слоям
    */
    Queue<TreapNode> GetLayers();
};
