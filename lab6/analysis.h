#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string.h>
#include <iostream>

void AnalyzeTrees(const int &startPower = 5, const int &measureCount = 3);

void SetMax(int &max, const int &value);

int GetRandomNumber(const int &min, const int &max);

template <typename Tree>
void SetTree(Tree &tree, const long long &maxNodes, const int &seed = 0);

template <typename Tree>
std::pair<std::string, std::string> GetAddingMeasures(Tree &tree, const long long &maxNodes, const int &seed = 0);

template <typename Tree>
std::pair<std::string, std::string> GetRemovingMeasures(Tree &tree, const long long &maxNodes, const int &seed = 0);

#endif // ANALYSIS_H
