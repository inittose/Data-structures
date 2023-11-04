#include "Stack.h"


Stack::Stack()
{
    _top = nullptr;
    _size = 0;
}

Stack::~Stack()
{
    StackItem *run = _top;
    while(run)
    {
        StackItem *temp = run;
        run = run->Prev;
        delete temp;
    }
}

void Stack::Push(const int & data)
{
    StackItem *newItem = new StackItem(data);
    newItem->Prev = _top;
    _top = newItem;
    _size++;
}

int Stack::Pop()
{
    if (!_top)
    {
        cout << "No elements in stack" << endl;
        return -1;
    }
    StackItem *temp = _top;
    int result = temp->Data;
    _top = _top->Prev;
    cout << "Pop element: " << result << endl;
    delete temp;
    _size--;
    return result;
}

bool Stack::IsEmpty()
{
    return !_top;
}

ostream& operator<<(ostream& os, const Stack& stack)
{
    os << "Stack: \t\t" << "Size: " << stack._size << endl;

    StackItem *temp = stack._top;
    for (int i = 0; i < stack._size; i++)
    {
        os << "\t| " << temp->Data << " |" << endl;
        temp = temp->Prev;
    }
    os << "\t`````" << endl;

    return os;
}

char Stack::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\nq - quit\nYour choice: ";
    char mode = '\0';

    cout << *this;
    while (true)
    {
        int value;
        cout << menu;
        ValidInput(mode);
        system("clear");
        switch (mode)
        {
        case '.':
            return '.';
        case '1':
            cout << "Enter push element: ";
            ValidInput(value);
            this->Push(value);
            break;
        case '2':
            this->Pop();
            break;
        case 'q':
            return 'q';
        }
        cout << *this;
    }
    return '\0';
}

template <typename T>
void ValidInput(T& variable)
{
	cin >> variable;
	while (cin.fail())
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Please enter correct value: ";
		cin >> variable;
	}
	while (cin.get() != '\n');
}