#include <iostream>
#include <bitset>
#include "hashtable.h"

using namespace std;

void XORPreview();

int main()
{
    HashTable hashtable;
    hashtable.Add("question", "yes");
    hashtable.Add("question", "no");
    hashtable.Show();
    return 0;
}

/*!
 * \brief Показывает работу бинарного оператора исключающего ИЛИ
 */
void XORPreview()
{
    unsigned char a;
    unsigned char b;
    cout << "Enter a = ";
    cin >> a;
    cout << "Enter b = ";
    cin >> b;
    cout << "a = " << int(a) << "\t\tin bits: " << bitset<8>(a)
         << "\nb = " << int(b) << "\t\tin bits: " << bitset<8>(b)
         << "\na XOR b = " << (a ^ b) << "\tin bits: " << bitset<8>(a ^ b) << endl;
    a = (a^b);
    b = (a^b);
    a = (a^b);
    cout << "Swap a and b: \na = " << a << "\nb = " << b << endl;
}
