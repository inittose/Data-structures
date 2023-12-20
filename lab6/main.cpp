#include <iostream>
#include <string.h>
#include <chrono>
#include <fstream>
#include "rbtree.h"
#include "avltree.h"

using std::chrono::steady_clock;
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
void AnalyzeTrees();


int main()
{
    AnalyzeTrees();
    //MainController();
    return 0;
}

void AnalyzeTrees()
{
    int columns = 5;
    int rows = 12;
    int startPower = 5;
    string tables[rows];
    srand(time(nullptr));
    for (int i = 0; i < columns; i++)
    {
        steady_clock::time_point begin;
        steady_clock::time_point end;
        int maxNodes = Power(10, startPower + i);
        RBTree redBlackTree;
        AVLTree avlTree;
        long long RBAddTime = 0;
        long long RBAddRotation = 0;
        long long RBRemoveTime = 0;
        long long RBRemoveRotation = 0;
        long long AVLAddTime = 0;
        long long AVLAddRotation = 0;
        long long AVLRemoveTime = 0;
        long long AVLRemoveRotation = 0;
        if (i == 0)
        {
            tables[0] = "Insert [Microseconds]\t";
            tables[3] = "\nInsert [Rotations]\t";
            tables[6] = "\nRemove [Microseconds]\t";
            tables[9] = "\nRemove [Rotations]\t";
            tables[1] = tables[4] = tables[7] = tables[10] = "Red-black tree\t";
            tables[2] = tables[5] = tables[8] = tables[11] = "AVL-tree\t";
        }
        tables[0] += to_string(maxNodes) + '\t';
        tables[3] += to_string(maxNodes) + '\t';
        tables[6] += to_string(maxNodes) + '\t';
        tables[9] += to_string(maxNodes) + '\t';
        for (int j = 0; j < maxNodes; j++)
        {
            int newKey = rand() % 198 - 99;

            begin = steady_clock::now();
            redBlackTree.AddNode(newKey);
            end = steady_clock::now();
            RBAddTime += chrono::duration_cast<chrono::microseconds>(end - begin).count();
            RBAddRotation += redBlackTree.Rotations;

            begin = steady_clock::now();
            avlTree.AddNode(newKey);
            end = steady_clock::now();
            AVLAddTime += chrono::duration_cast<chrono::microseconds>(end - begin).count();
            AVLAddRotation += avlTree.Rotations;
        }

        for (int j = 0; j < maxNodes; j++)
        {
            begin = steady_clock::now();
            redBlackTree.RemoveNode(redBlackTree.GetRoot());
            end = steady_clock::now();
            RBRemoveTime += chrono::duration_cast<chrono::milliseconds>(end - begin).count();
            RBRemoveRotation += redBlackTree.Rotations;

            begin = steady_clock::now();
            avlTree.RemoveNode(avlTree.GetRoot());
            end = steady_clock::now();
            AVLRemoveTime += chrono::duration_cast<chrono::milliseconds>(end - begin).count();
            AVLRemoveRotation += avlTree.Rotations;
        }

        tables[1] += to_string(RBAddTime) + '\t';
        tables[4] += to_string(RBAddRotation) + '\t';

        tables[2] += to_string(AVLAddTime) + '\t';
        tables[5] += to_string(AVLAddRotation) + '\t';

        tables[7] += to_string(RBRemoveTime) + '\t';
        tables[10] += to_string(RBRemoveRotation) + '\t';

        tables[8] += to_string(AVLRemoveTime) + '\t';
        tables[11] += to_string(AVLRemoveRotation) + '\t';

        //cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "\n";
    }
    cout << "Done!\n";
    ofstream file;
    file.open("tables.txt");
    for (int i = 0; i < rows; i++)
    {
        cout << tables[i] << endl;
        file << tables[i] << endl;
    }
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
            cout << "Rotations: " << redBlackTree.Rotations << endl;
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            redBlackTree.RemoveNode(data);
            cout << "Rotations: " << redBlackTree.Rotations << endl;
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
            cout << "Rotations: " << avlTree.Rotations << endl;
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(value);
            avlTree.RemoveNode(value);
            cout << "Rotations: " << avlTree.Rotations << endl;
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
