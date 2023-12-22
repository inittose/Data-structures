#include "menu.h"
#include "avltree.h"
#include "rbtree.h"

void MainController()
{
    string menu = "Choose one of structure:\n1 - Red-black tree\
            \n2 - AVL tree\nq - Quit\nYour choice: ";
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

void ControllerRBTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\
            \n4 - Show details of node\nq - Exit to main menu\nYour choice: ";
    
    RBTree* redBlackTree = new RBTree;
    char mode = '\0';

    string enterMessage = "Enter value for ";
    string treeName = "red-black tree";
    string failMessage = "No this node in " + treeName + "!\n";

    while (mode != 'q')
    {
        ShowTree<RBTree, RBTreeNode>(redBlackTree);
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
            int data;
            case '1':
                cout << enterMessage << "adding: ";
                ValidInput(data);
                redBlackTree->AddNode(data);
                cout << "Rotations: " << redBlackTree->Rotations << endl;
                break;
            case '2':
                cout << enterMessage << "deletion: ";
                ValidInput(data);
                redBlackTree->RemoveNode(data);
                cout << "Rotations: " << redBlackTree->Rotations << endl;
                break;
            case '3':
                cout << enterMessage << "search: ";
                ValidInput(data);
                if (redBlackTree->SearchNode(data) != nullptr)
                {
                    cout << "Value " << data << " is contained in red-black tree!\n";
                }
                else
                {
                    cout << failMessage;
                }
                break;
            case '4':
                cout << "Enter value for search: ";
                ValidInput(data);
                if (redBlackTree->SearchNode(data) != nullptr)
                {
                    RBTreeNode* node = redBlackTree->SearchNode(data);
                    cout << "Parent: Ptr: " << node->Parent 
                        << "  Data: " << node->Parent->Data 
                        << "  Color: " << node->Parent->Color 
                        << endl;

                    cout << "Ptr: " << node 
                        << "  Data: " << node->Data 
                        << "  Color: " << node->Color 
                        << endl;

                    cout << "Left: Ptr: " << node->Left 
                        << "  Data: " << node->Left->Data 
                        << "  Color: " << node->Left->Color 
                        << endl;

                    cout << "Right: Ptr: " << node->Right 
                        << "  Data: " << node->Right->Data 
                        << "  Color: " << node->Right->Color 
                        << endl;
                }
                else
                {
                    cout << failMessage;
                }
            default:
                break;
        }
    }
    delete redBlackTree;
}

void ControllerAVLTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\
            \n3 - Search\nq - Exit to main menu\nYour choice: ";
    AVLTree* avlTree = new AVLTree;
    char mode = '\0';
    string enterMessage = "Enter value for ";

    while (mode != 'q')
    {
        ShowTree<AVLTree, AVLTreeNode>(avlTree);
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode) {
            int value;
            case '1':
                cout << enterMessage << "adding: ";
                ValidInput(value);
                avlTree->AddNode(value);
                cout << "Rotations: " << avlTree->Rotations << endl;
                break;
            case '2':
                cout << enterMessage << "deletion: ";
                ValidInput(value);
                avlTree->RemoveNode(value);
                cout << "Rotations: " << avlTree->Rotations << endl;
                break;
            case '3':
                cout << enterMessage << "search: ";
                ValidInput(value);
                if (avlTree->SearchNode(value) != nullptr)
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
    delete avlTree;
}

string GetTypeName(const char* letter)
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

int Power(const int& number, const int& power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

int DigitPlace(int number)
{
    int i = 1;
    number /= 10;
    while (number)
    {
        number /= 10;
        i++;
    }
    return i;
}

string GetTreeName(const type_info& type)
{
    string treeName;
    RBTreeNode* rbTreeNode;
    AVLTreeNode* avlTreeNode;
    if (typeid(rbTreeNode) == type)
    {
        treeName = "Red-black tree";
    }
    else
    {
        if (typeid(avlTreeNode) == type)
        {
            treeName = "AVL-tree";
        }
        else
        {
            treeName = "Unknown tree";
        }
    }
    return treeName;
}

template <typename Tree, typename Node>
void ShowTree(Tree* tree)
{
    // ANSI escape codes
    string brightRedColor = "\033[91m";
    string reset = "\033[0m";

    Queue<Node>* queue = tree->GetLayers();
    int treeDepth = queue->GetMaxDepth();
    int depthObserver = queue->GetDepth();
    char color = queue->GetColor();
    int depth = queue->GetDepth();
    Node* temp = queue->Pop();
    string treeName = GetTreeName(typeid(temp));

    if (temp == nullptr || color == 2)
    {
        cout << treeName << " is empty!" << endl;
        return;
    }
    cout << treeName << ":\n";
    while (!queue->IsEmpty())
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
        color = queue->GetColor();
        depth = queue->GetDepth();
        temp = queue->Pop();
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
    delete queue;
}

template <typename T>
void ValidInput(T& variable)
{
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
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
