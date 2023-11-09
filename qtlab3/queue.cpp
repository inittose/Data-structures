#include "queue.h"

/*!
 * \brief Поставить элемент в очередь
 * \param value Значение элемента
 */
void Queue::Enqueue(const int & value)
{
    _stackIn.Push(value);
}

/*!
 * \brief Убрать элемент из очереди
 * \return Возвращает значение убранного элемента
 */
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

/*!
 * \brief Вывести 2 стека на экран
 */
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

/*!
 * \brief Управляет очередью по средствам меню
 * \return Возвращает символ при выходе из меню
 */
char Queue::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';
    bool bWrongInput = false;

    while (true)
    {
        int value;
        ShowStacks();
        cout << menu;
        ValidInput(mode, bWrongInput);
        bWrongInput = false;
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
        default:
            bWrongInput = true;
            break;
        }
    }
    return mode;
}
