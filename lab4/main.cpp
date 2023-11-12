#include <iostream>
#include <typeinfo>
#include <bitset>
#include <string>
#include "dictionary.h"

using namespace std;

void Menu();
template <typename T>
void ValidInput(T &variable);
string GetTypeName(const char *letter);
void ClearTerminal();


int main()
{
    Menu();

    return 0;
}

void Menu()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Search\n3 - Delete\n4 - Show hash table\nq - Quit\nYour choice: ";
    string key;
    string value;
    Dictionary dictionary;
    char mode = '\0';

    while (mode != 'q')
    {
        dictionary.Show();
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
        case '1':
            cout << "Enter key for adding: ";
            ValidInput(key);
            cout << "Enter value: ";
            ValidInput(value);
            dictionary.Add(key, value);
            break;
        case '2':
            cout << "Enter key for search: ";
            ValidInput(key);
            value = dictionary.Search(key);
            if (value != "")
            {
                cout << "Key \"" << key << "\" contains value \"" << value << "\"\n";
            }
            else
            {
                cout << "No key in dictionary!\n";
            }
            break;
        case '3':
            cout << "Enter key for deletion: ";
            ValidInput(key);
            if (dictionary.Delete(key))
            {
                cout << "Deletion successful!\n";
            }
            else
            {
                cout << "No key in dictionary!\n";
            }
            break;
        case '4':
            dictionary.ShowHashTable();
            break;
        default:
            break;
        }
    }
}

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
    default:
        return "UNKNOWN_TYPE";
    }
}

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

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}
