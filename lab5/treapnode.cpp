#include "treapnode.h"

/*!
 * \brief Конструктор узла декартова дерева
 * \param key Ключ узла
 */
TreapNode::TreapNode(const int & key)
{
    Key = key;
    std::srand(std::time(nullptr));
    Priority = std::rand() % MAX_PRIORITY;
}
