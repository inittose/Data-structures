#include <iostream>
#include "stack.h"
#include "ringbuffer.h"
#include "queue.h"
#include "iotool.h"
#include "queuering.h"
using std::cin;
using std::cout;
using std::endl;


template<typename Type>
char MainController();

int main()
{
    char mode = '\0';
    char bWrongInput = false;
    const char *MENU_MESSAGE = "\nChoose one of structures: \n1 - Stack \n2 - Ring buffer \n3 - Queue (Ring) \n4 - Queue (Stack) \nq - Quit \nYour choice: ";
    cout << MENU_MESSAGE;
    while(mode != 'q')
    {
        ValidInput(mode, bWrongInput);
        ClearTerminal();
        switch(mode)
        {
        case '1':
            mode = MainController<Stack>();
            break;
        case '2':
            mode = MainController<RingBuffer>();
            break;
        case '3':
            mode = MainController<QueueRing>();
            break;
        case '4':
            mode = MainController<Queue>();
            break;
        default:
            bWrongInput = true;
            break;
        }
        cout << MENU_MESSAGE;
    }
    ClearTerminal();
    return 0;
}

/*!
 * \brief Вызов меню определенного класса
 * \return Возвращает символ при выходе из меню класса
 */
template<typename Type>
char MainController()
{
    Type item;
    return item.Controller();
}
