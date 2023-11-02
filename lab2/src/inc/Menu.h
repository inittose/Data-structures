#pragma once
#include "List.h"

int MenuMessage();
void ModeControl(List& list, const int & mode);
template <typename T>
void ValidInput(T& variable);
void ClearMenu();
