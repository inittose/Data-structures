#include "iotool.h"



/**
 *  Очистка окна вывода
 */
void ClearTerminal()
{
    /*
     *  "cls" - на OS Windows
     *  "clear" - на OS Unix
     */
    system("cls");
}
