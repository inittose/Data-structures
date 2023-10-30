#pragma once
#include "List.h"

char MenuMessage();
void ModeControl(List& list, const char& mode);
template <typename T>
void ValidInput(T& variable);
void ClearMenu();
