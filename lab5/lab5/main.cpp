#include <iostream>
#include <typeinfo>
#include <bitset>
#include <string>
#include "binarytree.h"
#include "treap.h"

using namespace std;

void ControllerBinaryTree();
void ControllerTreap();
template <typename T>
void ValidInput(T &variable);
string GetTypeName(const char *letter);
void ClearTerminal();


int main()
{
    ControllerTreap();

    return 0;
}

/*!
 * \brief Меню и управление бинарным деревом поиска
 */
void ControllerBinaryTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Search max value\n5 - Search min value\n6 - Show details of element\nq - Quit\nYour choice: ";
    int data;
    BinaryTree binaryTree;
    char mode = '\0';

    while (mode != 'q')
    {
        binaryTree.Show();
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(data);
            binaryTree.Add(data);
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            if (binaryTree.Remove(data))
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
            if (binaryTree.Search(data))
            {
                cout << "Value " << data << " is contained in binary tree!\n";
            }
            else
            {
                cout << "No value " << data << " in binary tree!\n";
            }
            break;
        case '4':
            if (binaryTree.SearchMin())
            {
                cout << "Value " << binaryTree.SearchMin()->Data << " is minimum in binary tree!\n";
            }
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        case '5':
            if (binaryTree.SearchMax())
            {
                cout << "Value " << binaryTree.SearchMax()->Data << " is maximum in binary tree!\n";
            }
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        case '6':
            cout << "Enter value for details: ";
            ValidInput(data);
            binaryTree.ShowDetails(data);
            break;
        default:
            break;
        }
    }
}

/*!
 * \brief Меню и управление бинарным деревом поиска
 */
void ControllerTreap()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\nq - Quit\nYour choice: ";
    int data;
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
            ValidInput(data);
            treap.Add(data);
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            if (treap.Remove(data))
            {
                cout << "Deletion successful!\n";
            }
            else
            {
                cout << "No value " << data << " in treap!\n";
            }
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(data);
            if (treap.Search(data))
            {
                cout << "Value " << data << " is contained in treap!\n";
            }
            else
            {
                cout << "No value " << data << " in treap!\n";
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
