#include "iotool.h"



/*!
 * \brief Очистка терминала
 */
void ClearTerminal()
{
    if (system("clear"))
    {
        system("cls");
    }
}
