#include "Stack.h"

/*!
 * \brief Конструктор стека
 * \param size Изначальный размер стека
 */
Stack::Stack(const int & size)
{
    _sizeStack = size;
    _data = new int[_sizeStack];
    _lenght = 0;
}

/*!
 * \brief Деструктор стека
 */
Stack::~Stack()
{
    delete[] _data;
}

/*!
 * \brief Поменять размер стека
 * \param increase Флаг увелечения стека
 */
void Stack::ResizeStack(bool increase)
{
    _sizeStack = increase ? _sizeStack * 2 : _sizeStack / 2;
    int* newData = new int[_sizeStack];

    for (int i = 0; i < _lenght; i++)
    {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

/*!
 * \brief Добавить элемент в стек
 * \param value Значение элемента
 */
void Stack::Push(const int & value)
{
    if (_lenght == _sizeStack)
    {
        ResizeStack(true);
    }
    _data[_lenght] = value;
    _lenght++;
}

/*!
 * \brief Вытолкнуть элемент из стека
 * \return Значение элемента
 */
int Stack::Pop()
{
    if (!_lenght)
    {
        cout << "No elements in stack!\n";
        return -1;
    }

    int result = _data[_lenght - 1];
    _lenght--;

    if (_lenght <= _sizeStack / 2 && _lenght >= 4)
    {
        ResizeStack(false);
    }

    return result;
}

/*!
 * \brief Проверить пустой ли стек
 * \return true - пустой, иначе false
 */
bool Stack::IsEmpty()
{
    return !_lenght;
}

/*!
 * \brief Вывести стек на экран
 * \param os Объект потокового вывода
 * \param stack Объект стека
 * \return Объект потокового вывода
 */
ostream& operator<<(ostream& os, const Stack& stack)
{
    os << "Stack: \t\t" << "Lenght: " << stack._lenght << "\tStack size: " << stack._sizeStack << endl;

    for (int i = stack._lenght - 1; i >= 0; i--)
    {
        cout << "\t| " << stack._data[i] << " |" << endl;
    }

    os << "\t`````" << endl;

    return os;
}

/*!
 * \brief \brief Управляет стеком по средствам меню
 * \return Возвращает символ при выходе из меню
 */
char Stack::Controller()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\nq - quit\nYour choice: ";
    char mode = '\0';
    bool bWrongInput = false;

    cout << *this;
    while (true)
    {
        int value;
        cout << menu;
        ValidInput(mode, bWrongInput);
        bWrongInput = false;
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
        default:
            bWrongInput = true;
            break;
        }
        cout << *this;
    }
    return '\0';
}
