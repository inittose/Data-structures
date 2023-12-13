#include <iostream>

using namespace std;

int main()
{
    char * string = "Some text";
     cout << "\033[30;47m" << string << "\033[0m\n";
    return 0;
}


// \033 - ESC character
// [31m - red color
// [0m - reset
