#include <iostream>
#include <string.h>
#include "rbtree.h"

using namespace std;

void ControllerRBTree();
void ControllerAVLTree();
void MainController();
template <typename T>
void ValidInput(T &variable);
template <typename T>
void ShowTree(Queue<T> queue);
string GetTypeName(const char *letter);
void ClearTerminal();
int Power(const int &number, const int &power);
int DigitPlace(int number);


int main()
{
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
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Search min value\n5 - Search max value\n6 - Show details of element\nq - Exit to main menu\nYour choice: ";
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
        /*case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            if (redBlackTree.Remove(data))
            {
                cout << "Deletion successful!\n";
            }
            else
            {
                cout << "No value " << data << " in binary tree!\n";
            }
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(data);
            if (redBlackTree.Search(data))
            {
                cout << "Value " << data << " is contained in binary tree!\n";
            }
            else
            {
                cout << "No value " << data << " in binary tree!\n";
            }
            break;
        case '4':
            if (redBlackTree.SearchMin())
            {
                cout << "Value " << binaryTree.SearchMin()->Data << " is minimum in binary tree!\n";
            }
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        case '5':
            if (redBlackTree.SearchMax())
            {
                cout << "Value " << redBlackTree.SearchMax()->Data << " is maximum in binary tree!\n";
            }
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        case '6':
            cout << "Enter value for details: ";
            ValidInput(data);
            redBlackTree.ShowDetails(data);
            break;*/
        default:
            break;
        }
    }
}

/*!
 * \brief Меню и управление дерамидой (Декартово дерево)
 */
void ControllerAVLTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Light add\n3 - Remove\n4 - Light remove\n5 - Search\n6 - Deatails of element\nq - Exit to main menu\nYour choice: ";
    /*int key;
    Treap treap;
    char mode = '\0';

    while (mode != 'q')
    {
        treap.Show();
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(key);
            treap.Add(key);
            break;
        case '2':
            cout << "Enter value for adding: ";
            ValidInput(key);
            treap.LightAdd(key);
            break;
        case '3':
            cout << "Enter value for deletion: ";
            ValidInput(key);
            if (treap.Remove(key))
            {
                cout << "Deletion successful!\n";
            }
            else
            {
                cout << "No value " << key << " in treap!\n";
            }
            break;
        case '4':
            cout << "Enter value for deletion: ";
            ValidInput(key);
            if (treap.LightRemove(key))
            {
                cout << "Deletion successful!\n";
            }
            else
            {
                cout << "No value " << key << " in treap!\n";
            }
            break;
        case '5':
            cout << "Enter value for search: ";
            ValidInput(key);
            if (treap.Search(key))
            {
                cout << "Value " << key << " is contained in treap!\n";
            }
            else
            {
                cout << "No value " << key << " in treap!\n";
            }
            break;
        case '6':
            cout << "Enter value for details: ";
            ValidInput(key);
            treap.ShowDetails(key);
            break;
        default:
            break;
        }
    }*/
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

template <typename T>
void ShowTree(Queue<T> queue)
{
    // ESC codes
    string brightRedColor = "\033[91m";
    string reset = "\033[0m";

    int treeDepth = queue.GetMaxDepth();
    int depthObserver = queue.GetDepth();
    bool redColor = queue.GetColor();
    int depth = queue.GetDepth();
    T* temp = queue.Pop();
    if (temp == nullptr)
    {
        cout << "Red-black tree is empty!" << endl;
        return;
    }
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
            cout << "  ";
        }
        if (temp)
        {
            if (redColor)
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
            cout << "  ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
        redColor = queue.GetColor();
        depth = queue.GetDepth();
        temp = queue.Pop();
    }
    cout << "\nDepth of red-black tree: " << treeDepth - 1 << endl;
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
