#include "menu.h"

void MainController()
{
    string menu = "Choose one of structure:\n1 - Binary tree\n2 - Treap\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        //TODO: RSDN
        //UPD: Добавил табуляцию
        switch (mode)
        {
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

void ControllerBinaryTree()
{
    //TODO: RSDN
    //UPD: Перенес половину строки на следующую
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\
        \n4 - Search min value\n5 - Search max value\nq - Exit to main menu\nYour choice: ";
    //TODO: переменная должна объявляться как можно ближе к инициализации RSDN
    //UPD: переменную data поместил в switch

    //TODO: выделение памяти через new
    //UPD: Выделил
    BinaryTree* binaryTree = new BinaryTree;
    char mode = '\0';

    //UPD: Создал строки, чтобы не повторяться (DRY)
    string enterMessage = "Enter value for ";
    string treeName = "binary tree";
    string failMessage = "No this node in " + treeName + "!\n";

    while (mode != 'q')
    {
        ShowBinaryTree(binaryTree);
        cout << menu;

        mode = ValidInput<char>();
        ClearTerminal();
        switch (mode)
        {
            int data;
            case '1':
                cout << enterMessage << "adding: ";
                data = ValidInput<int>();
                binaryTree->Add(data);
                break;
            case '2':
                cout << enterMessage << "deletion: ";
                data = ValidInput<int>();
                if (binaryTree->Remove(data))
                {
                    cout << "Deletion successful!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            case '3':
                cout << enterMessage << "search: ";
                data = ValidInput<int>();
                if (binaryTree->Search(data))
                {
                    cout << "Value " << data << " is contained in " << treeName <<"!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            case '4':
                if (binaryTree->SearchMin())
                {
                    cout << "Value " << binaryTree->SearchMin()->Data <<
                        " is minimum in " << treeName <<"!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            case '5':
                if (binaryTree->SearchMax())
                {
                    cout << "Value " << binaryTree->SearchMax()->Data <<
                        " is maximum in " << treeName << "!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            default:
                break;
        }
    }
    delete binaryTree;
}

void ControllerTreap()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Light add\n3 - Remove\
        \n4 - Light remove\n5 - Search\nq - Exit to main menu\nYour choice: ";

    Treap* treap = new Treap;
    char mode = '\0';
    //UPD: Создал строки, чтобы не повторяться (DRY)
    string enterMessage = "Enter value for ";
    string treeName = "treap";
    string failMessage = "No this node in " + treeName + "!\n";

    while (mode != 'q')
    {
        ShowTreap(treap);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        switch (mode)
        {
            int key;
            case '1':
                cout << enterMessage << "adding: ";
                key = ValidInput<int>();
                treap->Add(key);
                break;
            case '2':
                cout << enterMessage << "adding: ";
                key = ValidInput<int>();
                treap->LightAdd(key);
                break;
            case '3':
                cout << enterMessage << "deletion: ";
                key = ValidInput<int>();
                if (treap->Remove(key))
                {
                    cout << "Deletion successful!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            case '4':
                cout << enterMessage << "deletion: ";
                key = ValidInput<int>();
                if (treap->LightRemove(key))
                {
                    cout << "Deletion successful!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            case '5':
                cout << enterMessage << "search: ";
                key = ValidInput<int>();
                if (treap->Search(key))
                {
                    cout << "Value " << key << " is contained in treap!\n";
                }
                //TODO: DRY - don't repeat yourself
                else
                {
                    cout << failMessage;
                }
                break;
            default:
                break;
        }
    }
    delete treap;
}

string GetTypeName(const char* letter)
{
    //TODO: RSDN
    //UPD: Добавил табуляцию
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

int Power(const int &number, const int &power)
{
    int result = 1;
    for(int i = 0; i < power; i++)
    {
            result *= number;
    }
    return result;
}

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

void ShowBinaryTree(BinaryTree* tree)
{
    Queue<BinaryTreeNode> queue = tree->GetLayers();
    int treeDepth = queue.GetMaxDepth();
    int depthObserver = queue.GetDepth();
    int depth = queue.GetDepth();
    BinaryTreeNode* temp = queue.Pop();
    string treeName = "Binary tree";

    if (temp == nullptr)
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
            cout << "  ";
        }
        if (temp)
        {
            if (temp->Data < 0)
            {
                cout << '\b';
            }
            cout << temp->Data;
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

void ShowTreap(Treap* tree)
{
    Queue<TreapNode> queue = tree->GetLayers();
    int treeDepth = queue.GetMaxDepth();
    int depthObserver = queue.GetDepth();
    int depth = queue.GetDepth();
    TreapNode* temp = queue.Pop();
    string treeName = "Binary tree";

    if (temp == nullptr)
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
            cout << "  ";
        }
        if (temp)
        {
            if (temp->Key < 0)
            {
                cout << '\b';
            }
            cout << "(" << temp->Key << ", " << temp->Priority << ")";
            backspaceCounter = DigitPlace(temp->Key);
        }
        for (int i = 0; i < spaceCounter; i++)
        {
            cout << "  ";
        }
        for (int i = 0; i < backspaceCounter; i++)
        {
            cout << '\b';
        }
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

//TODO: я бы переделал валидацию слева от метода - переменная = метод валидации, который внутри уже всё проверяет
//UPD: Переделал, теперь создается отдельная переменная
template <typename T>
T ValidInput()
{
    T variable;
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
