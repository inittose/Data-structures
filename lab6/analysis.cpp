#include "analysis.h"
#include "rbtree.h"
#include "avltree.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;
using std::chrono::steady_clock;

void AnalyzeTrees(const int &startPower, const int &measureCount)
{
    int rows = 4 * (measureCount + 1);
    long long startNodes = pow(10, startPower);
    long long maxNodes = 0;
    int seed = time(nullptr);
    RBTree redBlackTree;
    SetTree(redBlackTree, startNodes, seed);
    AVLTree avlTree;
    SetTree(avlTree, startNodes, seed);
    string* tables = new string[rows];
    tables[0] = "Insert [Microseconds]\tRed-black tree (SUM)\tRed-black tree (MAX)\t";
    tables[0] += "AVL-tree (SUM)\tAVL-tree (MAX)";
    tables[(measureCount + 1)] = "\nInsert [Rotations]\t";
    tables[2 * (measureCount + 1)] = "\nRemove [Microseconds]\t";
    tables[3 * (measureCount + 1)] = "\nRemove [Rotations]\t";
    for (int i = 0; i < measureCount; i++)
    {
        seed += i + 1;
        maxNodes += startNodes / 10;
        auto rbMeasures = GetAddingMeasures(redBlackTree, startNodes / 10, seed);
        auto avlMeasures = GetAddingMeasures(avlTree, startNodes / 10, seed);

        tables[i + 1] += to_string(maxNodes) + '\t' + rbMeasures.first + avlMeasures.first;

        tables[(measureCount + 1) + i + 1] += 
            to_string(maxNodes) + '\t' + 
            rbMeasures.second + avlMeasures.second;
    }
    for (int i = 0; i < measureCount; i++)
    {
        seed -= (i + 1);
        auto rbMeasures = GetRemovingMeasures(redBlackTree, startNodes / 10, seed);
        auto avlMeasures = GetRemovingMeasures(avlTree, startNodes / 10, seed);

        tables[2 * (measureCount + 1) + (measureCount - i)] += 
            to_string(maxNodes) + '\t' + 
            rbMeasures.first + avlMeasures.first;

        tables[3 * (measureCount + 1) + (measureCount - i)] += 
            to_string(maxNodes) + '\t' + 
            rbMeasures.second + avlMeasures.second;

        maxNodes -= startNodes / 10;
    }
    cout << "Done!\n";
    ofstream file;
    file.open("tables.txt");
    file << startNodes << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << tables[i] << endl;
        file << tables[i] << endl;
    }
    delete[] tables;
}

template <typename Type>
string to_string(const Type& value)
{
    stringstream buffer;
    buffer << value;
    return buffer.str();
}

void SetMax(int &max, const int &value)
{
    if (value > max)
    {
        max = value;
    }
}

int GetRandomNumber(const int &min, const int &max)
{
    if (min > max)
    {
        cout << "GET_RANDOM_NUMBER_EXCEPTION" << endl;
        return 0;
    }
    return rand() % (max - min) + min;
}

template <typename Tree>
pair<string, string> GetAddingMeasures(Tree &tree, const long long &maxNodes, const int &seed)
{
    srand(seed);
    steady_clock::time_point begin;
    steady_clock::time_point end;
    long long sumTime = 0;
    long long sumRotation = 0;
    int maxTime = 0;
    int maxRotation = 0;
    for (int j = 0; j < maxNodes; j++)
    {
        int newKey = GetRandomNumber(-999, 999);
        int runningTime;

        begin = steady_clock::now();
        tree.AddNode(newKey);
        end = steady_clock::now();
        runningTime = chrono::duration_cast<chrono::microseconds>(end - begin).count();
        sumTime += runningTime;
        sumRotation += tree.Rotations;
        SetMax(maxTime, runningTime);
        SetMax(maxRotation, tree.Rotations);
    }
    string first = to_string(sumTime) + '\t' + to_string(maxTime) + '\t';
    string second = to_string(sumRotation) + '\t' + to_string(maxRotation) + '\t';
    return make_pair(first, second);
}

template <typename Tree>
pair<string, string> GetRemovingMeasures(Tree &tree, const long long &maxNodes, const int &seed)
{
    srand(seed);
    steady_clock::time_point begin;
    steady_clock::time_point end;
    long long sumTime = 0;
    long long sumRotation = 0;
    int maxTime = 0;
    int maxRotation = 0;
    for (int j = 0; j < maxNodes; j++)
    {
        int deleteKey = GetRandomNumber(-999, 999);
        int runningTime;

        begin = steady_clock::now();
        tree.RemoveNode(deleteKey);
        end = steady_clock::now();
        runningTime = chrono::duration_cast<chrono::microseconds>(end - begin).count();
        sumTime += runningTime;
        sumRotation += tree.Rotations;
        SetMax(maxTime, runningTime);
        SetMax(maxRotation, tree.Rotations);
    }
    string first = to_string(sumTime) + '\t' + to_string(maxTime) + '\t';
    string second = to_string(sumRotation) + '\t' + to_string(maxRotation) + '\t';
    return make_pair(first, second);
}

template <typename Tree>
void SetTree(Tree &tree, const long long &maxNodes, const int &seed)
{
    srand(seed);
    for (int i = 0; i < maxNodes; i++)
    {
        int newKey = GetRandomNumber(-999, 999);
        tree.AddNode(newKey);
    }
}
