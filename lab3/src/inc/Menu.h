#pragma once
#include "Stack.h"

char MenuMessage(const char * message);
void ModeControl(Stack& list, const char& mode);
template <typename T>
void ValidInput(T& variable);
void ClearConsole();
