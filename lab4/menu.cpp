#include "menu.h"

void MenuController()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Search\
        \n3 - Delete\n4 - Show hash table\nq - Quit\nYour choice: ";

    Dictionary* dictionary = new Dictionary;
    char mode = '\0';

    string enterMessage = "Enter key for ";
    string failMessage = "No key in dictionary!\n";

    while (mode != 'q')
    {
        ShowDictionary(dictionary);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        string key;
        string value;
        switch (mode)
        {
            case '1':
                cout << enterMessage << "adding: ";
                key = ValidInput<string>();
                cout << "Enter value: ";
                value = ValidInput<string>();
                dictionary->Add(key, value);
                break;
            case '2':
                cout << enterMessage << "search: ";
                key = ValidInput<string>();
                value = dictionary->Search(key);
                if (value != "")
                {
                    cout << "Key \"" << key << "\" contains value \"" << value << "\"\n";
                }
                else
                {
                    cout << failMessage;
                }
                break;
            case '3':
                cout << enterMessage << "deletion: ";
                key = ValidInput<string>();
                if (dictionary->Delete(key))
                {
                    cout << "Deletion successful!\n";
                }
                else
                {
                    cout << failMessage;
                }
                break;
            case '4':
                ShowHashTable(dictionary);
                break;
            default:
                break;
        }
    }
    delete dictionary;
}

void ShowHashTable(Dictionary* dictionary)
{
    const HashTable* hashTable = dictionary->GetHashTable();
    int length = hashTable->GetLenght();
    int capacity = hashTable->GetCapacity();
    HashTableItem** data = hashTable->GetData();
    const int* pearsonTable = hashTable->GetPearsonTable();
    cout << "Pearson table: ";
    for (int i = 0; i < capacity; i++)
    {
        cout << pearsonTable[i] << " ";
    }
    cout << endl;
    cout << "Lenght = " << length << "  Capacity = " << capacity << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << "ID " << i << ": " << endl;
        if (data[i])
        {
            HashTableItem *temp = data[i];
            while (temp)
            {
                cout << "\t" << temp->Key << " : " << temp->Value << endl;
                temp = temp->Next;
            }
        }
        else
        {
            cout << "\t***\n";
        }
    }
}

void ShowDictionary(Dictionary* dictionary)
{
    const HashTable* hashTable = dictionary->GetHashTable();
    int length = hashTable->GetLenght();
    if (length == 0)
    {
        cout << "Dictionary is empty\n";
        return;
    }

    HashTableItem **data = hashTable->GetData();
    int capacity = hashTable->GetCapacity();
    int counter = 0;

    cout << "Dictionary:\t{ ";
    for (int i = 0; i < capacity; i++)
    {
        HashTableItem *temp = data[i];
        string keyStorage = "";
        while (temp)
        {
            if (keyStorage != temp->Key)
            {
                keyStorage = temp->Key;
                counter++;
                if (counter % 3 == 0)
                {
                    cout << "\n->\t\t  ";
                }
                cout << "\"" << temp->Key << "\" : \"" << temp->Value << "\", ";
                temp = temp->Next;
            }
        }
    }
    cout << "\b\b }\n";
}

string GetTypeName(const char *letter)
{
    switch (*letter)
    {
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

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while(cin.get() != '\n');
        cout << "Enter correct " << GetTypeName(typeid(variable).name()) << " value: ";
        cin >> variable;
    }
    return variable;
}

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}
