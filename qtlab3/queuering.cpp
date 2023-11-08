#include "queuering.h"

/*!
 * \brief Конструктор очереди
 */
QueueRing::QueueRing()
{
    _sizeBuffer = 4;
    _ringBuffer = new RingBuffer(_sizeBuffer);
}

/*!
 * \brief Деструктор очереди
 */
QueueRing::~QueueRing()
{
    delete _ringBuffer;
}

/*!
 * \brief Поменять размер буфера
 * \param increase Флаг увелечения буфера
 */
void QueueRing::ResizeBuffer(bool increase)
{
    _sizeBuffer = increase ? _sizeBuffer * 2 : _sizeBuffer / 2;
    RingBuffer* newBuffer = new RingBuffer(_sizeBuffer);

    int occupiedSpace = _ringBuffer->GetOccupiedSpace();
    for (int i = 0; i < occupiedSpace; i++)
    {
        newBuffer->Push(_ringBuffer->Pop());
    }
    delete _ringBuffer;
    _ringBuffer = newBuffer;
}

/*!
 * \brief Добавить элемент в очередь
 * \param value Значение элемента
 */
void QueueRing::Enqueue(const int & value)
{
    if (!_ringBuffer->GetFreeSpace())
    {
        ResizeBuffer(true);
    }
    _ringBuffer->Push(value);
}

/*!
 * \brief Снять элемент из очереди
 * \return Значение снятого элемента
 */
int QueueRing::Dequeue()
{
    int result = _ringBuffer->Pop();
    if (_ringBuffer->GetFreeSpace() <= _ringBuffer->_sizeBuffer / 2 && _ringBuffer->GetFreeSpace() >= 4)
    {
        ResizeBuffer(false);
    }
    return result;
}

/*!
 * \brief Вывести на экран очередь
 */
void QueueRing::ShowQueue()
{
    cout << "Queue: in | ";
    for (int i = 0; i < _ringBuffer->GetOccupiedSpace(); i++)
    {
        int temp = (_ringBuffer->_tail - 1 - i + _ringBuffer->_sizeBuffer) % _ringBuffer->_sizeBuffer;
        cout << *_ringBuffer->_data[temp] << " ";
    }
    cout << "| out\nBuffer size: " << _ringBuffer->_sizeBuffer << endl;
}

/*!
 * \brief Управляет очередью по средствам меню
 * \return Возвращает символ при выходе из меню
 */
char QueueRing::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';

    while (true)
    {
        int value;
        ShowQueue();
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
            if (_ringBuffer->GetOccupiedSpace())
            {
                cout << "Dequeue element: " << Dequeue() << endl;
            }
            else
            {
                cout << "No element in queue\n";
            }
            break;
        case 'q':
            return 'q';
        }
    }
    return mode;
}
