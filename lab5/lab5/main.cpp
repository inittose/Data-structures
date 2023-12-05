#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    BinaryTree binaryTree;
    binaryTree.Add(1);
    binaryTree.Add(3);
    binaryTree.Add(2);
    binaryTree.Add(-4);
    binaryTree.Add(-1);
    binaryTree.Add(-5);
    binaryTree.Add(4);
    binaryTree.Show();
    return 0;
}
