#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string.h>
#include <iostream>

void AnalyzeTrees(const int &startPower = 5, const int &measureCount = 3);

void SetMax(int &data, const int &value);

template <typename Tree>
std::pair<std::string, std::string> GetAddingMeasures(Tree &tree, const int &maxNodes, const int &seed = 0);

template <typename Tree>
std::pair<std::string, std::string> GetRemovingMeasures(Tree &tree, const int &maxNodes);

#endif // ANALYSIS_H
