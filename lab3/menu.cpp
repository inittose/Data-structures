#include "menu.h"

void MainController()
{
    string menu = "Choose one of structure:\n1 - Stack\n2 - Ring buffer \
        \n3 - Queue (Ring) \n4 - Queue (Stack)\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        switch (mode)
        {
            case '1':
                ControllerStack();
                break;
            case '2':
                ControllerRingBuffer();
                break;
            case '3':
                ControllerQueueRing();
                break;
            case '4':
                ControllerStackQueue();
                break;
            default:
                break;
        }
    }
}

void ShowStack(Stack* stack)
{
    cout << "Stack: \t\t" << "Lenght: " << stack->Length 
        << "\tStack size: " << stack->Capacity << endl;

    for (int i = stack->Length - 1; i >= 0; i--)
    {
        cout << "\t| " << stack->Data[i] << " |" << endl;
    }
    cout << "\t`````" << endl;
}

void ShowStackQueue(QueueStack* queue)
{
    cout << "Stack in\tStack out\n";
    const Stack* stackIn = queue->GetStackIn();
    const Stack* stackOut = queue->GetStackOut();
    int maxLenght;
    if (stackIn->Length > stackOut->Length)
    {
        maxLenght = stackIn->Length;
    }
    else
    {
        maxLenght = stackOut->Length;
    }
    for (int i = maxLenght; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << "`````\t\t`````\n";
            break;
        }
        if (i <= stackIn->Length)
        {
            cout << "| " << stackIn->Data[i - 1] << " |\t\t";
        }
        else
        {
            cout << "|   |\t\t";
        }
        if (i <= stackOut->Length)
        {
            cout << "| " << stackOut->Data[i - 1] << " |\n";
        }
        else
        {
            cout << "|   |\n";
        }
    }
}

void ShowRingBuffer(RingBuffer* ringBuffer)
{
    cout << "Ring Buffer: [ ";
    for (int i = 0; i < ringBuffer->Capacity; i++)
    {
        if (ringBuffer->Data[i])
        {
            cout << *ringBuffer->Data[i] << " ";
        }
        else
        {
            cout << "* ";
        }
    }
    cout << "]" << endl;
}

void ShowQueueRing(QueueRing* queueRing)
{
    const RingBuffer* ringBuffer = queueRing->GetRingBuffer();
    cout << "Queue: in | ";
    for (int i = 0; i < ringBuffer->GetOccupiedSpace(); i++)
    {
        int temp = (ringBuffer->Tail - 1 - i + ringBuffer->Capacity) % ringBuffer->Capacity;
        cout << *ringBuffer->Data[temp] << " ";
    }
    cout << "| out\nBuffer size: " << ringBuffer->Capacity << endl;
}

void ControllerQueueRing()
{
    const char* menu = "Choose one of activity:\n1 - Enqueue\
        \n2 - Dequeue\nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    QueueRing* queueRing = new QueueRing;

    while (mode != 'q')
    {
        int value;
        ShowQueueRing(queueRing);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        switch (mode)
        {
            case '1':
                cout << "Enter enqueue element: ";
                value = ValidInput<int>();
                queueRing->Enqueue(value);
                break;
            case '2':
                if (queueRing->GetRingBuffer()->GetOccupiedSpace())
                {
                    cout << "Dequeue element: " << queueRing->Dequeue() << endl;
                }
                else
                {
                    cout << "No element in queue\n";
                }
                break;
            default:
                break;
        }
    }
    delete queueRing;
}

void ControllerRingBuffer()
{
    const char* menu =
        "Choose one of activity:\n1 - Push\n2 - Pop\n3 - Show free space\
        \n4 - Show occupied space\nq - Choose another structure\nYour choice: ";

    char mode = '\0';
    RingBuffer* ringBuffer = new RingBuffer;

    while (mode != 'q')
    {
        ShowRingBuffer(ringBuffer);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        int value;
        switch (mode)
        {
            case '1':
                cout << "Enter push element: ";
                value = ValidInput<int>();
                ringBuffer->Push(value);
                break;
            case '2':
                if (ringBuffer->GetOccupiedSpace())
                {
                    cout << "Pop element: " << ringBuffer->Pop() << endl;
                }
                else
                {
                    cout << "No element in ring buffer\n";
                }
                break;
            case '3':
                cout << "Free space: " << ringBuffer->GetFreeSpace() << endl;
                break;
            case '4':
                cout << "Occupied space: " << ringBuffer->GetOccupiedSpace() << endl;
                break;
            default:
                break;
        }
    }
    delete ringBuffer;
}

void ControllerStackQueue()
{
    const char* menu = "Choose one of activity:\n1 - Enqueue\n2 - Dequeue\
                \nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    QueueStack* queue = new QueueStack;

    while (mode != 'q')
    {
        ShowStackQueue(queue);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        int value;
        switch (mode)
        {
        case '1':
            cout << "Enter enqueue element: ";
            value = ValidInput<int>();
            queue->Enqueue(value);
            break;
        case '2':
            if (queue->GetStackIn()->IsEmpty() && queue->GetStackOut()->IsEmpty())
            {
                cout << "No element in queue\n";
            }
            else
            {
                cout << "Dequeue element: " << queue->Dequeue() << endl;
            }
            break;
        default:
            break;
        }
    }
    delete queue;
}

void ControllerStack()
{
    const char* menu = "Choose one of activity:\n1 - Push\n2 - Pop\
        \nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    Stack* stack = new Stack;

    while (mode != 'q')
    {
        ShowStack(stack);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        int value;
        switch (mode)
        {
            case '1':
                cout << "Enter push element: ";
                value = ValidInput<int>();
                stack->Push(value);
                break;
            case '2':
                if (stack->IsEmpty())
                {
                    cout << "No elements in stack!\n";
                }
                else
                {
                    cout << "Pop element: " << stack->Pop() << endl;
                }
                break;
            default:
                break;
        }
    }
    delete stack;
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

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
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
