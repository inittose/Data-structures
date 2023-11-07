#include "queue.h"

void Queue::Enqueue(const int & value)
{
    _stackIn.Push(value);
}

int Queue::Dequeue()
{
    if (_stackOut.IsEmpty())
    {
        if (_stackIn.IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        while (!_stackIn.IsEmpty())
        {
            _stackOut.Push(_stackIn.Pop());
        }
    }
    int result = _stackOut.Pop();
    cout << "Dequeue element: " << result << endl;
    return result;
}

void Queue::ShowStacks()
{
    cout << "Stack in\tStack out\n";
    int maxLenght = _stackIn._lenght > _stackOut._lenght ? _stackIn._lenght : _stackOut._lenght;
    for (int i = maxLenght; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << "`````\t\t`````\n";
            break;
        }
        if (i <= _stackIn._lenght)
        {
            cout << "| " << _stackIn._data[i - 1] << " |\t\t";
        }
        else
        {
            cout << "|   |\t\t";
        }
        if (i <= _stackOut._lenght)
        {
            cout << "| " << _stackOut._data[i - 1] << " |\n";
        }
        else
        {
            cout << "|   |\n";
        }
    }
}

char Queue::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';

    while (true)
    {
        int value;
        ShowStacks();
        cout << menu;
        ValidInput(mode);
        ClearTerminal();
        switch (mode)
        {
        case '.':
            return '.';
        case '1':
            cout << "Enter enqueue element: ";
            ValidInput(value);
            Enqueue(value);
            break;
        case '2':
            Dequeue();
            break;
        case 'q':
            return 'q';
        }
    }
    return mode;
}
