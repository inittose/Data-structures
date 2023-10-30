#pragma once

struct ListItem
{
	int _data;
	ListItem* _next;
	ListItem* _prev;

	ListItem();
	ListItem(const int & data);
	ListItem(const int& data, ListItem * next, ListItem* prev);

	ListItem* SetNext(ListItem* next);
	ListItem* SetPrev(ListItem* prev);
};