#include "Stack.h"


Stack::Stack(const int & size)
{
    _sizeBuffer = size;
    _data = new int[_sizeBuffer];
    _lenght = 0;
}

Stack::~Stack()
{
    delete[] _data;
}

void Stack::ResizeStack(bool increase)
{
    _sizeBuffer = increase ? _sizeBuffer * 2 : _sizeBuffer / 2;
    int* newData = new int[_sizeBuffer];

    for (int i = 0; i < _lenght; i++)
    {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

void Stack::Push(const int & value)
{
    if (_lenght == _sizeBuffer)
    {
        ResizeStack(true);
    }
    _data[_lenght] = value;
    _lenght++;
}

int Stack::Pop()
{
    if (!_lenght)
    {
        cout << "No elements in stack!\n";
        return -1;
    }

    int result = _data[_lenght - 1];
    _lenght--;

    if (_lenght <= _sizeBuffer / 2 && _lenght >= 4)
    {
        ResizeStack(false);
    }

    return result;
}

bool Stack::IsEmpty()
{
    return !_lenght;
}

ostream& operator<<(ostream& os, const Stack& stack)
{
    os << "Stack: \t\t" << "Lenght: " << stack._lenght << "\tBuffer size: " << stack._sizeBuffer << endl;

    for (int i = stack._lenght - 1; i >= 0; i--)
    {
        cout << "\t| " << stack._data[i] << " |" << endl;
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
        ClearTerminal();
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
            if (IsEmpty())
            {
                cout << "No elements in stack!\n";
            }
            else
            {
                cout << "Pop element: " << this->Pop() << endl;
            }
            break;
        case 'q':
            return 'q';
        }
        cout << *this;
    }
    return '\0';
}
