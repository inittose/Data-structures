#include <iostream>
#include <typeinfo>
#include <bitset>
#include <string>
#include "binarytree.h"
#include "treap.h"

using namespace std;

void ControllerBinaryTree();
void ControllerTreap();
void MainController();
template <typename T>
void ValidInput(T &variable);
string GetTypeName(const char *letter);
void ClearTerminal();


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
    string menu = "Choose one of structure:\n1 - Binary tree\n2 - Treap\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            ControllerBinaryTree();
            break;
        case '2':
            ControllerTreap();
            break;
        default:
            break;
        }
    }
}

/*!
 * \brief Меню и управление бинарным деревом поиска
 */
void ControllerBinaryTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Search min value\n5 - Search max value\n6 - Show details of element\nq - Exit to main menu\nYour choice: ";
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
 * \brief Меню и управление дерамидой (Декартово дерево)
 */
void ControllerTreap()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Deatails of element\nq - Exit to main menu\nYour choice: ";
    int key;
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
        case '3':
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
        case '4':
            cout << "Enter value for details: ";
            ValidInput(key);
            treap.ShowDetails(key);
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
