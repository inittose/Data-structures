#include "ListItem.h"

/// <summary>
/// Конструктор элемента списка
/// </summary>
ListItem::ListItem()
{
	_data = 0;
	_next = nullptr;
	_prev = nullptr;
}

/// <summary>
/// Конструктор элемента списка
/// </summary>
ListItem::ListItem(const int& data)
{
	_data = data;
	_next = nullptr;
	_prev = nullptr;
}

/// <summary>
/// Конструктор элемента списка
/// </summary>
ListItem::ListItem(const int& data, ListItem* next, ListItem* prev)
{
	_data = data;
	_next = next;
	_prev = prev;
}

/// <summary>
/// Установка следующего элемента
/// </summary>
/// <param name="next"> - следующий элемент</param>
/// <returns>Этот же элемент</returns>
ListItem* ListItem::SetNext(ListItem* next)
{
	_next = next;
	return this;
}

/// <summary>
/// Установка предыдущего элемента
/// </summary>
/// <param name="next"> - предыдущий элемент</param>
/// <returns>Этот же элемент</returns>
ListItem* ListItem::SetPrev(ListItem* prev)
{
	_prev = prev;
	return this;
}