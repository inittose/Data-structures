#pragma once
#include "ListItem.h"
#include <iostream>

using std::ostream;

struct List
{
private:
	ListItem* _head;
	ListItem* _tail;

	List& Swap(ListItem* fItem, ListItem* sItem);

public:
	List();
	~List();

	List& InsertAtBeginning(const int& value);
	List& InsertAtEnd(const int& value);
	List& InsertAfter(const int& value, const int& leftValue);
	List& InsertBefore(const int& value, const int& rightValue);
	List& DeleteElement(const int& value);
	List& Sort();
	int LinearSearch(const int& value);
	List& Swap(const int& fIndex, const int& sIndex);

	friend ostream& operator<<(ostream& os, const List & list);
};