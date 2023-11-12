#include <iostream>
#include <bitset>
#include "hashtable.h"

using namespace std;

int main()
{
    HashTable hashtable;
    hashtable.Add("question", "yes");
    hashtable.Add("question", "no");
    hashtable.Show();
    return 0;
}

