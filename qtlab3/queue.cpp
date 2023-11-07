#include "queue.h"

void Queue::Enqueue(const int & value)
{
    S1.Push(value);
}

int Queue::Dequeue()
{
    if (S2.IsEmpty())
    {
        if (S1.IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        while (!S1.IsEmpty())
        {
            S2.Push(S1.Pop());
        }
    }
    int result = S2.Pop();
    cout << "Dequeue element: " << result << endl;
    return result;
}

ostream &operator<<(ostream & os, Queue queue)
{
    os << "S1 = " << queue.S1 << "S2 = " << queue.S2;
    return os;
}

char Queue::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
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
            cout << "Enter Enqueue element: ";
            ValidInput(value);
            this->Enqueue(value);
            break;
        case '2':
            this->Dequeue();
            break;
        case 'q':
            return 'q';
        }
        cout << *this;
    }
    return mode;
}
