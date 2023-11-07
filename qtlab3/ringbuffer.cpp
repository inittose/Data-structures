#include "RingBuffer.h"

RingBuffer::RingBuffer(const int &size)
{
    _sizeBuffer = size;
    _data = new int*[_sizeBuffer];
    _head = -1;
    _tail = 0;
    for (int i = 0; i < _sizeBuffer; i++)
    {
        _data[i] = nullptr;
    }
}

RingBuffer::~RingBuffer()
{
    for (int i = 0; i < _sizeBuffer; i++)
    {
        if (_data[i])
        {
            delete _data[i];
        }
    }
    delete[] _data;
}

int RingBuffer::GetFreeSpace() const
{
    if (_head == -1)
    {
        return _sizeBuffer;
    }
    return _tail > _head ? _sizeBuffer - _tail + _head : _head - _tail;
}

int RingBuffer::GetOccupiedSpace() const
{
    return _sizeBuffer - GetFreeSpace();
}

void RingBuffer::Push(const int & value)
{
    if (_head == _tail)
    {
        _head++;
        _head %= _sizeBuffer;
    }

    _data[_tail++] = new int(value);
    _tail %= _sizeBuffer;

    if (_head == -1)
    {
        _head = _tail - 1;
    }
}

int RingBuffer::Pop()
{
    int result;
    if (_head == -1)
    {
        cout << "No element in ring buffer" << endl;
        return 0;
    }
    result = *_data[_head];
    delete _data[_head];
    _data[_head++] = nullptr;

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
    os << "Ring Buffer: [ ";
    for (int i = 0; i < ringBuffer._sizeBuffer; i++)
    {
        if (ringBuffer._data[i])
        {
            os << *ringBuffer._data[i] << " ";
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
    const char* menu =
        "Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\n3 - Show free space\n4 - Show occupied space\nq - quit\nYour choice: ";

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
