#include <iostream>
#include "inc/Stack.h"
#include "inc/RingBuffer.h"
#include "inc/Menu.h"
using std::cin;
using std::cout;
using std::endl;


template<typename Type>
char MainController();

int main()
{
    char mode = '\0';
    const char *MENU_MESSAGE = "\nChoose one of structures: \n1 - Stack \n2 - Ring buffer \n3 - Queue (Ring) \n4 - Queue \nq - Quit \nYour choice: ";
    cout << MENU_MESSAGE;
    while(mode != 'q')
    {
        cin >> mode;
        system("clear");
        switch(mode)
        {
            case '1':
            mode = MainController<Stack>();
            break;
            case '2':
            mode = MainController<RingBuffer>();
            break;
            case '3':
            break;
            case '4':
            break;
        }
        cout << MENU_MESSAGE;
    }
    cout << endl;
    system("clear");
    return 0;
}

template<typename Type>
char MainController()
{
    Type item;
    return item.Controller();
}