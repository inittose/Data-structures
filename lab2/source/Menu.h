#pragma once
#include "List.h"
#include <windows.h>

char MenuMessage(const List& list);
void ModeControl(List& list, const char& mode);
template <typename T>
void ValidInput(T& variable);
void UpdateList(const List& list);
void ClearMenu();
