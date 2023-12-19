#include <iostream>
#include <string.h>
#include "rbtree.h"
#include "avltree.h"

using namespace std;

void ControllerRBTree();
void ControllerAVLTree();
void MainController();
template <typename T>
void ValidInput(T &variable);
template <typename T>
void ShowTree(Queue<T> queue);
string GetTypeName(const char *letter);
string GetTreeName(const string &name);
void ClearTerminal();
int Power(const int &number, const int &power);
int DigitPlace(int number);


int main()
{
    //RBTree redBlackTree;
    //AVLTree avlTree;
    //cout << "Red-black Tree: " << typeid(redBlackTree).name() << "\nAVL Tree: " << typeid(avlTree).name() << endl;
    MainController();

    return 0;
}

/*!
 * \brief Главное меню и выбор структур данных для работы
 */
void MainController()
{
    string menu = "Choose one of structure:\n1 - Red-black tree\n2 - AVL tree\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            ControllerRBTree();
            break;
        case '2':
            ControllerAVLTree();
            break;
        default:
            break;
        }
    }
}

/*!
 * \brief Меню и управление красно-черным деревом
 */
void ControllerRBTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Show details of node\nq - Exit to main menu\nYour choice: ";
    int data;
    RBTree redBlackTree;
    char mode = '\0';

    while (mode != 'q')
    {
        ShowTree(redBlackTree.GetLayers());
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(data);
            redBlackTree.AddNode(data);
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            redBlackTree.RemoveNode(data);
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(data);
            if (redBlackTree.SearchNode(data) != nullptr)
            {
                cout << "Value " << data << " is contained in red-black tree!\n";
            }
            else
            {
                cout << "No value " << data << " in red-black tree!\n";
            }
            break;
        case '4':
            cout << "Enter value for search: ";
            ValidInput(data);
            if (redBlackTree.SearchNode(data) != nullptr)
            {
                RBTreeNode* node = redBlackTree.SearchNode(data);
                cout << "Parent: Ptr: " << node->Parent << "  Data: " << node->Parent->Data << "  Color: " << node->Parent->Color << endl;
                cout << "Ptr: " << node << "  Data: " << node->Data << "  Color: " << node->Color << endl;
                cout << "Left: Ptr: " << node->Left << "  Data: " << node->Left->Data << "  Color: " << node->Left->Color << endl;
                cout << "Right: Ptr: " << node->Right << "  Data: " << node->Right->Data << "  Color: " << node->Right->Color << endl;
            }
            else
            {
                cout << "No value " << data << " in red-black tree!\n";
            }
        default:
            break;
        }
    }
}

/*!
 * \brief Меню и управление АВЛ-деревом
 */
void ControllerAVLTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\nq - Exit to main menu\nYour choice: ";
    int value;
    AVLTree avlTree;
    char mode = '\0';

    while (mode != 'q')
    {
        ShowTree(avlTree.GetLayers());
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(value);
            avlTree.AddNode(value);
            break;
        case '2':
            cout << "Enter value for adding: ";
            ValidInput(value);
            avlTree.RemoveNode(value);
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(value);
            if (avlTree.SearchNode(value) != nullptr)
            {
                cout << "Value " << value << " is contained in AVL-tree!\n";
            }
            else
            {
                cout << "No value " << value << " in AVL-tree!\n";
            }
            break;
        default:
            break;
        }
    }
}

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char *letter)
{
    switch (*letter) {
    case 'c':
        return "char";
    case 'i':
        return "integer";
    case 'f':
        return "float";
    case 'd':
        return "double";
    case 'N':
        return "string";
    default:
        return string("UNKNOWN_TYPE (") + letter + string(")");
    }
}

/*!
 * \brief Возведение в степень
 * \param number Число
 * \param power Степень
 * \return Число возведенное в степень
 */
int Power(const int &number, const int &power)
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
int DigitPlace(int number)
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

string GetTreeName(const string &name)
{
    string treeName;
    //cout << name << endl;
    switch(name[3])
    {
    case 'R':
        treeName = "Red-black tree";
        break;
    case 'A':
        treeName = "AVL-tree";
        break;
    default:
        treeName = "Unknown tree";
        break;
    }
    return treeName;
}

template <typename T>
void ShowTree(Queue<T> queue)
{
    // ESC codes
    string brightRedColor = "\033[91m";
    string reset = "\033[0m";

    int treeDepth = queue.GetMaxDepth();
    int depthObserver = queue.GetDepth();
    char color = queue.GetColor();
    int depth = queue.GetDepth();
    T* temp = queue.Pop();
    string treeName = GetTreeName(typeid(temp).name());

    if (temp == nullptr || color == 2)
    {
        cout << treeName << " is empty!" << endl;
        return;
    }
    cout << treeName << ":\n";
    while (!queue.IsEmpty())
    {
        if (depthObserver != depth)
        {
            depthObserver = depth;
            cout << endl << endl;
        }
        int spaceCounter = Power(2, treeDepth - depth + 1);
        int backspaceCounter = 0;
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << " ";
        }
        if (temp)
        {
            if (color == 1)
            {
                cout << brightRedColor;
            }
            if (temp->Data < 0)
            {
                cout << '\b';
            }
            cout << temp->Data << reset;
            backspaceCounter = DigitPlace(temp->Data);
        }
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
        color = queue.GetColor();
        depth = queue.GetDepth();
        temp = queue.Pop();
    }
    cout << "\nDepth of " << treeName << ": ";
    if (treeName[0] == 'R')
    {
        cout << treeDepth - 1 << endl;
    }
    else
    {
        cout << treeDepth << endl;
    }
}

/*!
 * \brief Ввод с проверкой
 * \param variable Переменная любого типа данных
 */
template <typename T>
void ValidInput(T &variable)
{
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while(cin.get() != '\n');
        cout << "Enter correct " << GetTypeName(typeid(variable).name()) << " value: ";
        cin >> variable;
    }
}

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}
