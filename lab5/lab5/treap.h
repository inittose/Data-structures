#ifndef TREAP_H
#define TREAP_H

#include "treapnode.h"
#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

class Treap
{
private:
    TreapNode* _root;
    int _depth;

    TreapNode* Merge(TreapNode* a, TreapNode* b);
    void Split(TreapNode* node, int key, TreapNode*& a, TreapNode*& b);
    void DeleteTreap(TreapNode* node);

    int Power(const int &number, const int &power);
    int DigitPlace(int number);
    int FindDepth(TreapNode* node, int depth);
    void UpdateDepth();

public:
    Treap();
    ~Treap();
    bool Add(const int & key);
    bool Remove(const int & key);
    bool Search(const int & key);
    void Show();
};

#endif // TREAP_H
