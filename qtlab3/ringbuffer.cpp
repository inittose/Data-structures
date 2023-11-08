#include "RingBuffer.h"

/*!
 * \brief Конструктор кольцевого буфера
 * \param size Размер буфера
 */
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

/*!
 * \brief Деструктор кольцевого буфера
 */
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

/*!
 * \brief Найти свободное место в буфере
 * \return Количество свободного места
 */
int RingBuffer::GetFreeSpace() const
{
    if (_head == -1)
    {
        return _sizeBuffer;
    }
    return _tail > _head ? _sizeBuffer - _tail + _head : _head - _tail;
}

/*!
 * \brief Найти занятое место в буфере
 * \return Количество занятого места
 */
int RingBuffer::GetOccupiedSpace() const
{
    return _sizeBuffer - GetFreeSpace();
}

/*!
 * \brief Добавить элемент в буфер
 * \param value Значение элемента
 */
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

/*!
 * \brief Вытолкнуть элемент из буфера
 * \return Значение элемента
 */
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
    //cout << "Pop element: " << result << endl;
    return result;
}

/*!
 * \brief Вывести кольцевой буфер
 * \param os Объект потокового вывода
 * \param ringBuffer Кольцевой буфер
 * \return Объект потокового вывода
 */
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

/*!
 * \brief Управляет кольцевым буфером по средствам меню
 * \return Возвращает символ при выходе из меню
 */
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
            if (GetOccupiedSpace())
            {
                cout << "Pop element: " << this->Pop() << endl;
            }
            else
            {
                cout << "No element in ring buffer\n";
            }
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
