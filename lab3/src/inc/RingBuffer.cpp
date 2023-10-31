#include "RingBuffer.h"

RingBuffer::RingBuffer()
{
    _data = new char[_sizeBuffer];
    _head = -1;
    _tail = 0;
}

RingBuffer::~RingBuffer()
{
    delete[] _data;
}

int RingBuffer::GetFreeSpace()
{
    if (_head == -1)
    {
        return _sizeBuffer;
    }
    return _tail > _head ? _sizeBuffer - _tail + _head : _head - _tail;
}

int RingBuffer::GetOccupiedSpace()
{
    return _sizeBuffer - GetFreeSpace();
}

void RingBuffer::Push(const char & value)
{
    if (_head == _tail)
    {
        _head++;
        _head %= _sizeBuffer;
    }

    _data[_tail++] = value;
    _tail %= _sizeBuffer;

    if (_head == -1)
    {
        _head = _tail - 1;
    }
}

char RingBuffer::Pop()
{
    char result;
    if (_head == -1)
    {
        cout << "No element in ring buffer" << endl;
        return 0;
    }
    result = _data[_head];
    _data[_head++] = '\0';
    _head %= _sizeBuffer;

    if (_head == _tail)
    {
        _head = -1;
    }
    cout << "Pop element: " << result << endl;
    return result;
}

ostream& operator<<(ostream& os, const RingBuffer& ringBuffer)
{
    int head = ringBuffer._head;
    int tail = ringBuffer._tail;
    int size = ringBuffer._sizeBuffer;
    os << "Ring Buffer: [ ";
    for (int i = 0; i < ringBuffer._sizeBuffer; i++)
    {
        /*bool range = i >= head && i < tail && head != -1;
        bool reverseRange = i >= head && i < size || i >= 0 && i < tail;
        if (tail >= head && range || !(tail >= head) && reverseRange)
        {
            os << ringBuffer._data[i] << " ";
        }
        else
        {
            os << "* ";
        }*/
        if (ringBuffer._data[i])
        {
            os << ringBuffer._data[i] << " ";
        }
        else
        {
            os << "* ";
        }
        
    }
    os << "]" << endl;

    return os;
}

char RingBuffer::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\n3 - Show free space\n4 - Show occupied space\nq - quit\nYour choice: ";
    char mode = '\0';

    cout << *this;
    while (true)
    {
        char value;
        cout << menu;
        cin.get(mode);
        while(cin.get() != '\n');
        system("clear");
        switch (mode)
        {
        case '.':
            return '.';
        case '1':
            cout << "Enter push element: ";
            cin.get(value);
            while(cin.get() != '\n');
            this->Push(value);
            break;
        case '2':
            this->Pop();
            break;
        case '3':
            cout << "Free space: " << this->GetFreeSpace() << endl;
            break;
        case '4':
            cout << "Occupied space: " << this->GetOccupiedSpace() << endl;
            break;
        case 'q':
            return 'q';
        }
        cout << *this;
    }
    return '\0';
}