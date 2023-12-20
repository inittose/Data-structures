#include "analysis.h"
#include "rbtree.h"
#include "avltree.h"
#include <chrono>
#include <cmath>
#include <fstream>
using namespace std;
using std::chrono::steady_clock;

void AnalyzeTrees(const int &startPower, const int &measureCount)
{
    int rows = 4 * (measureCount + 1);
    string tables[rows];
    tables[0] = "Insert [Microseconds]\tRed-black tree (SUM)\tRed-black tree (MAX)\t";
    tables[0] += "AVL-tree (SUM)\tAVL-tree (MAX)";
    tables[(measureCount + 1)] = "\nInsert [Rotations]\t";
    tables[2 * (measureCount + 1)] = "\nRemove [Microseconds]\t";
    tables[3 * (measureCount + 1)] = "\nRemove [Rotations]\t";
    for (int i = 0; i < measureCount; i++)
    {
        RBTree redBlackTree;
        AVLTree avlTree;
        int seed = time(nullptr);
        int maxNodes = pow(10, startPower + i);
        auto rbMeasures = GetAddingMeasures(redBlackTree, maxNodes, seed);
        auto avlMeasures = GetAddingMeasures(avlTree, maxNodes, seed);

        tables[i + 1] += to_string(startPower + i) + '\t' + rbMeasures.first + avlMeasures.first;
        tables[(measureCount + 1) + i + 1] += to_string(startPower + i) +
                                              '\t' + rbMeasures.second + avlMeasures.second;

        rbMeasures = GetRemovingMeasures(redBlackTree, maxNodes);
        avlMeasures = GetRemovingMeasures(avlTree, maxNodes);

        tables[2 * (measureCount + 1) + i + 1] += to_string(startPower + i) +
                                                  '\t' + rbMeasures.first + avlMeasures.first;

        tables[3 * (measureCount + 1) + i + 1] += to_string(startPower + i) +
                                                  '\t' + rbMeasures.second + avlMeasures.second;
    }
    cout << "Done!\n";
    ofstream file;
    file.open("tables.txt");
    for (int i = 0; i < rows; i++)
    {
        cout << tables[i] << endl;
        file << tables[i] << endl;
    }
}

void SetMax(int &data, const int &value)
{
    if (value > data)
    {
        data = value;
    }
}

template <typename Tree>
std::pair<std::string, std::string> GetAddingMeasures(Tree &tree, const int &maxNodes, const int &seed)
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
        int newKey = rand() % 198 - 99;
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
std::pair<std::string, std::string> GetRemovingMeasures(Tree &tree, const int &maxNodes)
{
    steady_clock::time_point begin;
    steady_clock::time_point end;
    long long sumTime = 0;
    long long sumRotation = 0;
    int maxTime = 0;
    int maxRotation = 0;
    for (int j = 0; j < maxNodes; j++)
    {
        int runningTime;

        begin = steady_clock::now();
        tree.RemoveNode(tree.GetRoot());
        end = steady_clock::now();
        runningTime = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
        sumTime += runningTime;
        sumRotation += tree.Rotations;
        SetMax(maxTime, runningTime);
        SetMax(maxRotation, tree.Rotations);
    }
    string first = to_string(sumTime) + '\t' + to_string(maxTime) + '\t';
    string second = to_string(sumRotation) + '\t' + to_string(maxRotation) + '\t';
    return make_pair(first, second);
}
