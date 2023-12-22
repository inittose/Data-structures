//TODO: перейти на pragma ones
#ifndef TREAP_H
#define TREAP_H

#include "treapnode.h"
#include "queue.h"
//TODO: убрать из СД операциии IO должны быть отдельно от СД
#include <iostream>
using std::cout;
using std::endl;

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

    /*!
     * \brief Глубина дерамиды
     */
    int _depth;

    //TODO: RSDN naming - названия a и b не очень хорошо отражают назначение аргументов
    TreapNode* Merge(TreapNode* a, TreapNode* b);
    void Split(TreapNode* node, int key, TreapNode*& a, TreapNode*& b);
    void DeleteTreap(TreapNode* node);
    void LightAdd(TreapNode* node, TreapNode* newNode, TreapNode* parent = nullptr);
    bool LightRemove(TreapNode* node, const int & key, TreapNode* parent = nullptr);

    int Power(const int &number, const int &power);
    int DigitPlace(int number);
    int FindDepth(TreapNode* node, int depth);
    void UpdateDepth();

public:
    Treap();
    ~Treap();
    bool Add(const int & key);
    void LightAdd(const int & key);
    bool Remove(const int & key);
    bool LightRemove(const int & key);
    TreapNode* Search(const int & key);
    void Show();
    void ShowDetails(const int & data);
};

#endif // TREAP_H
